/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:32:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/29 20:00:45 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	convert_spacesto_wall(char *maparr)
{
	int i;

	i = -1;
	while (maparr[++i])
		if (maparr[i] == ' ')
			maparr[i] = '1';
}

static void	set_initial_player_position(
		const char *maparr,
		int map_rows,
		int map_cols,
		t_map *map)
{
	char	pl;
	int		x;
	int		y;
	int		flag;

	flag = 1;
	x = -1;
	while (++x < map_cols)
	{
		y = -1;
		while (++y < map_rows)
		{
			pl = maparr[x + y * map_cols];
			if (pl == 'N' || pl == 'S' || pl == 'W' || pl == 'E')
			{
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

static void	set_num_rays(t_map *map)
{
	map->num_rays = map->map_width;
	printf("num_rays = %d\n", map->num_rays);
}

void		set_map_information(t_map *map)
{
	convert_spacesto_wall(map->maparr);
	set_initial_player_position(map->maparr, map->rows, map->cols, map);
	set_num_rays(map);
}