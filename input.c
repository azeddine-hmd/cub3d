/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:08:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/31 13:21:35 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_pressed(int key, void *param)
{
	param = NULL;
	key = key + 1 - 1;
	if (key == KEY_ESC)
		game_exit();
	else if (key == KEY_LEFT_ARROW)
		player()->turn_direction = -1;
	else if (key == KEY_RIGHT_ARROW)
		player()->turn_direction = 1;
	else if (key == KEY_W)
		player()->walk_direction = 1;
	else if (key == KEY_A)
		player()->x = player()->x + player()->walk_speed;
	else if (key == KEY_S)
		player()->walk_direction = -1;
	else if (key == KEY_D)
		player()->x = player()->x - player()->walk_speed;
	else
		printf("key: %d not mapped\n", key);
	game_loop();
	return (0);
}

static int	on_key_released(int key, void *param)
{
	param = NULL;
	key = key + 1 - 1;
	if (key == KEY_ESC)
		game_exit();
	else if (key == KEY_LEFT_ARROW)
		player()->turn_direction = 0;
	else if (key == KEY_RIGHT_ARROW)
		player()->turn_direction = 0;
	else if (key == KEY_W)
		player()->walk_direction = 0;
	else if (key == KEY_A)
		player()->x = player()->x + player()->walk_speed; // refactor
	else if (key == KEY_S)
		player()->walk_direction = 0;
	else if (key == KEY_D)
		player()->x = player()->x - player()->walk_speed; // refactor
	else
		printf("key: %d not mapped\n", key);
	game_loop();
	return (0);
}

static int	on_window_closed(int key, void *param)
{
	param = NULL;
	key = key + 1 - 1;
	game_exit();
	return (0);
}

/*
** before calling this function, 'player()' should be invoked first.
*/

void		input_handler(void)
{
	mlx_hook(vars()->win, 2, 1L << 0, on_key_pressed, NULL);
	mlx_hook(vars()->win, 3, 1L << 1, on_key_released, NULL);
	mlx_hook(vars()->win, 17, 1L << 17, on_window_closed, NULL);
}
