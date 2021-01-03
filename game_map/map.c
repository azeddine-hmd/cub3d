/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:45:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/03 16:03:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_double_pointer(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

int	is_information(char *info)
{
	char 	*new_info;
	int		exist;

	exist = 0;
	if (!ft_strncmp(freader.line, info, ft_strlen(info)))
		exist = 1;
	new_info = ft_strjoin(info, " ");
	if (!new_info)
		error();
	if (!ft_strncmp(freader.line, new_info, ft_strlen(new_info)))
	{
		exist = 2;
		if (freader.info_count != freader.max_info &&
				freader.line[ft_strlen(freader.line) - 1] == ' ')
			error_line(freader.ln, "space at the end of line");
		free(new_info);
		return (TRUE);
	}
	if (exist == 2)
		error_line(freader.ln, "no argumment specified");
	free(new_info);
	return (FALSE);
}

void	preparing_filling_r(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 2)
		error_line(freader.ln,
				"found less or more than two argumments in R identifier");
	fill_r(map, list[1], list[2]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_no(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumment in NO identifier");
	fill_no(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_so(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumment in WE identifier");
	fill_so(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_we(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumment in WE identifier");
	fill_we(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_ea(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumment in EA identifier");
	fill_ea(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_s(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumment in S identifier");
	fill_s(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}
void	preparing_filling_c(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumments in ceiling color");
	fill_c(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_f(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(freader.ln,
				"found less or more than one argumments in floor color");
	fill_f(map, list[1]);
	free_double_pointer(list);
	freader.info_count++;
}

void	filling_information(t_map *map)
{
	if (!freader.line[0])
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
	else if (freader.info_count != freader.max_info)
		error_message("missing identifier");
}

void reading_map(t_data **tmp_map)
{
	if (freader.map_state == MAP_STATE_READING && !(freader.line[0]))
	{
		freader.map_state = MAP_STATE_FINISHED;
		return ;
	}
	if (freader.map_state == MAP_STATE_FINISHED && freader.line[0])
		error_line(freader.ln, "map must be the last element");
	if (freader.map_state == MAP_STATE_PRIOR && !(freader.line[0]))
		return ;
	if (freader.map_state == MAP_STATE_PRIOR)
		freader.map_state = MAP_STATE_READING;
	fill_map(tmp_map);
	check_line_element(freader.line);
}

void	set_cols(t_map *map, t_data *tmp_map)
{
	int	col;

	map->cols = 0;
	while (tmp_map)
	{
		col = ft_strlen((char*)tmp_map->data);
		if (map->cols < col)
			map->cols = col;
		tmp_map = tmp_map->next;
	}
	map->map_width = map->cols * TILE_SIZE;
}

void	set_rows(t_map *map, t_data *tmp_map)
{
	map->rows = lst_size(tmp_map);
	map->map_height = map->rows * TILE_SIZE;
}

void	check_player_instance(void)
{
	if (freader.player_count == 0)
		error_message("no player have been found in the map");
	else if (freader.player_count > 1)
		error_message("multiple instance of player have been found");
}

void	joinmap(t_map *map, t_data *head)
{
	char *tmp_line;

	while (head)
	{
		tmp_line = (char*)head->data;
		map->maparr = xstrjoin(map->maparr, tmp_line);
		head = head->next;
	}
}

void	set_map_information(t_map *map, t_data *tmp_map)
{
	if (!tmp_map)
		error_message("map not found");
	set_cols(map, tmp_map);
	set_rows(map, tmp_map);
	map->num_rays = map->win_width;
	check_player_instance();
	if (!is_map_walls_closed(tmp_map, map->cols))
	{
		lst_clear(tmp_map);
		error_message("map is not surrounding with walls");
	}
	joinmap(map, tmp_map);
	set_initial_player_position(map);
	set_sp_initial_position(map);
}

static void	fill(t_map *map, int fd, int max_info)
{
	t_data	*tmp_map;
	int		eol;

	freader.ln = 1;
	freader.max_info = max_info;
	tmp_map = NULL;
	eol = 1;
	while(eol)
	{
		eol = get_next_line(fd, &freader.line);
		if (eol == -1)
			error();
		if (freader.info_count != freader.max_info)
			filling_information(map);
		else
			reading_map(&tmp_map);
		free(freader.line);
		freader.ln++;
	}
	set_map_information(map, tmp_map);
}

static void	map_initializer(t_map *map)
{
	int	i;

	ft_bzero(map, sizeof(t_map));
	map->win_name = "cub3d";
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
