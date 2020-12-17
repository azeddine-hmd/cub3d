/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 03:29:46 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 20:00:29 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(float nplayer_x, float nplayer_y)
{
	nplayer_x = player()->x +
		cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
	nplayer_y = player()->y +
		cos(player()->rotation_angle) * player()->walk_speed;
	player()->move_right = 0;
}

void	move_left(float nplayer_x, float nplayer_y)
{
	nplayer_x = player()->x -
		cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
	nplayer_y = player()->y -
		cos(player()->rotation_angle) * player()->walk_speed;
	player()->move_left = 0;
}

void	move_forwback(float *move_step, float *nplayer_x, float *nplayer_y)
{
	player()->rotation_angle +=
		player()->turn_direction * player()->turn_speed;
	player()->rotation_angle = normalize_angle(player()->rotation_angle);
	*move_step = player()->walk_direction * player()->walk_speed;
	*nplayer_x = player()->x + cos(player()->rotation_angle) * *move_step;
	*nplayer_y = player()->y + sin(player()->rotation_angle) * *move_step;
	player()->move_forward_or_backward = 1;
}

void	no_movement(void)
{
	player()->rotation_angle +=
		player()->turn_direction * player()->turn_speed;
	player()->rotation_angle = normalize_angle(player()->rotation_angle);
}
