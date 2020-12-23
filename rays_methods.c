/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:52:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 01:56:45 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rays_render(void)
{
	t_point p0;
	t_point p1;
	int		col;

	if (g_pref.is_minimap_enabled == 0)
		return ;
	p0.x = player()->x * game()->minimap_scale;
	p0.y = player()->y * game()->minimap_scale;
	col = -1;
	while (++col < game()->num_rays)
	{
		p1.x = rays()[col]->wall_hit_x * game()->minimap_scale;
		p1.y = rays()[col]->wall_hit_y * game()->minimap_scale;
		line(p0, p1, rgb(0, 255, 0));
	}
}

void	cast_all_rays(void)
{
	float	ray_angle;
	int		col;

	ray_angle = player()->rotation_angle - (FOV_ANGLE / 2);
	col = -1;
	while (++col < game()->num_rays)
	{
		rays()[col]->ray_angle = normalize_angle(ray_angle);
		set_ray_direction(rays()[col]);
		cast(rays()[col]);
		ray_angle += FOV_ANGLE / game()->num_rays;
	}
}
