/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:32:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/03 16:07:31 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	set_initial_player_position(t_map *map)
{
	char	pl;
	int		x;
	int		y;
	int		flag;

	flag = 1;
	x = -1;
	while (++x < map->cols)
	{
		y = -1;
		while (++y < map->rows)
		{
			pl = map->maparr[x + y * map->cols];
			if (pl == 'N' || pl == 'S' || pl == 'W' || pl == 'E')
			{
				map->pview = pl;
				flag = 0;
				break ;
			}
		}
		if (flag == 0)
			break ;
	}
	map->initial_pos[0] = x + 1;
	map->initial_pos[1] = y + 1;
}
