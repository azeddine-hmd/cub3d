/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:52:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/30 18:35:53 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(void)
{
	float move_step;
	float nplayer_x;
	float nplayer_y;

	player()->rotation_angle += player()->turn_direction * player()->turn_speed;
	player()->rotation_angle = normalize_angle(player()->rotation_angle);
	move_step = player()->walk_direction * player()->walk_speed;
	nplayer_x = player()->x + cos(player()->rotation_angle) * move_step;
	nplayer_y = player()->y + sin(player()->rotation_angle) * move_step;

	// debugging
	//printf("move_step = %f\n", move_step);
	//printf("nplayer_x = %f\n", nplayer_x);
	//printf("nplayer_y = %f\n\n", nplayer_y);

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
