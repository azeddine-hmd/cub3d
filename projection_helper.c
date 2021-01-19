/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 05:36:58 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/17 12:34:06 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceilling_projection(int col, t_wall *wall)
{
	int y;
	int	*crgb;

	crgb = game()->crgb;
	y = -1;
	while (++y < wall->wall_top_pixel)
		pixel_put(col, y, rgb(crgb[0], crgb[1], crgb[2]));
}

void	floor_projection(int col, t_wall *wall)
{
	int y;
	int *frgb;

	frgb = game()->frgb;
	y = wall->wall_bottom_pixel - 1;
	while (++y < game()->win_height)
		pixel_put(col, y, rgb(frgb[0], frgb[1], frgb[2]));
}

void	wall_projection(int col, t_ray *ray, t_wall *wall)
{
	int y;
	int offset_y;
	int offset_x;
	int distance_from_top;

	if (ray->was_hit_vertical)
		offset_x =
			f_mod(ray->wall_hit_y, TILE_SIZE) * (gettxt()->width / TILE_SIZE);
	else
		offset_x =
			f_mod(ray->wall_hit_x, TILE_SIZE) * (gettxt()->width / TILE_SIZE);
	y = wall->wall_top_pixel - 1;
	while (++y < wall->wall_bottom_pixel)
	{
		distance_from_top =
			y + (wall->wall_strip_height / 2) -
			(game()->win_height / 2 + player()->look);
		offset_y = distance_from_top *
			((float)gettxt()->height / wall->wall_strip_height);
		pixel_put(col, y, texture_pixel_get(offset_x, offset_y));
	}
}
