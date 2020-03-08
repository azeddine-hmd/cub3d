/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:13:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/08 12:10:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	*new_map(void)
{
	t_map	*map;

	map = (t_map*)xmalloc(sizeof(t_map));
	map->name = NULL;
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
	map->map_size = 0;
	return (map);
}

t_map			*read_map(const char *file_name)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		line_end;
	char	**strings;
	int		i;
	t_data	*maparr;
	int		map_time;
	int		map_reached;

	map = new_map();
	maparr = NULL;
	map_time = 0;
	map->name = xstrdup(file_name);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error();
	line_end = 1;
	while (line_end)
	{
		if ((line_end = get_next_line(fd, &line)) == -1)
			error();
		add(get_head_node(), line);
		strings = ft_split(line, ' ');
		add_double_pointer(strings);
		i = -1;
		while (strings[++i])
		{
			if (!ft_strcmp(strings[i], "R"))
			{
				fill_r(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "NO"))
			{
				fill_no(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "SO"))
			{
				fill_so(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "WE"))
			{
				fill_we(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "EA"))
			{
				fill_ea(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "S"))
			{
				fill_s(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "F"))
			{
				fill_f(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (!ft_strcmp(strings[i], "C"))
			{
				fill_c(map, (const char**)(strings + i + 1));\
				break ;
			}
			else
			{
				map_time = 1;
				break ;
			}
		}
		if (map_time)
			break ;
		xfree(line);
	}
	xfree_double_pointer(strings);
	if (*line != '\0')
		fill_map(map, &maparr, (const char*)line);
	xfree(line);
	map_reached = 0;
	while (line_end)
	{
		if ((line_end = get_next_line(fd, &line)) == -1)
			error();
		add(get_head_node(), line);
		if (!map_reached && *line == '\0')
			continue ;
		map_reached = 1;
		fill_map(map, &maparr, (const char*)line);
		xfree(line);
	}
	if (!is_map_closed(map, maparr))
		error_map(map->name, "map walls not closed!");
	lst_clear(maparr);
	return (map);
}
