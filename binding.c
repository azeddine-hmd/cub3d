/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 01:54:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:21:35 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_binding(int key)
{
	if (key == KEY_ESC)
		game_exit(0);
}

void	minimap_binding(int key)
{
	if (key == KEY_M)
	{
		if (g_pref.is_minimap_enabled == FALSE)
			g_pref.is_minimap_enabled = TRUE;
		else
			g_pref.is_minimap_enabled = FALSE;
	}
}

void	movement_binding(int key)
{
	if (key == KEY_W)
	{
		player()->walk_direction = 1;
		player()->move_forward_or_backward = TRUE;
	}
	else if (key == KEY_A)
		player()->left = TRUE;
	else if (key == KEY_S)
	{
		player()->walk_direction = -1;
		player()->move_forward_or_backward = TRUE;
	}
	else if (key == KEY_D)
		player()->right = TRUE;
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
		if (!(g_game.map_width * g_game.minimap_scale > g_game.win_width))
			g_game.minimap_scale += 0.01;
	}
	else if (key == KEY_O)
	{
		if (!(g_game.minimap_scale < 0.1))
			g_game.minimap_scale -= 0.01;
	}
}
