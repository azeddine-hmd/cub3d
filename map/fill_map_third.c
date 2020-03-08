/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 03:27:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/08 12:08:59 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		check_map(t_map *map, const char *line)
{
	int i;

	i = -1;
	if (*line == '\0')
		error_map(map->name, "empty line inside map's lines.");
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
				&& line[i] != 'E' && line[i] != ' ')
		{
			error_map(map->name, "map's lines not well formated.");
			return (0);
		}
	}
	return (1);
}

static void	set_map_width(t_map *map, const char *line)
{
	int	strings_len;

	strings_len = ft_strlen(line);
	if (map->map_width == 0)
		map->map_width = strings_len;
	else if (map->map_width < strings_len)
		map->map_width = strings_len;
}

void		fill_map(t_map *map, t_data **maparr, const char *line)
{
	check_map(map, line);
	set_map_width(map, line);
	add(maparr, (void*)xstrdup(line));
}
