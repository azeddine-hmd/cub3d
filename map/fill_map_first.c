/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:04 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 11:12:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	fill_r(t_map *map, const char **strings)
{
	int		position;
	int		i;

	position = 1;
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (position == 1 && ft_isstrdigit(strings[i]))
		{
			map->width = atoi(strings[i]);
			position++;
			continue ;
		}
		else if (position == 2 && ft_isstrdigit(strings[i]))
		{
			map->height = atoi(strings[i]);
		}
		else
		{
			error_message("bad resolution!");
		}
	}
}

void	fill_no(t_map *map, const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], "/"))
		{
			map->no = xstrdup(strings[i]);
		}
		else
			error_message("bad path to north texture!");
	}
}

void	fill_so(t_map *map, const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], "/"))
		{
			map->so = xstrdup(strings[i]);
		}
		else
			error_message("bad path to south texture!");
	}
}

void	fill_we(t_map *map, const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], "/"))
		{
			map->we = xstrdup(strings[i]);
		}
		else
			error_message("bad path to west texture!");
	}
}
