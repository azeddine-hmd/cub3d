/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/22 03:33:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	fill_r_norm(t_map *map, const char **arglst, int i, int *position)
{
	if (ft_onlyspaces(arglst[i]))
		return ;
	if (*position == 1 && ft_isstrdigit(arglst[i]))
	{
		if ((map->win_width = atoi(arglst[i])) < MIN_WINDOW_WIDTH)
			map->win_width = MIN_WINDOW_WIDTH;
		if (map->win_width > MAX_WINDOW_WIDTH)
			map->win_width = MAX_WINDOW_WIDTH;
		(*position)++;
		return ;
	}
	else if (*position == 2 && ft_isstrdigit(arglst[i]))
	{
		if ((map->win_height = atoi(arglst[i])) < MIN_WINDOW_HEIGHT)
			map->win_height = MIN_WINDOW_HEIGHT;
		if (map->win_height > MAX_WINDOW_HEIGHT)
			map->win_height = MAX_WINDOW_HEIGHT;
	}
	else
		error_map(map->name, "nvalid resolution");
}

void		fill_r(t_map *map, const char **arglst)
{
	int		position;
	int		i;

	if (length(arglst) != 2)
		error_map(map->name,
				"found less or more than two argumments in resolution");
	position = 1;
	i = -1;
	while (arglst[++i])
	{
		fill_r_norm(map, arglst, i, &position);
	}
}

void		fill_no(t_map *map, const char **arglst)
{
	t_image	*img;
	int		i;

	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumment in 'NO' texture");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if ((img->img = mlx_xpm_file_to_image(
						get_mlx(), xstrdup(arglst[i]), &(img->w), &(img->h))))
		{
			map->no = img;
			return ;
		}
		else
			error_message("invalid path to north texture");
		xfree((void*)arglst[i]);
	}
}

void		fill_so(t_map *map, const char **arglst)
{
	t_image	*img;
	int		i;

	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumment in 'SO' texture");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if ((img->img = mlx_xpm_file_to_image(
						get_mlx(), xstrdup(arglst[i]), &(img->w), &(img->h))))
		{
			map->so = img;
			return ;
		}
		else
			error_map(map->name, "invalid south texture path");
		xfree((void*)arglst[i]);
	}
}

void		fill_we(t_map *map, const char **arglst)
{
	t_image	*img;
	int		i;

	if (length(arglst) != 1)
		error_map(map->name,
				"found less or more than one argumment in 'WE' texture");
	img = (t_image*)xmalloc(sizeof(t_image));
	i = -1;
	while (arglst[++i])
	{
		if (ft_onlyspaces(arglst[i]))
			continue ;
		if ((img->img = mlx_xpm_file_to_image(
						get_mlx(), xstrdup(arglst[i]), &(img->w), &(img->h))))
		{
			map->we = img;
			return ;
		}
		else
			error_map(map->name, "invalid west texture path");
		xfree((void*)arglst);
	}
}
