/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/14 17:30:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_ea(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumment in ea texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if ((img->d = mlx_xpm_file_to_image(
						get_mlx(), (char*)strings[i], &(img->w), &(img->h))))
		{
			map->ea = img;
			return ;
		}
		else
			error_map(map->name, "bad path to east texture.");
	}
}

void		fill_s(t_map *map, const char **strings)
{
	t_image *img;
	int		i;

	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumment in s texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if ((img->d = mlx_xpm_file_to_image(
						get_mlx(), (char*)strings[i], &(img->w), &(img->h))))
		{
			map->s = img;
			return ;
		}
		else
			error_map(map->name, "bad path to sprite texture.");
	}
}

static void	rgbstr_to_rgbint(int *rgbint, char *rgbstr, t_map *map)
{
	char	**rgbarr;
	int		i;

	if (!rgbstr)
		return ;
	rgbarr = ft_split(rgbstr, ',');
	add_double_pointer(rgbarr);
	if (!have_strings((const char**)rgbarr, 3))
		error_map(map->name,
				"found less or more than 3 argumments in rgb color.");
	i = -1;
	while (rgbarr[++i])
	{
		if ((rgbint[i] = atoi(rgbarr[i])) < 0)
			error_map(map->name, "rgb color below 0.");
		if (rgbint[i] > 255)
			error_map(map->name, "rgb color bigger than 255.");
	}
	xfree_double_pointer(rgbarr);
}

void		fill_f(t_map *map, const char **strings)
{
	int		i;
	char	*frgb;

	i = -1;
	frgb = NULL;
	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumments in floor color.");
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], ","))
		{
			if (ft_countchar(strings[i], ',') != 2)
				error_map(map->name,
						"found less or more than two commas in floor rgb.");
			frgb = xstrdup(strings[i]);
		}
		else
			error_map(map->name, "bad floor color.");
	}
	rgbstr_to_rgbint(map->frgb, frgb, map);
	if (frgb)
		xfree(frgb);
}

void		fill_c(t_map *map, const char **strings)
{
	int		i;
	char	*crgb;

	i = -1;
	crgb = NULL;
	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumments in ceiling color.");
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if (ft_strstr(strings[i], ","))
		{
			if (ft_countchar(strings[i], ',') != 2)
				error_map(map->name,
						"found less or more than two commas in ceiling rgb.");
			crgb = xstrdup(strings[i]);
		}
		else
			error_map(map->name, "bad ceilling color.");
	}
	rgbstr_to_rgbint(map->crgb, crgb, map);
	if (!crgb)
		xfree(crgb);
}
