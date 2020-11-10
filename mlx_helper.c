/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:35:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/08 18:15:51 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(int x, int y, int color)
{
	int *buf;
	int	unused;

	if (!is_inside_window(x, y))
		return ;
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	buf[x + y * map()->win_width] = color;
}

int		pixel_get(int x, int y)
{
	int *buf;
	int	unused;

	if (!is_inside_texture(x, y, gettxt()->width, gettxt()->height))
		return rgb(255, 0, 0);
	buf = (int*)mlx_get_data_addr(gettxt()->img, &unused, &unused, &unused);
	return (buf[x + y * gettxt()->width]);
}
