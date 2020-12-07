/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:52:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/07 20:43:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(void)
{
	float move_step;
	float nplayer_x;
	float nplayer_y;

	nplayer_x = 0.0;
	nplayer_y = 0.0;
	if (player()->move_right)
	{
		nplayer_x = player()->x + cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
		nplayer_y = player()->y + cos(player()->rotation_angle) * player()->walk_speed;
		player()->move_right = 0;
	}
	else if (player()->move_left)
	{
		nplayer_x = player()->x - cos(player()->rotation_angle + M_PI / 2) * player()->walk_speed;
		nplayer_y = player()->y - cos(player()->rotation_angle) * player()->walk_speed;
		player()->move_left = 0;
	}
	else if (player()->move_forward_or_backward)
	{
		player()->rotation_angle += player()->turn_direction * player()->turn_speed;
		player()->rotation_angle = normalize_angle(player()->rotation_angle);
		move_step = player()->walk_direction * player()->walk_speed;
		nplayer_x = player()->x + cos(player()->rotation_angle) * move_step;
		nplayer_y = player()->y + sin(player()->rotation_angle) * move_step;
		player()->move_forward_or_backward = 1;
	}
	if (!has_wall_at(nplayer_x, player()->y) && !has_sprite_at(nplayer_x, player()->y))
		player()->x = nplayer_x;
	if (!has_wall_at(player()->x, nplayer_y) && !has_sprite_at(player()->x, nplayer_y))
		player()->y = nplayer_y;
}

void	player_render(void)
{
	t_point p0;
	t_point p1;

	p0.x = player()->x * map()->minimap_scale;
	p0.y = player()->y * map()->minimap_scale;
	p1.x = p0.x + cos(player()->rotation_angle)
		* TILE_SIZE * 4 * map()->minimap_scale;
	p1.y = p0.y + sin(player()->rotation_angle)
		* TILE_SIZE * 4 * map()->minimap_scale;

	line(p0, p1, COLOR_RED);
	square(player()->x * map()->minimap_scale - 2, player()->y * map()->minimap_scale - 2, 4, COLOR_RED);
}
