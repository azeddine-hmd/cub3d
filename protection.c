/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:58:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:21:42 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_inside_map(float x, float y)
{
	if (x < 0 || x >= g_game.map_width || y < 0 || y >= g_game.map_height)
		return (0);
	return (1);
}

int		is_inside_window(float x, float y)
{
	if (x < 0 || x >= g_game.win_width || y < 0 || y >= g_game.win_height)
		return (0);
	return (1);
}

int		is_inside_texture(float x, float y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	return (1);
}

int		is_inside_sprite(float x, float y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	return (1);
}
