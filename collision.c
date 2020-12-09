/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:51:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/08 06:05:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		has_wall_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > map()->map_width || y < 0 || y > map()->map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = map()->maparr[grid_x + grid_y * map()->cols] - '0';
	return (content == 1 ? TRUE : FALSE);
}

int		has_player_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	result;
	int	content;

	if (x < 0 || x > map()->map_width || y < 0 || y > map()->map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = map()->maparr[grid_x + grid_y * map()->cols];
	if (content == 'N' || content == 'S' || content == 'W' || content == 'E')
		result = TRUE;
	else
		result = FALSE;
	return (result);
}

int		has_sprite_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > map()->map_width || y < 0 || y > map()->map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = map()->maparr[grid_x + grid_y * map()->cols] - '0';
	return (content == 2 ? TRUE : FALSE);
}

int		has_hidden_wall_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > map()->map_width || y < 0 || y > map()->map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = map()->maparr[grid_x + grid_y * map()->cols] - '0';
	return ( content == 3 ? TRUE : FALSE);
}
