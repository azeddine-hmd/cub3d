/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 01:54:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/14 02:37:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_binding(int key)
{
	if (key == KEY_ESC)
		game_exit(0);
}

void	movement_binding(int key)
{
	if (key == KEY_W)
	{
		player()->walk_direction = 1;
		player()->move_forward_or_backward = 1;
	}
	else if (key == KEY_A)
		player()->move_left = TRUE;
	else if (key == KEY_S)
	{
		player()->walk_direction = -1;
		player()->move_forward_or_backward = 1;
	}
	else if (key == KEY_D)
		player()->move_right = TRUE;
}

void	rotation_binding(int key)
{
	if (key == KEY_LEFT_ARROW)
		player()->turn_direction = -1;
	if (key == KEY_RIGHT_ARROW)
		player()->turn_direction = 1;
}

void	minimap_resezing_binding(int key)
{
	if (key == KEY_P)
	{
		if (!(map()->map_width * map()->minimap_scale > map()->win_width))
			map()->minimap_scale += 0.01;
	}
	else if (key == KEY_O)
	{
		if (!(map()->minimap_scale < 0.1))
			map()->minimap_scale -= 0.01;
	}
}
