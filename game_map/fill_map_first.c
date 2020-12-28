/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 15:02:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_r(t_map *map, char *width, char *height)
{
	if (!ft_isstrdigit(width))
		error_line(freader.ln, "invalid resolution width");
	if (!ft_isstrdigit(height))
		error_line(freader.ln, "invalid resolution height");
	map->win_width = atoi(width);
	if (map->win_width < MIN_WINDOW_WIDTH)
		map->win_width = MIN_WINDOW_WIDTH;
	if (map->win_width > MAX_WINDOW_WIDTH)
		map->win_width = MAX_WINDOW_WIDTH;
	map->win_height = atoi(height);
	if (map->win_height < MIN_WINDOW_HEIGHT)
		map->win_height = MIN_WINDOW_HEIGHT;
	if (map->win_height > MAX_WINDOW_HEIGHT)
		map->win_height = MAX_WINDOW_HEIGHT;
}

void		fill_no(t_map *map, char *path)
{
	t_image	*img;

	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(freader.ln, "invalid path arguemnt in NO idenfifier");
	map->no = img;
}

void		fill_so(t_map *map, char *path)
{
	t_image	*img;

	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
			error_line(freader.ln, "invalid path argument in SO identfier");
	map->so = img;
}

void		fill_we(t_map *map, char *path)
{
	t_image	*img;

	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(freader.ln, "invalid path in WE identifier");
	map->we = img;
}
