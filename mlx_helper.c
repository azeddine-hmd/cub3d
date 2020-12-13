/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:35:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/11 18:33:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(float x, float y, int color)
{
	int *buf;
	int	unused;

	if (!is_inside_window(x, y))
		return ;
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	buf[(int)floor(x) + (int)floor(y) * map()->win_width] = color;
}

int		get_window_color(float x, float y)
{
	int *buf;
	int	unused;

	if (!is_inside_window(x, y))
		return COLOR_RED;
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	return (buf[(int)floor(x) + (int)floor(y) * map()->win_width]);
}

int		texture_pixel_get(int x, int y)
{
	int *buf;
	int	unused;

	if (!is_inside_texture(x, y, gettxt()->width, gettxt()->height))
		return COLOR_RED;
	buf = (int*)mlx_get_data_addr(gettxt()->img, &unused, &unused, &unused);
	return (buf[x + y * gettxt()->width]);
}

int		sprite_pixel_get(int x, int y)
{
	int *buf;
	int	unused;

	if (!is_inside_sprite(x, y, gettxt()->width, gettxt()->height))
		return COLOR_RED;
	buf = (int*)mlx_get_data_addr(map()->s->img, &unused, &unused, &unused);
	return (buf[x + y * map()->s->w]);
}
