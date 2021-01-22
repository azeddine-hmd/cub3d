/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:29:46 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 18:54:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(float *nplayer_x, float *nplayer_y)
{
	float walk_speed;

	walk_speed = g_player.walk_speed;
	*nplayer_x += cos(g_player.rotation_angle + M_PI / 2) * walk_speed;
	*nplayer_y += cos(g_player.rotation_angle) * walk_speed;
}

void	move_left(float *nplayer_x, float *nplayer_y)
{
	float walk_speed;

	walk_speed = g_player.walk_speed;
	*nplayer_x -= cos(g_player.rotation_angle + M_PI / 2) * walk_speed;
	*nplayer_y -= cos(g_player.rotation_angle) * walk_speed;
}

void	move_forwback(float *nplayer_x, float *nplayer_y)
{
	float move_step;

	move_step = g_player.walk_direction * g_player.walk_speed;
	*nplayer_x = g_player.x + cos(g_player.rotation_angle) * move_step;
	*nplayer_y = g_player.y + sin(g_player.rotation_angle) * move_step;
}

void	rotate(void)
{
	g_player.rotation_angle += g_player.turn_direction * g_player.turn_speed;
	g_player.rotation_angle = normalize_angle(g_player.rotation_angle);
}
