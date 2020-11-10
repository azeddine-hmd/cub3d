/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:57:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 12:01:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_sp	*new_sprite(int x, int y)
{
	t_sp	*sp;

	sp = (t_sp*)malloc(sizeof(t_sp));
	if (!sp)
		error(); // modify it later, remember to free sprite list data
	printf("sprite: x = %d | y = %d\n", x, y);
	sp->x = x;
	sp->y = y;
	return (sp);
}

void			set_sp_initial_position(t_map *map)
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
	printf("all sprite data have been stored succesfully\n");
}
