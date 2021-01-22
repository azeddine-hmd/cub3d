/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:03:39 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 18:54:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_ray_horz(t_ray *ray, t_horz *horz, float horz_hit_distance)
{
	ray->distance = horz_hit_distance;
	ray->wall_hit_x = horz->horz_wall_hit_x;
	ray->wall_hit_y = horz->horz_wall_hit_y;
	ray->wall_hit_content = horz->horz_wall_content;
	ray->was_hit_vertical = 0;
}

static void	fill_ray_vert(t_ray *ray, t_vert *vert, float vert_hit_distance)
{
	ray->distance = vert_hit_distance;
	ray->wall_hit_x = vert->vert_wall_hit_x;
	ray->wall_hit_y = vert->vert_wall_hit_y;
	ray->wall_hit_content = vert->vert_wall_content;
	ray->was_hit_vertical = 1;
}

static void	storing_ray_content(t_ray *ray, t_horz *horz, t_vert *vert)
{
	float	horz_hit_distance;
	float	vert_hit_distance;
	t_point	player_point;
	t_point	horz_wall_hit_point;
	t_point	vert_wall_hit_point;

	setpoint(&player_point, g_player.x, g_player.y);
	setpoint(
			&horz_wall_hit_point,
			horz->horz_wall_hit_x,
			horz->horz_wall_hit_y);
	setpoint(
			&vert_wall_hit_point,
			vert->vert_wall_hit_x,
			vert->vert_wall_hit_y);
	horz_hit_distance = (horz->found_horz_wall_hit)
		? distance_between_points(player_point, horz_wall_hit_point) : INT_MAX;
	vert_hit_distance = (vert->found_vert_wall_hit)
		? distance_between_points(player_point, vert_wall_hit_point) : INT_MAX;
	if (vert_hit_distance < horz_hit_distance)
		fill_ray_vert(ray, vert, vert_hit_distance);
	else
		fill_ray_horz(ray, horz, horz_hit_distance);
}

void		cast(t_ray *ray)
{
	t_horz	horz;
	t_vert	vert;

	ray->ray_angle = normalize_angle(ray->ray_angle);
	horizontal_intersection(ray, &horz);
	vertical_intersection(ray, &vert);
	storing_ray_content(ray, &horz, &vert);
}
