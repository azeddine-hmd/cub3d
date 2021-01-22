/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:51:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:19:21 by ahamdaou         ###   ########.fr       */
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

int		has_player_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	result;
	int	content;

	if (x < 0 || x > g_game.map_width || y < 0 || y > g_game.map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = g_game.maparr[grid_x + grid_y * g_game.cols];
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

	if (x < 0 || x > g_game.map_width || y < 0 || y > g_game.map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = g_game.maparr[grid_x + grid_y * g_game.cols] - '0';
	return (content == 2 ? TRUE : FALSE);
}

int		has_hidden_wall_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	content;

	if (x < 0 || x > g_game.map_width || y < 0 || y > g_game.map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	content = g_game.maparr[grid_x + grid_y * g_game.cols] - '0';
	return (content == 3 ? TRUE : FALSE);
}
