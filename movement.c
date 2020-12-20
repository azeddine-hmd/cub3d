/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:29:46 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/20 02:31:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(float *nplayer_x, float *nplayer_y)
{
	float walk_speed;

	walk_speed = player()->walk_speed;
	*nplayer_x += cos(player()->rotation_angle + M_PI / 2) * walk_speed;
	*nplayer_y += cos(player()->rotation_angle) * walk_speed;
}

void	move_left(float *nplayer_x, float *nplayer_y)
{
	float walk_speed;

	walk_speed = player()->walk_speed;
	*nplayer_x -= cos(player()->rotation_angle + M_PI / 2) * walk_speed;
	*nplayer_y -= cos(player()->rotation_angle) * walk_speed;
}

void	move_forwback(float *nplayer_x, float *nplayer_y)
{
	float move_step;

	move_step = player()->walk_direction * player()->walk_speed;
	*nplayer_x = player()->x + cos(player()->rotation_angle) * move_step;
	*nplayer_y = player()->y + sin(player()->rotation_angle) * move_step;
}

void	rotate(void)
{
	player()->rotation_angle += player()->turn_direction * player()->turn_speed;
	player()->rotation_angle = normalize_angle(player()->rotation_angle);
}
