/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:08:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 18:55:41 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_pressed(int key, void *param)
{
	param = NULL;
	global_binding(key);
	movement_binding(key);
	rotation_binding(key);
	if (g_bonus)
	{
		if (key == KEY_UP_ARROW)
			g_player.look += 100;
		else if (key == KEY_DOWN_ARROW)
			g_player.look -= 100;
		if (key == KEY_L)
		{
			if (g_pref.is_slide_enabled)
				g_pref.is_slide_enabled = FALSE;
			else
				g_pref.is_slide_enabled = TRUE;
		}
		collision_binding(key);
		audio_binding(key);
		minimap_binding(key);
		minimap_resezing_binding(key);
		window_binding(key);
	}
	return (0);
}

static int	on_key_released(int key, void *param)
{
	param = NULL;
	if (key == KEY_ESC)
		game_exit(0);
	else if (key == KEY_LEFT_ARROW)
		g_player.turn_direction = 0;
	else if (key == KEY_RIGHT_ARROW)
		g_player.turn_direction = 0;
	else if (key == KEY_W)
	{
		g_player.walk_direction = 0;
		g_player.move_forward_or_backward = FALSE;
	}
	else if (key == KEY_A)
		g_player.left = FALSE;
	else if (key == KEY_S)
	{
		g_player.walk_direction = 0;
		g_player.move_forward_or_backward = FALSE;
	}
	else if (key == KEY_D)
		g_player.right = FALSE;
	return (0);
}

/*
** exit game if user click on red button window
*/

static int	on_window_closed(void)
{
	game_exit(0);
	return (-1);
}

/*
** before calling this function player_init() should be called first.
*/

int			input_handler(void)
{
	mlx_hook(vars()->win, 2, 1L << 0, on_key_pressed, NULL);
	mlx_hook(vars()->win, 3, 1L << 1, on_key_released, NULL);
	mlx_hook(vars()->win, 17, 1L << 18, on_window_closed, NULL);
	render();
	return (0);
}
