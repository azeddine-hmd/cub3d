/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/21 00:28:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_ea(t_map *map, const char **arglst)
{
	t_image	*img;
	int		i;

	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumment in 'EA' texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if ((img->img = mlx_xpm_file_to_image(
						get_mlx(), xstrdup(arglst[i]), &(img->w), &(img->h))))
		{
			map->ea = img;
			return ;
		}
		else
			error_map(map->name, "invalid path to east texture.");
		xfree((void*)arglst[i]);
	}
}

void		fill_s(t_map *map, const char **arglst)
{
	t_image *img;
	int		i;

	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumment in 'S' texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if ((img->img = mlx_xpm_file_to_image(
						get_mlx(), xstrdup(arglst[i]), &(img->w), &(img->h))))
		{
			map->s = img;
			return ;
		}
		else
			error_map(map->name, "invalid path to sprite texture.");
		xfree((void*)arglst[i]);
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
	if (length((const char **)rgbarr) != 3)
		error_map(map->name,
				"found less or more than three argumments in rgb color.");
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

void		fill_f(t_map *map, const char **arglst)
{
	int		i;
	char	*frgb;

	i = -1;
	frgb = NULL;
	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumments in floor color.");
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if (ft_strstr(arglst[i], ","))
		{
			if (ft_countchar(arglst[i], ',') != 2)
				error_map(map->name,
						"found less or more than two commas in floor rgb.");
			frgb = xstrdup(arglst[i]);
		}
		else
			error_map(map->name, "invalid floor color.");
	}
	rgbstr_to_rgbint(map->frgb, frgb, map);
	if (frgb)
		xfree(frgb);
}

void		fill_c(t_map *map, const char **arglst)
{
	int		i;
	char	*crgb;

	i = -1;
	crgb = NULL;
	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumments in ceiling color.");
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if (ft_strstr(arglst[i], ","))
		{
			if (ft_countchar(arglst[i], ',') != 2)
				error_map(map->name,
						"found less or more than two commas in ceiling rgb.");
			crgb = xstrdup(arglst[i]);
		}
		else
			error_map(map->name, "invalid ceilling color.");
	}
	rgbstr_to_rgbint(map->crgb, crgb, map);
	if (!crgb)
		xfree(crgb);
}
