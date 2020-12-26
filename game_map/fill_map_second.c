/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/26 10:55:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_ea(t_map *map, const char **arglst, int ln)
{
	t_image	*img;
	int		i;

	if (length(arglst) != 1)
		error_line(ln,
				"found less or more than one argumment in EA identifier");
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
			error_line(ln, "invalid path argument in EA identifier");
		xfree((void*)arglst[i]);
	}
}

void		fill_s(t_map *map, const char **arglst, int ln)
{
	t_image *img;
	int		i;

	if (length(arglst) != 1)
		error_line(ln,
				"found less or more than one argumment in S identifier");
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
			error_line(ln, "invalid path argument in S identifier");
		xfree((void*)arglst[i]);
	}
}

static void	rgbstr_to_rgbint(int *rgbint, char *rgbstr, int ln)
{
	char	**rgbarr;
	int		i;

	if (!rgbstr)
		return ;
	rgbarr = ft_split(rgbstr, ',');
	add_double_pointer(rgbarr);
	if (length((const char **)rgbarr) != 3)
		error_line(ln,
				"found less or more than three argumments in rgb color");
	i = -1;
	while (rgbarr[++i])
	{
		if (!ft_isstrdigit(rgbarr[i]))
			error_line(ln, "invalid rgb color");
		if ((rgbint[i] = atoi(rgbarr[i])) < 0)
			error_line(ln, "rgb color below 0");
		if (rgbint[i] > 255)
			error_line(ln, "rgb color bigger than 255");
	}
	xfree_double_pointer(rgbarr);
}

void		fill_f(t_map *map, const char **arglst, int ln)
{
	int		i;
	char	*frgb;

	i = -1;
	frgb = NULL;
	if (length(arglst) != 1)
		error_line(ln,
				"found less or more than one argumments in floor color");
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if (ft_strstr(arglst[i], ","))
		{
			if (ft_countchar(arglst[i], ',') != 2)
				error_line(ln,
						"found less or more than two commas in floor rgb");
			frgb = xstrdup(arglst[i]);
		}
		else
			error_line(ln, "invalid floor color");
	}
	rgbstr_to_rgbint(map->frgb, frgb, ln);
	if (frgb)
		xfree(frgb);
}

void		fill_c(t_map *map, const char **arglst, int ln)
{
	int		i;
	char	*crgb;

	i = -1;
	crgb = NULL;
	if (length(arglst) != 1)
		error_line(ln,
				"found less or more than one argumments in ceiling color");
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if (ft_strstr(arglst[i], ","))
		{
			if (ft_countchar(arglst[i], ',') != 2)
				error_line(ln,
						"found less or more than two commas in ceiling rgb");
			crgb = xstrdup(arglst[i]);
		}
		else
			error_line(ln, "invalid ceilling color");
	}
	rgbstr_to_rgbint(map->crgb, crgb, ln);
	if (!crgb)
		xfree(crgb);
}
