/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:13 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/24 21:32:15 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		fill_ea(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		ea_exist;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	ea_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "EA", 3))
			ea_exist = 1;
		if (ea_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->ea = strings[i];
			return (1);
		}
	}
	return (0);
}

int		fill_s(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		s_exist;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	s_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "S", 3))
			s_exist = 1;
		if (s_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->s = strings[i];
			return (1);
		}
	}
	return (0);
}

static void		rgbstr_to_rgbint(t_data *database, int *rgbint, char *rgbstr)
{
	char	**rgbarr;
	int		i;

	rgbarr = ft_split(rgbstr, ',');
	add(database, rgbarr);
	i = -1;
	while (rgbarr[++i])
		add(database, rgbarr[i]);
	i = -1;
	while (rgbarr[++i])
		rgbint[i] = atoi(rgbarr[i]);
}

int		fill_f(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		f_exist;
	char	*frgb;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	f_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "F", 3))
			f_exist = 1;
		if (f_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
			frgb = strings[i];
	}
	if (f_exist)
	{
		rgbstr_to_rgbint(database, map->frgb, frgb);
		return (1);
	}
	return (0);
}

int		fill_c(t_data *database, t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		c_exist;
	char	*crgb;

	strings = ft_split(line, ' ');
	add(database, strings);
	i = -1;
	while (strings[++i])
		add(database, strings[i]);
	c_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "C", 3))
			c_exist = 1;
		if (c_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
			crgb = strings[i];
	}
	if (c_exist)
	{
		rgbstr_to_rgbint(database, map->frgb, crgb);
		return (1);
	}
	return (0);
}
