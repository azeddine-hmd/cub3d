/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:51:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/07 12:22:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		has_wall_at(float x, float y)
{
	int grid_x;
	int	grid_y;
	int	result;
	int	element;

	if (x < 0 || x > map()->map_width || y < 0 || y > map()->map_height)
		return (1);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	element = map()->maparr[grid_x + grid_y * map()->cols];
	result = (element - '0') != 0;
	if (element == 'N' || element == 'S' || element == 'W' || element == 'E')
		result = 0;
	return (result);
}
