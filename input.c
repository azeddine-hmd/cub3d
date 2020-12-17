/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:08:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 19:51:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_pressed(int key, void *param)
{
	param = NULL;
	global_binding(key);
	rotation_binding(key);
	movement_binding(key);
	minimap_binding(key);
	minimap_resezing_binding(key);
	if (key == KEY_C)
	{
		if (game()->is_collision_enabled)
			game()->is_collision_enabled = FALSE;
		else
			game()->is_collision_enabled = TRUE;
	}
	render();
	return (0);
}

static int	on_key_released(int key, void *param)
{
	param = NULL;
	if (key == KEY_ESC)
		game_exit(0);
	else if (key == KEY_LEFT_ARROW)
		player()->turn_direction = 0;
	else if (key == KEY_RIGHT_ARROW)
		player()->turn_direction = 0;
	else if (key == KEY_W)
		player()->walk_direction = 0;
	else if (key == KEY_A)
		player()->move_left = FALSE;
	else if (key == KEY_S)
		player()->walk_direction = 0;
	else if (key == KEY_D)
		player()->move_right = FALSE;
	return (0);
}

/*
** exit game if user click on red button window
*/

static int	on_window_closed(void)
{
	system("killall afplay");
	game_exit(0);
	return (0);
}

/*
** before calling this function player() should be called first.
*/

void		input_handler(void)
{
	mlx_hook(vars()->win, 2, 1L << 0, on_key_pressed, NULL);
	mlx_hook(vars()->win, 3, 1L << 1, on_key_released, NULL);
	mlx_hook(vars()->win, 17, 1L << 18, on_window_closed, NULL);
}
