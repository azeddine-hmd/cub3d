/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:54:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/05 09:54:25 by ahamdaou         ###   ########.fr       */
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

static int		check_map(const char **strings)
{
	int			i;
	int			j;
	const char	*str;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		str = strings[i];
		j = -1;
		while (str[++j])
		{
			if (str[j] != '0' && str[j] != '1' && str[j] != '2'
				&& str[j] != 'N' && str[j] != 'S' && str[j] != 'W'
				&& str[j] != 'E')
				return (0);
		}
	}
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
	t_data	*maparr;

	map = new_map();
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
		xfree(line);
		i = -1;
		while (strings[++i])
		{
			if (ft_onlyspaces(strings[i]))
				continue ;
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
				fill_c(map, (const char**)(strings + i + 1));
				break ;
			}
			else if (check_map((const char**)(strings + i)))
			{
				fill_map(map, (const char**)(strings + i), &maparr);
				break ;
			}
			else
				error_map(map->name, "bad formated!");
		}
	}
	xfree_double_pointer(strings);
	if (!is_map_closed(maparr))
		error_map(map->name, "walls are not closed!");
	return (map);
}
