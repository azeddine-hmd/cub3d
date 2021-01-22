/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:51:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 19:08:10 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		has_wall_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > g_game.map_width || y < 0 || y > g_game.map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = g_game.maparr[grid_x + grid_y * g_game.cols] - '0';
	return (content == 1 ? TRUE : FALSE);
}

int		has_sprite_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > g_game.map_width || y < 0 || y > g_game.map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = g_game.maparr[grid_x + grid_y * g_game.cols] - '0';
	return (content == 2 ? TRUE : FALSE);
}

int		has_elements_at(float x, float y, char *elements)
{
	int	content;
	int	is_element_exist;
	int	i;

	if (!is_inside_map(x, y))
		return (FALSE);
	content = g_game.maparr
		[(int)floor(x / TILE_SIZE) + (int)floor(y / TILE_SIZE) * g_game.cols];
	is_element_exist = FALSE;
	i = 0;
	while (elements[i])
	{
		if (content == elements[i])
			is_element_exist = TRUE;
		i++;
	}
	return (is_element_exist);
}
