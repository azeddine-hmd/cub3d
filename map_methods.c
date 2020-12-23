/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_methods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:56:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/22 23:21:16 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_minimap(int x, int y)
{
	int tile_x;
	int tile_y;
	int content;
	int color;

	tile_x = x * TILE_SIZE;
	tile_y = y * TILE_SIZE;
	color = -1;
	content = game()->maparr[x + y * game()->cols];
	if (content == '0')
		color = COLOR_BLACK;
	else if (content == '1')
		color = COLOR_WHITE;
	else if (content == '3')
		color = COLOR_WHITE;
	else if (content == ' ')
		return ;
	else
		color = COLOR_BLACK;
	square(
		tile_x * game()->minimap_scale,
		tile_y * game()->minimap_scale,
		TILE_SIZE * game()->minimap_scale,
		color);
}

/*
** draws a small minimap on top left side window to visuals player
** position in game.
*/

void		minimap_render(void)
{
	int i;
	int j;

	if (g_pref.is_minimap_enabled == 0)
		return ;
	i = -1;
	while (++i < game()->rows)
	{
		j = -1;
		while (++j < game()->cols)
			draw_minimap(j, i);
	}
}

static void	draw_sprite_minimap(int x, int y)
{
	int tile_x;
	int tile_y;
	int content;
	int color;

	tile_x = x * TILE_SIZE;
	tile_y = y * TILE_SIZE;
	color = -1;
	content = game()->maparr[x + y * game()->cols];
	if (content == '2')
		color = COLOR_ORANGE;
	else
		return ;
	square(
		tile_x * game()->minimap_scale,
		tile_y * game()->minimap_scale,
		TILE_SIZE * game()->minimap_scale,
		color);
}

/*
** this is same as the above one only difference is this will draw only sprites
** and ignore other map's elements. You may be wondering why I dublicate code
** two times, well the answer is obvious: I'M F***ing LAZY!!
*/

void		minimap_sprite_render(void)
{
	int i;
	int j;

	if (g_pref.is_minimap_enabled == 0)
		return ;
	i = -1;
	while (++i < game()->rows)
	{
		j = -1;
		while (++j < game()->cols)
			draw_sprite_minimap(j, i);
	}
}
