/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:57:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/17 09:47:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_sp	*new_sprite(int x, int y)
{
	t_sp	*sp;

	sp = (t_sp*)xmalloc(sizeof(t_sp));
	if (!sp)
	{
		lst_clear(game()->sp_head);
		error();
	}
	sp->x = (x + 0.5) * TILE_SIZE;
	sp->y = (y + 0.5) * TILE_SIZE;
	sp->dist = -1;
	return (sp);
}

void		set_sp_initial_position(t_map *map)
{
	int x;
	int	y;

	x = -1;
	while (++x < map->cols)
	{
		y = -1;
		while (++y < map->rows)
			if (map->maparr[x + y * map->cols] == '2')
				add(&(map->sp_head), new_sprite(x, y));
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
