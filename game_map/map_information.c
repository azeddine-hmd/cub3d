/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_information.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 00:32:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/03 16:43:45 by ahamdaou         ###   ########.fr       */
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

void	set_cols(t_map *map, t_data *tmp_map)
{
	int	col;

	map->cols = 0;
	while (tmp_map)
	{
		col = ft_strlen((char*)tmp_map->data);
		if (map->cols < col)
			map->cols = col;
		tmp_map = tmp_map->next;
	}
	map->map_width = map->cols * TILE_SIZE;
}

void	set_rows(t_map *map, t_data *tmp_map)
{
	map->rows = lst_size(tmp_map);
	map->map_height = map->rows * TILE_SIZE;
}

void	set_map_information(t_map *map, t_data *tmp_map)
{
	if (!tmp_map)
		error_message("map not found");
	set_cols(map, tmp_map);
	set_rows(map, tmp_map);
	map->num_rays = map->win_width;
	check_player_instance();
	if (!is_map_walls_closed(tmp_map, map->cols))
	{
		lst_clear(tmp_map);
		error_message("map is not surrounding with walls");
	}
	joinmap(map, tmp_map);
	set_initial_player_position(map);
	set_sp_initial_position(map);
}
