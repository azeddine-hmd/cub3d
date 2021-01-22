/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:18:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:22:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_vert_collision(
		t_ray *ray,
		t_vert *vert,
		float x_step,
		float y_step)
{
	float	x_to_check;
	float	y_to_check;
	int		index;

	x_to_check = vert->next_vert_touch_x - (ray->is_ray_facing_left ? 1 : 0);
	y_to_check = vert->next_vert_touch_y;
	if (has_wall_at(x_to_check, y_to_check) ||
			has_hidden_wall_at(x_to_check, y_to_check))
	{
		vert->vert_wall_hit_x = vert->next_vert_touch_x;
		vert->vert_wall_hit_y = vert->next_vert_touch_y;
		vert->found_vert_wall_hit = 1;
		if (is_inside_map(x_to_check, y_to_check))
		{
			index = (int)(floor(x_to_check / TILE_SIZE) +
					floor(y_to_check / TILE_SIZE) * g_game.cols);
			vert->vert_wall_content = g_game.maparr[index];
		}
		return (-1);
	}
	vert->next_vert_touch_x += x_step;
	vert->next_vert_touch_y += y_step;
	return (1);
}

void		vertical_intersection(t_ray *ray, t_vert *vert)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;

	vert->found_vert_wall_hit = 0;
	vert->vert_wall_hit_x = 0;
	vert->vert_wall_hit_y = 0;
	vert->vert_wall_content = 0;
	x_intercept = floor(player()->x / TILE_SIZE) * TILE_SIZE;
	x_intercept += ray->is_ray_facing_right ? TILE_SIZE : 0;
	y_intercept =
		player()->y + (x_intercept - player()->x) * tan(ray->ray_angle);
	x_step = TILE_SIZE;
	x_step *= ray->is_ray_facing_left ? -1 : 1;
	y_step = TILE_SIZE * tan(ray->ray_angle);
	y_step *= (ray->is_ray_facing_up && y_step > 0) ? -1 : 1;
	y_step *= (ray->is_ray_facing_down && y_step < 0) ? -1 : 1;
	vert->next_vert_touch_x = x_intercept;
	vert->next_vert_touch_y = y_intercept;
	while (is_inside_map(vert->next_vert_touch_x, vert->next_vert_touch_y))
		if (check_vert_collision(ray, vert, x_step, y_step) == -1)
			break ;
}
