/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:08:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/11 19:19:13 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	on_key_pressed(int key, void *param)
{
	param = NULL;
	if (key == KEY_ESC)
		game_exit(0);
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
		player()->move_left = TRUE;
	else if (key == KEY_S)
	{
		player()->walk_direction = -1;
		player()->move_forward_or_backward = 1;
	}
	else if (key == KEY_D)
		player()->move_right = TRUE;
	else if (key == KEY_P)
	{
		if (!(map()->map_width * map()->minimap_scale > map()->win_width))
			map()->minimap_scale += 0.01;
	}
	else if (key == KEY_O)
	{
		if (!(map()->minimap_scale < 0.1))
			map()->minimap_scale -= 0.01;
	}
	else if (key == KEY_1)
		play_song(1);
	else if (key == KEY_2)
		play_song(2);
	else if (key == KEY_3)
		play_song(3);
	else if (key == KEY_4)
		play_song(4);
	else if (key == KEY_5)
		play_song(5);
	else if (key == KEY_6)
		play_song(6);
	else if (key == KEY_7)
		play_song(7);
	else if (key == KEY_8)
		play_song(8);
	else if (key == KEY_9)
		play_song(9);
	else if (key == KEY_0)
		play_song(0);
	game_loop();
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
	game_loop();
	return (0);
}

/*
** exit game if user click on red button window
*/

static int			on_window_closed(void)
{
	system("killall afplay &2>1 >/dev/null");
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
