/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:35:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:20:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(float x, float y, int color)
{
	int *buf;
	int	unused;

	if (!is_inside_window(x, y))
		return ;
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	buf[(int)floor(x) + (int)floor(y) * g_game.win_width] = color;
}

int		pixel_get(float x, float y)
{
	int *buf;
	int	unused;

	if (!is_inside_window(x, y))
		return (COLOR_RED);
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	return (buf[(int)floor(x) + (int)floor(y) * g_game.win_width]);
}

int		texture_pixel_get(int x, int y)
{
	int *buf;
	int	unused;

	if (!is_inside_texture(x, y, gettxt()->width, gettxt()->height))
		return (COLOR_RED);
	buf = (int*)mlx_get_data_addr(gettxt()->img, &unused, &unused, &unused);
	return (buf[x + y * gettxt()->width]);
}

int		sprite_pixel_get(int x, int y)
{
	int *buf;
	int	unused;

	if (!is_inside_sprite(x, y, g_game.s->w, g_game.s->h))
		return (COLOR_RED);
	buf = (int*)mlx_get_data_addr(g_game.s->img, &unused, &unused, &unused);
	return (buf[x + y * g_game.s->w]);
}
