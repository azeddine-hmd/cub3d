/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:02:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/07 19:27:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_projection_walls(void)
{
	int 	i;
	int		y;
	t_ray	*ray;
	float 	correct_wall_distance;
	float 	distance_proj_plane;
	float 	wall_strip_height;
	int 	wall_top_pixel;
	int		wall_bottom_pixel;

	i = -1;
	while (++i < map()->num_rays)
	{
		ray = rays()[i];

		correct_wall_distance = ray->distance * cos(ray->ray_angle - player()->rotation_angle);

		// calculate the distace to the projection plane
		distance_proj_plane = (map()->win_width / 2) / tan(FOV_ANGLE / 2);

		// projected wall height
		wall_strip_height = (TILE_SIZE / correct_wall_distance) * distance_proj_plane;

        wall_top_pixel = (map()->win_height / 2) - (wall_strip_height / 2);
        wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;

        wall_bottom_pixel = (map()->win_height / 2) + (wall_strip_height / 2);
        wall_bottom_pixel = wall_bottom_pixel > map()->win_height ? map()->win_height : wall_bottom_pixel;

		int	*crgb = map()->crgb;
		y = -1;
		while (++y < wall_top_pixel)
			pixel_put(i, y, rgb(crgb[0], crgb[1], crgb[2]));

		settexture(ray);

		// applying texture on walls
		int	offset_x;
		int offset_y;
		int	distance_from_top;

		// calculate offset_x
		if (ray->was_hit_vertical)
			offset_x = f_mod(ray->wall_hit_y, TILE_SIZE) * (gettxt()->width / TILE_SIZE);
		else
			offset_x = f_mod(ray->wall_hit_x, TILE_SIZE) * (gettxt()->width / TILE_SIZE);

		y = wall_top_pixel - 1;
		while (++y < wall_bottom_pixel)
		{
			distance_from_top = y + (wall_strip_height / 2) - (map()->win_height / 2);
			offset_y = distance_from_top * ((float)gettxt()->height / wall_strip_height);
			pixel_put(i, y, texture_pixel_get(offset_x, offset_y));
		}

		int *frgb = map()->frgb;
		y = wall_bottom_pixel - 1;
		while (++y < map()->win_height)
		{
			if (y < 0)
				break ;
			pixel_put(i, y, rgb(frgb[0], frgb[1], frgb[2]));
		}
	}
}
