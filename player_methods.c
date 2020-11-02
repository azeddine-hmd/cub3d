/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:52:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/02 14:27:31 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(void)
{
	float move_step;
	float nplayer_x;
	float nplayer_y;

	if (player()->move_right)
	{
		nplayer_x = player()->x + cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
		nplayer_y = player()->y + cos(player()->rotation_angle) * player()->walk_speed;
	}
	else if (player()->move_left)
	{
		nplayer_x = player()->x - cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
		nplayer_y = player()->y - cos(player()->rotation_angle) * player()->walk_speed;
	}
	else
	{
		player()->rotation_angle += player()->turn_direction * player()->turn_speed;
		player()->rotation_angle = normalize_angle(player()->rotation_angle);
		move_step = player()->walk_direction * player()->walk_speed;
		nplayer_x = player()->x + cos(player()->rotation_angle) * move_step;
		nplayer_y = player()->y + sin(player()->rotation_angle) * move_step;
	}

	if (!has_wall_at(nplayer_x, nplayer_y))
	{
		player()->x = nplayer_x;
		player()->y = nplayer_y;
	}
}

void	player_render(void)
{
	t_point p0;
	t_point p1;

	p0.x = player()->x * MINIMAP_SCALE;
	p0.y = player()->y * MINIMAP_SCALE;
	p1.x = p0.x + cos(player()->rotation_angle) * 40;
	p1.y = p0.y + sin(player()->rotation_angle) * 40;

	line(p0, p1, rgb(255, 0, 0));
	square(player()->x * MINIMAP_SCALE - 2, player()->y * MINIMAP_SCALE - 2, 4, rgb(255, 0, 0));
}
