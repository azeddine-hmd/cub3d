/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:57:22 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 10:19:59 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	set_sprite_initial_position(t_map *map, int x, int y)
{
	char		*arr;
	int			x;
	int			y;
	t_data		**head;
	t_sprite	sprite;

	x = -1;
	while (++x < map_cols)
	{
		y = -1;
		while (++y < map_rows)
			if (arr[x + y * map_cols] == '2')
				add(head, );
	}
}
