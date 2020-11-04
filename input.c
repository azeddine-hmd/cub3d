/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:08:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/04 18:05:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_pressed(int key, void *param)
{
	param = NULL;
	if (key == KEY_ESC)
		game_exit();
	else if (key == KEY_LEFT_ARROW)
		player()->turn_direction = -1;
	else if (key == KEY_RIGHT_ARROW)
		player()->turn_direction = 1;
	else if (key == KEY_W)
	{
		player()->walk_direction = 1;
		player()->move_forward_or_backward = 1;
	}
	else if (key == KEY_A)
		player()->move_left = 1;
	else if (key == KEY_S)
	{
		player()->walk_direction = -1;
		player()->move_forward_or_backward = 1;
	}
	else if (key == KEY_D)
		player()->move_right = 1;
	else if (key == 35)
		map()->minimap_scale += 0.1;
	else if (key == 31)
		map()->minimap_scale -= 0.1;
	else
		printf("key: %d not mapped\n", key);
	game_loop();
	return (0);
}

static int	on_key_released(int key, void *param)
{
	param = NULL;
	if (key == KEY_ESC)
		game_exit();
	else if (key == KEY_LEFT_ARROW)
		player()->turn_direction = 0;
	else if (key == KEY_RIGHT_ARROW)
	{
		printf("KEY_RIGHT_ARROW released\n");
		player()->turn_direction = 0;
	}
	else if (key == KEY_W)
	{
		printf("KEY_W released\n");
		player()->walk_direction = 0;
	}
	else if (key == KEY_A)
		player()->move_left = 0;
	else if (key == KEY_S)
		player()->walk_direction = 0;
	else if (key == KEY_D)
		player()->move_right = 0;
	else
		printf("key: %d not mapped\n", key);
	game_loop();
	return (0);
}

int			on_window_closed(void)
{
	game_exit();
	return (0);
}

static int			on_mouse_moved(void)
{
	return (0);
}

/*
** before calling this function, 'player()' should be invoked first.
*/

void		input_handler(void)
{
	mlx_hook(vars()->win, 2, 1L << 0, on_key_pressed, NULL);
	mlx_hook(vars()->win, 3, 1L << 1, on_key_released, NULL);
	mlx_hook(vars()->win, 17, 1L << 18, on_window_closed, NULL);
	mlx_hook(vars()->win, 6, 0, on_mouse_moved, NULL);
}
