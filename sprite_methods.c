/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:29:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/18 12:32:22 by ahamdaou         ###   ########.fr       */
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

/*
** Description: sort sprites based on distance from nearest to farthest,
** then render them as squares on window.
*/

static void	print_sprites_distance(void)
{
	t_sp	*sprite;
	t_data	*head;

	head = map()->sp_head;
	while (head)
	{
		sprite = (t_sp*)head->data;
		printf("distance = %f\n", sprite->dist);
		head = head->next;
	}
}

void		render_sprites(void)
{
	t_data	*head;

	head = map()->sp_head;
	if (!head)
		return ;
	print_sprites_distance();
	linkedlist_bubble_sort(head);
	printf("\n");
	print_sprites_distance();
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
