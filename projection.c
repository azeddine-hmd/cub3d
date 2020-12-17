/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:02:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:05:45 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	projection(t_ray *ray, int col)
{
	t_wall	wall;

	wall.correct_wall_distance =
		ray->distance * cos(ray->ray_angle - player()->rotation_angle);
	wall.distance_proj_plane = (game()->win_width / 2) / tan(FOV_ANGLE / 2);
	wall.wall_strip_height =
		(TILE_SIZE / wall.correct_wall_distance) * wall.distance_proj_plane;
	wall.wall_top_pixel =
		(game()->win_height / 2) - ((wall.wall_strip_height / 2));
	wall.wall_top_pixel = (wall.wall_top_pixel < 0) ? 0 : wall.wall_top_pixel;
	wall.wall_bottom_pixel =
		(game()->win_height / 2) + ((wall.wall_strip_height / 2));
	wall.wall_bottom_pixel = (wall.wall_bottom_pixel > game()->win_height) ?
		game()->win_height : wall.wall_bottom_pixel;
	ceilling_projection(col, &wall);
	settexture(ray);
	wall_projection(col, ray, &wall);
	floor_projection(col, &wall);
}

void		render_projection_walls(void)
{
	int		col;
	t_ray	*ray;

	col = -1;
	while (++col < game()->num_rays)
	{
		ray = rays()[col];
		projection(ray, col);
	}
}
