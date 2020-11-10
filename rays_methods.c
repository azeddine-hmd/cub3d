/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:52:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/07 12:58:49 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_render(void)
{
	t_point p0;
	t_point p1;
	int		col;

	p0.x = player()->x * map()->minimap_scale;
	p0.y = player()->y * map()->minimap_scale;
	col = -1;
	while (++col < map()->num_rays)
	{
		p1.x = rays()[col]->wall_hit_x * map()->minimap_scale;
		p1.y = rays()[col]->wall_hit_y * map()->minimap_scale;
		line(p0, p1, rgb(0, 255, 0));
	}
}

void	cast_all_rays(void)
{
	float	ray_angle;
	int		col;

	ray_angle = player()->rotation_angle - (FOV_ANGLE / 2);
	col = -1;
	while (++col < map()->num_rays)
	{
		rays()[col]->ray_angle = normalize_angle(ray_angle);
		set_ray_direction(rays()[col]);
		cast(rays()[col]);
		ray_angle += FOV_ANGLE / map()->num_rays;
	}
}

void	cast(t_ray *ray)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;

	/////////////////////////////////////////////
	//  HORIZONTAL RAY-GRID INTERSECTION CODE  //
	/////////////////////////////////////////////
	float	next_horz_touch_x;
	float	next_horz_touch_y;
	int		found_horz_wall_hit = 0;
	float	horz_wall_hit_x = 0;
	float	horz_wall_hit_y = 0;
	int		horz_wall_content = 0;

	ray->ray_angle = normalize_angle(ray->ray_angle);

	// Find the y-coordinate of the closest horizontal grid intersection
	y_intercept = floor(player()->y / TILE_SIZE) * TILE_SIZE;
	y_intercept += ray->is_ray_facing_down ? TILE_SIZE : 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	x_intercept = player()->x + (y_intercept - player()->y) / tan(ray->ray_angle);

	// Calculate the increment xstep and ystep
	y_step = TILE_SIZE;
	y_step *= ray->is_ray_facing_up ? -1 : 1;

	x_step = TILE_SIZE / tan(ray->ray_angle);
	x_step *= (ray->is_ray_facing_left && x_step > 0) ? -1 : 1;
	x_step *= (ray->is_ray_facing_right && x_step < 0) ? -1 : 1;

	next_horz_touch_x = x_intercept;
	next_horz_touch_y = y_intercept;

	// Increment x_step and y_step until we find a wall
	while (is_inside_map(next_horz_touch_x, next_horz_touch_y))
	{
		float x_to_check = next_horz_touch_x;
		float y_to_check = next_horz_touch_y + (ray->is_ray_facing_up ? -1 : 0);

		if (has_wall_at(x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
			horz_wall_hit_y = next_horz_touch_y;
			found_horz_wall_hit = 1;
			if (is_inside_map(x_to_check, y_to_check))
			{
				int index = (int)(floor((x_to_check / TILE_SIZE)) + floor((y_to_check / TILE_SIZE)) * map()->cols);
				horz_wall_content = map()->maparr[index];
			}
			break ;
		}
		else
		{
			next_horz_touch_x += x_step;
			next_horz_touch_y += y_step;
		}
	}


	/////////////////////////////////////////////
	//    VERTICAL RAY-GRID INTERSECTION CODE  //
	/////////////////////////////////////////////
	int		found_vert_wall_hit = 0;
	float	vert_wall_hit_x = 0;
	float	vert_wall_hit_y = 0;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	int		vert_wall_content = 0;

	// Find the x-coordinate of the closest vertical grid intersection
	x_intercept = floor(player()->x / TILE_SIZE) * TILE_SIZE;
	x_intercept += ray->is_ray_facing_right ? TILE_SIZE : 0;

	// Find the y-coordinate of the closest vertical grid intersection
	y_intercept = player()->y + (x_intercept - player()->x) * tan(ray->ray_angle);

	// Calculate the increment xstep and ystep
	x_step = TILE_SIZE;
	x_step *= ray->is_ray_facing_left ? -1 : 1;

	y_step = TILE_SIZE * tan(ray->ray_angle);
	y_step *= (ray->is_ray_facing_up && y_step > 0) ? -1 : 1;
	y_step *= (ray->is_ray_facing_down && y_step < 0) ? -1 : 1;

	next_vert_touch_x = x_intercept;
	next_vert_touch_y = y_intercept;

	// Increment x_step and y_step until we find a wall
	while (is_inside_map(next_vert_touch_x, next_vert_touch_y))
	{
		float x_to_check = next_vert_touch_x - (ray->is_ray_facing_left ? 1 : 0);
		float y_to_check = next_vert_touch_y;

		if (has_wall_at(x_to_check, y_to_check))
		{
			vert_wall_hit_x = next_vert_touch_x;
			vert_wall_hit_y = next_vert_touch_y;
			found_vert_wall_hit = 1;
			if (is_inside_map(x_to_check, y_to_check))
			{
				int content_index = (int)(floor(x_to_check / TILE_SIZE) + floor(y_to_check / TILE_SIZE) * map()->cols);
				vert_wall_content = map()->maparr[content_index];
			}
			break ;
		}
		else
		{
			next_vert_touch_x += x_step;
			next_vert_touch_y += y_step;
		}
	}

	// Calculate both horizontal and vertical distances and choose the smallest values
	float	horz_hit_distance;
	float	vert_hit_distance;

	horz_hit_distance = (found_horz_wall_hit)
		? distance_between_points(player()->x, player()->y, horz_wall_hit_x, horz_wall_hit_y)
		: INT_MAX;
	vert_hit_distance = (found_vert_wall_hit)
		? distance_between_points(player()->x, player()->y, vert_wall_hit_x, vert_wall_hit_y)
		: INT_MAX;

	// only store the smallest of the distances
	if (vert_hit_distance < horz_hit_distance)
	{
		ray->distance = vert_hit_distance;
		ray->wall_hit_x = vert_wall_hit_x;
		ray->wall_hit_y = vert_wall_hit_y;
		ray->wall_hit_content = vert_wall_content;
		ray->was_hit_vertical = 1;
	}
	else
	{
		ray->distance = horz_hit_distance;
		ray->wall_hit_x = horz_wall_hit_x;
		ray->wall_hit_y = horz_wall_hit_y;
		ray->wall_hit_content = horz_wall_content;
		ray->was_hit_vertical = 0;
	}
}
