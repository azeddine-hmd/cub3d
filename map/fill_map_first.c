/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/14 17:38:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	fill_r_norm(t_map *map, const char **strings, int i, int *position)
{
	if (ft_onlyspaces(strings[i]))
		return ;
	if (*position == 1 && ft_isstrdigit(strings[i]))
	{
		if ((map->width = atoi(strings[i])) < 100)
			map->width = 100;
		if (map->width > 2560)
			map->width = 2560;
		(*position)++;
		return ;
	}
	else if (*position == 2 && ft_isstrdigit(strings[i]))
	{
		if ((map->height = atoi(strings[i])) < 100)
			map->height = 100;
		if (map->height > 1440)
			map->height = 1440;
	}
	else
		error_map(map->name, "bad resolution.");
}

void		fill_r(t_map *map, const char **strings)
{
	int		position;
	int		i;

	if (!have_strings(strings, 2))
		error_map(map->name,
				"found less or more than 2 argumments in resolution.");
	position = 1;
	i = -1;
	while (strings[++i])
	{
		fill_r_norm(map, strings, i, &position);
	}
}

void		fill_no(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumment in no texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if ((img->d = mlx_xpm_file_to_image(
						get_mlx(), (char*)strings[i], &(img->w), &(img->h))))
		{
			map->no = img;
			return ;
		}
		else
			error_message("bad path to north texture.");
	}
}

void		fill_so(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumment in so texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if ((img->d = mlx_xpm_file_to_image(
						get_mlx(), (char*)strings[i], &(img->w), &(img->h))))
		{
			map->so = img;
			return ;
		}
		else
			error_map(map->name, "bad path to south texture.");
	}
}

void		fill_we(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

	if (!have_strings(strings, 1))
		error_map(map->name,
				"found less or more than one argumment in we texture.");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (strings[++i])
	{
		if (ft_onlyspaces(strings[i]))
			continue ;
		if ((img->d = mlx_xpm_file_to_image(
						get_mlx(), (char*)strings[i], &(img->w), &(img->h))))
		{
			map->we = img;
			return ;
		}
		else
			error_map(map->name, "bad path to west texture.");
	}
}
