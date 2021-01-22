/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:23:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 18:54:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	slide(float nplayer_x, float nplayer_y)
{
	if (
			!has_wall_at(nplayer_x, g_player.y) &&
			!has_sprite_at(nplayer_x, g_player.y))
		g_player.x = nplayer_x;
	if (
			!has_wall_at(g_player.x, nplayer_y) &&
			!has_sprite_at(g_player.x, nplayer_y))
		g_player.y = nplayer_y;
}

static void	move_with_collision(float nplayer_x, float nplayer_y)
{
	if (
			!has_wall_at(nplayer_x, nplayer_y) &&
			!has_sprite_at(nplayer_x - 5, nplayer_y - 5))
	{
		g_player.x = nplayer_x;
		g_player.y = nplayer_y;
	}
}

void		move_player(void)
{
	float nplayer_x;
	float nplayer_y;

	nplayer_x = g_player.x;
	nplayer_y = g_player.y;
	rotate();
	if (g_player.right)
		move_right(&nplayer_x, &nplayer_y);
	else if (g_player.left)
		move_left(&nplayer_x, &nplayer_y);
	else if (g_player.move_forward_or_backward)
		move_forwback(&nplayer_x, &nplayer_y);
	if (g_pref.is_collision_enabled)
		if (g_pref.is_slide_enabled)
			slide(nplayer_x, nplayer_y);
		else
			move_with_collision(nplayer_x, nplayer_y);
	else
	{
		g_player.x = nplayer_x;
		g_player.y = nplayer_y;
	}
}

void		player_render(void)
{
	t_point p0;
	t_point p1;
	int		line_height;

	if (g_pref.is_minimap_enabled == 0)
		return ;
	p0.x = g_player.x * g_game.minimap_scale;
	p0.y = g_player.y * g_game.minimap_scale;
	line_height = 2;
	p1.x = p0.x + cos(g_player.rotation_angle) *
		(TILE_SIZE * line_height * g_game.minimap_scale);
	p1.y = p0.y + sin(g_player.rotation_angle) *
		(TILE_SIZE * line_height * g_game.minimap_scale);
	line(p0, p1, COLOR_RED);
	square(
			g_player.x * g_game.minimap_scale - 2,
			g_player.y * g_game.minimap_scale - 2,
			4,
			COLOR_RED);
}
