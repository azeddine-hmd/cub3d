/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:58:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:06:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_inside_map(float x, float y)
{
	if (x < 0 || x >= game()->map_width || y < 0 || y >= game()->map_height)
		return (0);
	return (1);
}

int		is_inside_window(float x, float y)
{
	if (x < 0 || x >= game()->win_width || y < 0 || y >= game()->win_height)
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
