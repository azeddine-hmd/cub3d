/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:42:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:21:23 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** storing distance between player and sprites in map
*/

void		set_sprites_distance(void)
{
	t_data	*head;
	t_sp	*sp;
	t_point	player_point;
	t_point	sprite_point;

	head = g_game.sp_head;
	if (!head)
		return ;
	setpoint(&player_point, player()->x, player()->y);
	while (head)
	{
		sp = (t_sp*)head->data;
		setpoint(&sprite_point, sp->x, sp->y);
		sp->dist = distance_between_points(player_point, sprite_point);
		head = head->next;
	}
}

static void	draw_sprite_strip(int col, int x, int sp_height)
{
	int y;
	int	x_offset;
	int y_offset;
	int color;

	y = (g_game.win_height / 2 + player()->look) - sp_height / 2;
	x_offset = x - col;
	y_offset = 0;
	while (y < (g_game.win_height / 2 + player()->look) + sp_height / 2)
	{
		color = sprite_pixel_get(
				(x_offset * g_game.s->w) / sp_height,
				(y_offset * g_game.s->h) / sp_height);
		if (color != COLOR_BLACK)
			pixel_put(x, y, color);
		y++;
		y_offset++;
	}
}

static void	draw_sprite(int col, float distance, float sp_height)
{
	int x;

	if (col >= -sp_height && col < g_game.win_width)
	{
		x = col;
		while (x <= col + sp_height - 1)
		{
			if (x >= 0 && x < g_game.win_width &&
					distance < rays()[x]->distance)
				draw_sprite_strip(col, x, sp_height);
			x++;
		}
	}
}

static void	single_sprite_rendring(t_sp *sprite)
{
	float	angle;
	float	alpha;
	float	sprite_height;
	int		col;

	angle = atan2(player()->y - sprite->y, player()->x - sprite->x) + M_PI;
	alpha = angle - rays()[0]->ray_angle;
	if (rays()[0]->ray_angle > (3 * M_PI / 2) && angle < FOV_ANGLE)
		alpha += 2 * M_PI;
	sprite_height = (TILE_SIZE / sprite->dist) *
		(g_game.win_width / 2) / tan(FOV_ANGLE / 2);
	col = alpha * g_game.win_width / FOV_ANGLE - sprite_height / 2;
	draw_sprite(col, sprite->dist, sprite_height);
}

void		render_sprites(void)
{
	t_data	*head;
	t_sp	*sprite;

	head = g_game.sp_head;
	if (!head)
		return ;
	linkedlist_bubble_sort(head);
	while (head)
	{
		sprite = (t_sp*)head->data;
		single_sprite_rendring(sprite);
		head = head->next;
	}
}
