/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:52:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/14 19:04:08 by ahamdaou         ###   ########.fr       */
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
