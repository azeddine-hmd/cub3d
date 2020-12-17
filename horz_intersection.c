/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:16:17 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:05:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_horz_collision(
		t_ray *ray,
		t_horz *horz,
		float x_step,
		float y_step)
{
	float	x_to_check;
	float	y_to_check;
	int		index;

	x_to_check = horz->next_horz_touch_x;
	y_to_check = horz->next_horz_touch_y + (ray->is_ray_facing_up ? -1 : 0);
	if (has_wall_at(x_to_check, y_to_check) ||
			has_hidden_wall_at(x_to_check, y_to_check))
	{
		horz->horz_wall_hit_x = horz->next_horz_touch_x;
		horz->horz_wall_hit_y = horz->next_horz_touch_y;
		horz->found_horz_wall_hit = 1;
		if (is_inside_map(x_to_check, y_to_check))
		{
			index = (int)(floor((x_to_check / TILE_SIZE)) +
					floor((y_to_check / TILE_SIZE)) * game()->cols);
			horz->horz_wall_content = game()->maparr[index];
		}
		return (-1);
	}
	horz->next_horz_touch_x += x_step;
	horz->next_horz_touch_y += y_step;
	return (1);
}

void		horizontal_intersection(t_ray *ray, t_horz *horz)
{
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;

	horz->found_horz_wall_hit = 0;
	horz->horz_wall_hit_x = 0;
	horz->horz_wall_hit_y = 0;
	horz->horz_wall_content = 0;
	y_intercept = floor(player()->y / TILE_SIZE) * TILE_SIZE;
	y_intercept += ray->is_ray_facing_down ? TILE_SIZE : 0;
	x_intercept =
		player()->x + (y_intercept - player()->y) / tan(ray->ray_angle);
	y_step = TILE_SIZE;
	y_step *= ray->is_ray_facing_up ? -1 : 1;
	x_step = TILE_SIZE / tan(ray->ray_angle);
	x_step *= (ray->is_ray_facing_left && x_step > 0) ? -1 : 1;
	x_step *= (ray->is_ray_facing_right && x_step < 0) ? -1 : 1;
	horz->next_horz_touch_x = x_intercept;
	horz->next_horz_touch_y = y_intercept;
	while (is_inside_map(horz->next_horz_touch_x, horz->next_horz_touch_y))
		if (check_horz_collision(ray, horz, x_step, y_step) == -1)
			break ;
}
