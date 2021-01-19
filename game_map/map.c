/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:45:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 15:38:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	filling_information(t_map *map)
{
	if (!g_freader.line[0])
		return ;
	if (is_information("R"))
		preparing_filling_r(map);
	else if (is_information("NO"))
		preparing_filling_no(map);
	else if (is_information("SO"))
		preparing_filling_so(map);
	else if (is_information("WE"))
		preparing_filling_we(map);
	else if (is_information("EA"))
		preparing_filling_ea(map);
	else if (is_information("S"))
		preparing_filling_s(map);
	else if (is_information("C"))
		preparing_filling_c(map);
	else if (is_information("F"))
		preparing_filling_f(map);
	else if (g_freader.info_count != g_freader.max_info)
		error_message("missing identifier");
}

static void	reading_map(t_data **tmp_map)
{
	if (g_freader.map_state == MAP_STATE_READING && !(g_freader.line[0]))
	{
		g_freader.map_state = MAP_STATE_FINISHED;
		return ;
	}
	if (g_freader.map_state == MAP_STATE_FINISHED && g_freader.line[0])
		error_line(g_freader.ln, "map must be the last element");
	if (g_freader.map_state == MAP_STATE_PRIOR && !(g_freader.line[0]))
		return ;
	if (g_freader.map_state == MAP_STATE_PRIOR)
		g_freader.map_state = MAP_STATE_READING;
	fill_map(tmp_map);
	check_line_element(g_freader.line);
}

static void	fill(t_map *map, int fd, int max_info)
{
	t_data	*tmp_map;
	int		eol;

	g_freader.ln = 1;
	g_freader.max_info = max_info;
	tmp_map = NULL;
	eol = 1;
	while (eol)
	{
		eol = get_next_line(fd, &g_freader.line);
		if (eol == -1)
			error();
		if (g_freader.info_count != g_freader.max_info)
			filling_information(map);
		else
			reading_map(&tmp_map);
		free(g_freader.line);
		g_freader.ln++;
	}
	set_map_information(map, tmp_map);
}

static void	map_initializer(t_map *map)
{
	int	i;

	map->win_width = -1;
	map->win_height = -1;
	map->win_name = WINDOW_NAME;
	map->minimap_scale = INITIAL_MINIMAP_SCALE;
	i = -1;
	while (++i < 3)
	{
		map->frgb[i] = UNITIALIZED_COLOR;
		map->crgb[i] = UNITIALIZED_COLOR;
	}
}

t_map		*load_map(const char *file_name, int max_info)
{
	t_map	*map;
	int		fd;

	check_file_extension(file_name);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_file(file_name, "File doesn't exist");
	map = (t_map*)xmalloc(sizeof(t_map));
	map_initializer(map);
	fill(map, fd, max_info);
	close(fd);
	return (map);
}
