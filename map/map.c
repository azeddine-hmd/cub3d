/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:07:50 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 16:08:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	*new_map(t_data *database)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	add(database, map);
	map->height = 0;
	map->width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->frgb[0] = 255;
	map->frgb[1] = 255;
	map->frgb[2] = 255;
	map->crgb[0] = 255;
	map->crgb[1] = 255;
	map->crgb[2] = 255;
	map->maparr = NULL;
	map->map_width = 0;
	return (map);
}

t_map			*read_map(t_data *database, char *file_name)
{
	int			fd;
	int			line_end;
	t_map		*map;
	char		**strings;

	map = new_map(database);
	filler = (t_filler*)malloc(sizeof(t_filler*));
	add(database, filler);
	filler();
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error(database);
	line_end = 1;
	while (line_end)
	{
		if ((line_end = get_next_line(fd, &line)) == -1)
			error(database);
		add(database, line);
		fill_r(database, map, line, filler)
		fill_no(database, map, line, filler);
		fill_so(database, map, line, filler);
		fill_we(database, map, line);
		fill_ea(database, map, line);
		fill_s(database, map, line);
		fill_f(database, map, line);
		fill_c(database, map, line);
		map_arr(database, map, line);
	}
	return (map);
}
