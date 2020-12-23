/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 03:27:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 02:25:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		check_map(t_map *map, const char *line, int *p)
{
	int		i;
	char	*message;

	i = -1;
	if (*line == '\0')
		error_map(map->name, "empty line inside map's lines.");
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E')
		{
			map->pview = line[i];
			(*p)++;
		}
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
				&& line[i] != 'E' && line[i] != ' ')
		{
			message = xstrdup("'x' not  a map element.");
			message[1] = line[i];
			error_map(map->name, (const char*)message);
			return (0);
		}
	}
	return (1);
}

static void		set_map_width(t_map *map, const char *line)
{
	int	strings_len;

	strings_len = ft_strlen(line);
	if (map->cols == 0)
		map->cols = strings_len;
	else if (map->cols < strings_len)
		map->cols = strings_len;
	map->map_width = map->cols * TILE_SIZE;
}

void			fill_map(t_map *map, t_data **maparr, const char *line, int *p)
{
	const char	*maparr_line;

	maparr_line = (const char*)xstrdup(line);
	if (!maparr_line)
	{
		lst_clear(*maparr);
		error();
	}
	check_map(map, line, p);
	set_map_width(map, line);
	add(maparr, (void*)maparr_line);
}
