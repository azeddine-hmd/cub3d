/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:29:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/19 14:56:15 by ahamdaou         ###   ########.fr       */
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

	head = map()->sp_head;
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
		if (lsprite->dist > rsprite->dist)
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
		j = (map()->win_height - height) / 2;
		y_offset = 0;
		if (i >= 0 && i < map()->win_width && distance < rays[i]->dist)
		{
			while (j < (map()->win_height + height) / 2 - 1)
			{
				color = g_texture[4].data[(int)(y_offset / height *
						g_texture[4].height) * g_texture[4].width +
					(int)((i - x) / height * g_texture[4].width)];
				j++;
				y_offset++;
			}
		}
		i++;
	}
}

/*
** Description: sort sprites based on distance from nearest to farthest,
** then render them as squares on window.
*/

void		render_sprites(void)
{
	t_data	*head;
	t_sp	*sprite;
	float	angle;
	int		sp_size;
	float	sprite_height;
	int		column_index;
	int		i;

	head = map()->sp_head;
	if (!head)
		return ;
	sp_size = lst_size(head);
	linkedlist_bubble_sort(head);
	i = -1;
	while (++i < sp_size)
	{
		sprite = (t_sp*)head->data;
		angle = atan2(sprite->y - player()->y, sprite->x - player()->x);
		while (angle - rays()[i]->ray_angle > M_PI)
			angle -= 2 * M_PI;
		while (angle - rays()[i]->ray_angle < -M_PI)
			angle += 2 * M_PI;
		sprite_height = (TILE_SIZE / sprite->dist);
		column_index = (angle - rays()[i]->ray_angle)
		/ (FOV_ANGLE / map()->win_width) - (sprite_height / 2);
		draw_sprite(column_index, sprite->dist, sprite_height);
		head = head->next;
		if (head == NULL)
			printf("YOO head is null somehting wrong");
	}
}

/*
** make sure to call this function before game end, otherwise memory leak
** deallocate sprites memory only if sprite head is exists otherwise do nothing
*/

void		release_sprites(void)
{
	if (map()->sp_head)
		lst_clear(map()->sp_head);
	mlx_destroy_image(vars()->mlx, map()->s->img);
}
