/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:37:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 03:47:26 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	*new_map()
{
	t_map	*map;

	map = (t_map*)xmalloc(sizeof(t_map));
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

static int		check_map(const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (line[i] == ' ')
			continue ;
		printf("%s\n", line);
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E')
		{
			printf("\"%s\"\n", line);
			return (0);
		}
	}
	if (line[0] == '\0')
		return (0);
	return (1);
}

t_map			*read_map(const char *file_name)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		line_end;
	char	**strings;
	int		i;

	map = new_map();
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error();
	line_end = 1;
	while (line_end)
	{
		if ((line_end = get_next_line(fd, &line)) == -1)
			error();
		add(*get_head_node(), line);
		strings = ft_split(line, ' ');
		xfree(line);
		i = -1;
		while (strings[++i])
			add(*get_head_node(), strings[i]);
		while (strings[++i])
		{
			if (ft_onlyspaces(strings[i]))
				continue ;
			if (!ft_strcmp(strings[i], "R"))
				fill_r(map, (const char**)(strings + i + 1));
			if (check_map(map, (const char**)strings[i]))
				fill_map(map, (const char**)(strings + i + 1));
		}
		i = -1;
		while (strings[++i])
			xfree(strings[i]);
	}
	return (map);
}
