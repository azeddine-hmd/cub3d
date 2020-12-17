/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:23:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 20:04:28 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void move(float nplayer_x, float nplayer_y)
{
	player()->x = nplayer_x;
	player()->y = nplayer_y;
}

static void	slide(float nplayer_x, float nplayer_y)
{
	if (
			!has_wall_at(nplayer_x, player()->y) &&
			!has_sprite_at(nplayer_x, player()->y))
		player()->x = nplayer_x;
	if (
			!has_wall_at(player()->x, nplayer_y) &&
			!has_sprite_at(player()->x, nplayer_y))
		player()->y = nplayer_y;
}

void	move_player(void)
{
	float move_step;
	float nplayer_x;
	float nplayer_y;

	nplayer_x = player()->x;
	nplayer_y = player()->y;
	if (player()->move_right)
		move_right(nplayer_x, nplayer_y);
	else if (player()->move_left)
		move_left(nplayer_x, nplayer_y);
	else if (player()->move_forward_or_backward)
		move_forwback(&move_step, &nplayer_x, &nplayer_y);
	else
		no_movement();
	if (game()->is_collision_enabled)
		slide(nplayer_x, nplayer_y);
	else
		move(nplayer_x, nplayer_y);
}

void	player_render(void)
{
	t_point p0;
	t_point p1;
	int		line_height;

	if (game()->is_minimap_enabled == 0)
		return ;
	p0.x = player()->x * game()->minimap_scale;
	p0.y = player()->y * game()->minimap_scale;
	line_height = 2;
	p1.x = p0.x + cos(player()->rotation_angle) *
		(TILE_SIZE * line_height * game()->minimap_scale);
	p1.y = p0.y + sin(player()->rotation_angle) *
		(TILE_SIZE * line_height * game()->minimap_scale);
	line(p0, p1, COLOR_RED);
	square(
			player()->x * game()->minimap_scale - 2,
			player()->y * game()->minimap_scale - 2,
			4,
			COLOR_RED);
}
