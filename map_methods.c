/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:56:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/16 14:14:03 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** draws a small minimap on top left side window to visuals
** player position in game.
*/

void	minimap_render()
{
	int i;
	int j;

	i = -1;
	while (++i < map()->rows)
	{
		j = -1;
		while (++j < map()->cols)
		{
			int tile_x = j * TILE_SIZE;
			int tile_y = i * TILE_SIZE;
			int color = map()->maparr[j + i * map()->cols] == '1' ?
				rgb(255, 255, 255) : rgb(0, 0, 0);
			square(
				tile_x * map()->minimap_scale,
				tile_y * map()->minimap_scale,
				TILE_SIZE * map()->minimap_scale,
				color
			);
		}
	}
}

int		is_inside_map(float x, float y)
{
	if (x < 0 || x >= map()->map_width || y < 0 || y >= map()->map_height)
		return (0);
	return (1);
}

int		is_inside_window(float x, float y)
{
	if (x < 0 || x >= map()->win_width || y < 0 || y >= map()->win_height)
		return (0);
	return (1);
}

int		is_inside_texture(float x, float y, int txt_width, int txt_height)
{
	if (x < 0 || x >= txt_width || y < 0 || y >= txt_height)
		return (0);
	return (1);
}
