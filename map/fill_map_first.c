/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/24 21:32:06 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		fill_r(t_data *database, t_map *map, char *line)
{
	char	**strings;
	int		i;
	int		r_exist;
	int		pos;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	r_exist = 0;
	pos = 1;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "R", 2))
			r_exist = 1;
		if (r_exist && pos == 2 && ft_isstrdigit(strings[i]))
		{
			map->height = atoi(strings[i]);
			return (1);
		}
		if (r_exist && pos == 1 && ft_isstrdigit(strings[i]))
		{
			map->width = atoi(strings[i]);
			pos++;
		}
	}
	return (0);
}

int		fill_no(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		no_exist;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	no_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "NO", 3))
			no_exist = 1;
		if (no_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->no = strings[i];
			return (1);
		}
	}
	return (0);
}

int		fill_so(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		so_exist;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	so_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "SO", 3))
			so_exist = 1;
		if (so_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->so = strings[i];
			return (1);
		}
	}
	return (0);
}

int		fill_we(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		we_exist;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	we_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "WE", 3))
			we_exist = 1;
		if (we_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->we = strings[i];
			return (1);
		}
	}
	return (0);
}
