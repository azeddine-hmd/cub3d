/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:29:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:02:07 by ahamdaou         ###   ########.fr       */
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

	head = game()->sp_head;
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

/*
** Description: sorting sprites in linkedlist using bubble sort algorithm.
**
** note: bubble sort is extremly slow but takes less time to code. however,
** since we will never have millions of sprites in one map it's okey to
** implement it here
*/

void		linkedlist_bubble_sort(t_data *head)
{
	int		swapped;
	t_sp	*lsprite;
	t_sp	*rsprite;

	if (!head)
		return ;
	swapped = 0;
	while (head->next)
	{
		lsprite = (t_sp*)head->data;
		rsprite = (t_sp*)head->next->data;
		if (lsprite->dist < rsprite->dist)
		{
			swap(head, head->next);
			swapped = 1;
		}
		head = head->next;
	}
	if (swapped)
		linkedlist_bubble_sort(head);
}

static void	draw_sprite(int x, float distance, float height)
{
	int i;
	int j;
	int y_offset;
	int color;

	i = x;
	while (i <= x + height)
	{
		j = (game()->win_height - height) / 2;
		y_offset = 0;
		if (i >= 0 && i < game()->win_width && distance < rays()[i]->distance)
		{
			while (j < (game()->win_height + height) / 2 - 1)
			{
				color = sprite_pixel_get(
						(int)(i - x) / height * game()->s->w,
						(int)(y_offset / height * game()->s->h));
				if (j < game()->win_height && j >= 0 && color != 0x000000)
					pixel_put(i, j, color);
				j++;
				y_offset++;
			}
		}
		i++;
	}
}

/*
** sort sprites based on distance from nearest to farthest,then render
** them as squares on window.
*/

static void	set_sprite_angle(t_sp *sprite, float *angle)
{
	*angle = atan2(sprite->y - player()->y, sprite->x - player()->x);
	while (*angle - rays()[0]->ray_angle > M_PI)
		*angle -= 2 * M_PI;
	while (*angle - rays()[0]->ray_angle < -M_PI)
		*angle += 2 * M_PI;
}

void		render_sprites(void)
{
	t_data	*head;
	t_sp	*sprite;
	float	angle;
	float	sprite_height;
	int		column_index;

	head = game()->sp_head;
	if (!head)
		return ;
	linkedlist_bubble_sort(head);
	while (head)
	{
		sprite = (t_sp*)head->data;
		set_sprite_angle(sprite, &angle);
		sprite_height = (TILE_SIZE / sprite->dist) *
			(game()->win_width / 2) / tan(FOV_ANGLE / 2);
		column_index =
			(angle - rays()[0]->ray_angle) / (FOV_ANGLE / game()->win_width)
			- (sprite_height / 2);
		draw_sprite(column_index, sprite->dist, sprite_height);
		head = head->next;
	}
}
