/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 05:29:39 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 19:20:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	get_initial_angle(void)
{
	float	initial_angle;
	char	pview;

	initial_angle = 0;
	pview = g_game.pview;
	if (pview == 'W')
		initial_angle = M_PI;
	else if (pview == 'N')
		initial_angle = (3 * M_PI) / 2;
	else if (pview == 'S')
		initial_angle = M_PI / 2;
	return (initial_angle);
}

void			set_player_state(void)
{
	g_player.x = g_game.initial_pos[0] * TILE_SIZE - (TILE_SIZE / 2);
	g_player.y = g_game.initial_pos[1] * TILE_SIZE - (TILE_SIZE / 2);
	g_player.rotation_angle = get_initial_angle();
	g_player.walk_speed = 10;
	g_player.turn_speed = 3 * (M_PI / 180);
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.right = 0;
	g_player.left = 0;
	g_player.move_forward_or_backward = 0;
	g_player.look = 0;
}

void			player_init(void)
{
	g_player = *(t_player*)xmalloc(sizeof(t_player));
	set_player_state();
}
