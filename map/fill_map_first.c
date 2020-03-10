/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/09 13:10:49 by ahamdaou         ###   ########.fr       */
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
			map->height = atoi(strings[i]);
		else
			error_map(map->name, "bad resolution.");
	}
}

void	fill_no(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

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

void	fill_so(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

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

void	fill_we(t_map *map, const char **strings)
{
	t_image	*img;
	int		i;

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
