/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:25:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/10 10:36:21 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		fill_ea(t_map *map, char *path)
{
	t_image	*img;

	if (map->ea != NULL)
		error_line(g_freader.ln, "duplicated EA identifier");
	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(g_freader.ln, "invalid path argument in EA identifier");
	map->ea = img;
}

void		fill_s(t_map *map, char *path)
{
	t_image *img;

	if (map->s != NULL)
		error_line(g_freader.ln, "duplicated S identifier");
	img = (t_image*)xmalloc(sizeof(t_image));
	img->img = mlx_xpm_file_to_image(getmlx(), path, &(img->w), &(img->h));
	if (img->img == NULL)
		error_line(g_freader.ln, "invalid path argument in S identifier");
	map->s = img;
}

int			char_counter(const char *s, char c)
{
	int i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i])
		if (s[i] == c)
			counter++;
	return (counter);
}

void		fill_f(t_map *map, char *rgb)
{
	char	**rgb_list;
	int		rgb_position;
	int		color;

	if (char_counter(rgb, ',') > 2)
		error_line(g_freader.ln, "found more than two commas");
	rgb_list = ft_split(rgb, ',');
	if (length(rgb_list) != 3)
		error_line(g_freader.ln,
				"found less or more than 3 rgb color in floor identifier");
	rgb_position = 0;
	while (rgb_list[rgb_position])
	{
		if (!is_str_digit(rgb_list[rgb_position]))
			error_line(g_freader.ln, "rgb color is not valid");
		color = ft_atoi(rgb_list[rgb_position]);
		if (color < 0 || color > 255)
			error_line(g_freader.ln, "rgb color is below 0 or bigger than 255");
		map->frgb[rgb_position] = color;
		rgb_position++;
	}
	free_double_pointer(rgb_list);
}

void		fill_c(t_map *map, char *rgb)
{
	char	**rgb_list;
	int		rgb_position;
	int		color;

	if (char_counter(rgb, ',') > 2)
		error_line(g_freader.ln, "found more than two commas");
	rgb_list = ft_split(rgb, ',');
	if (length(rgb_list) != 3)
		error_line(g_freader.ln,
				"found less or more than 3 rgb color in floor identifier");
	rgb_position = 0;
	while (rgb_list[rgb_position])
	{
		if (!is_str_digit(rgb_list[rgb_position]))
			error_line(g_freader.ln, "rgb color is not valid");
		color = ft_atoi(rgb_list[rgb_position]);
		if (color < 0 || color > 255)
			error_line(g_freader.ln, "rgb color is below 0 or bigger than 255");
		map->crgb[rgb_position] = color;
		rgb_position++;
	}
	free_double_pointer(rgb_list);
}
