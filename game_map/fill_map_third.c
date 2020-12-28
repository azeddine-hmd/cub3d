/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 03:27:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 18:25:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*static int		check_map(t_map *map, const char *line)
{
	char	*message;
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E')
			map->pview = line[i];
		if (line[i] != '0' && line[i] != '1' && line[i] != '2' && line[i] != '3'
				&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
				&& line[i] != 'E' && line[i] != ' ')
		{
			message = xstrdup("'x' not  a map element.");
			message[1] = line[i];
			error_line(freader.ln, message);
			return (0);
		}
	}
	return (1);
}*/

static void	set_cols(t_map *map, const char *line)
{
	int	strings_len;

	strings_len = ft_strlen(line);
	if (map->cols == 0)
		map->cols = strings_len;
	else if (map->cols < strings_len)
		map->cols = strings_len;
	map->map_width = map->cols * TILE_SIZE;
}

void		fill_map(t_map *map, t_data **tmp_map)
{
	char	*tmp_line;

	tmp_line = ft_strdup(freader.line);
	if (!tmp_line)
	{
		lst_clear(*tmp_map);
		error();
	}
	set_cols(map, freader.line);
	add(tmp_map, (void*)tmp_line);
}
