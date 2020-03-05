/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:54:06 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/05 02:54:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_ea(t_map *map, const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], "/"))
		{
			map->ea = xstrdup(strings[i]);
		}
		else
			error_message("bad path to east texture!");
	}
}

void		fill_s(t_map *map, const char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], "/"))
		{
			map->s = xstrdup(strings[i]);
		}
		else
			error_message("bad path to sprite texture!");
	}
}

static void	rgbstr_to_rgbint(int *rgbint, char *rgbstr)
{
	char	**rgbarr;
	int		i;

	rgbarr = ft_split(rgbstr, ',');
	add_double_pointer(rgbarr);
	i = -1;
	while (rgbarr[++i])
		rgbint[i] = atoi(rgbarr[i]);
	xfree_double_pointer(rgbarr);
}

void		fill_f(t_map *map, const char **strings)
{
	int		i;
	char	*frgb;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], ","))
		{
			frgb = xstrdup(strings[i]);
		}
		else
			error_message("bad floor color!");
	}
	rgbstr_to_rgbint(map->frgb, frgb);
	xfree(frgb);
}

void		fill_c(t_map *map, const char **strings)
{
	int		i;
	char	*crgb;

	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], ","))
		{
			crgb = xstrdup(strings[i]);
		}
		else
			error_message("bad ceilling color!");
	}
	rgbstr_to_rgbint(map->frgb, crgb);
	xfree(crgb);
}
