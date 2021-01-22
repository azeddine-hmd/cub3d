/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/22 18:00:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_r(t_map *map, char *width, char *height)
{
	if (map->win_width != -1 || map->win_height != -1)
		error_line(g_freader.ln, "duplicated resolution");
	if (!is_str_digit(width))
		error_line(g_freader.ln, "invalid resolution width");
	if (!is_str_digit(height))
		error_line(g_freader.ln, "invalid resolution height");
	map->win_width = ft_atoi(width);
	if (map->win_width < MIN_WINDOW_WIDTH)
		map->win_width = MAX_WINDOW_WIDTH;
	if (map->win_width > MAX_WINDOW_WIDTH)
		map->win_width = MAX_WINDOW_WIDTH;
	map->win_height = ft_atoi(height);
	if (map->win_height < MIN_WINDOW_HEIGHT)
		map->win_height = MAX_WINDOW_HEIGHT;
	if (map->win_height > MAX_WINDOW_HEIGHT)
		map->win_height = MAX_WINDOW_HEIGHT;
}

void		fill_no(t_map *map, char *path)
{
	t_image	*img;

	if (map->no != NULL)
		error_line(g_freader.ln, "duplicated NO identifier");
	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(g_freader.ln, "invalid path arguemnt in NO idenfifier");
	map->no = img;
}

void		fill_so(t_map *map, char *path)
{
	t_image	*img;

	if (map->so != NULL)
		error_line(g_freader.ln, "duplicated SO identifier");
	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(g_freader.ln, "invalid path argument in SO identfier");
	map->so = img;
}

void		fill_we(t_map *map, char *path)
{
	t_image	*img;

	if (map->we != NULL)
		error_line(g_freader.ln, "duplicated WE identifier");
	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(g_freader.ln, "invalid path in WE identifier");
	map->we = img;
}
