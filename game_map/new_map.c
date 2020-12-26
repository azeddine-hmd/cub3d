/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:45:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/26 13:01:43 by ahamdaou         ###   ########.fr       */
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
				line[ft_strlen(freader.line) - 1] == ' ')
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
	fill_no(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_so(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_so(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_we(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_we(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_ea(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_ea(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_s(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_s(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}
void	preparing_filling_c(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_c(map, list + 1);
	free_double_pointer(list);
	freader.info_count++;
}

void	preparing_filling_f(t_map *map)
{
	char	**list;

	list = ft_split(freader.line, ' ');
	fill_f(map, list + 1);
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

void reading_map(char *line)
{
	//TODO: read map from freader.line
}

void	fill(t_map *map, int fd, int max_info)
{
	int		eol;

	freader.ln = 1;
	freader.max_info = max_info;
	eol = 1;
	while(eol)
	{
		eol = get_next_line(fd, &freader.line);
		if (eol == -1)
			error();
		if (freader.info_count != freader.max_info)
			filling_information(map);
		else
			reading_map(map);
		free(freader.line);
		freader.ln++;
	}
}

static void	map_initializer(t_map *map)
{
	ft_bzero(map, sizeof(t_map));
	map->minimap_scale = INITIAL_MINIMAP_SCALE;
	map->frgb[0] = UNITIALIZED_COLOR;
	map->frgb[1] = UNITIALIZED_COLOR;
	map->frgb[2] = UNITIALIZED_COLOR;
	map->crgb[0] = UNITIALIZED_COLOR;
	map->crgb[1] = UNITIALIZED_COLOR;
	map->crgb[2] = UNITIALIZED_COLOR;
}

t_map		*load_map(char *file_name, int max_info)
{
	t_map	*map;
	int		fd;

	check_file_extension(file_name);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_file("File doesn't exist");
	map = (t_map*)xmalloc(sizeof(t_map));
	map_initializer(map);
	fill(map, fd, max_info);
	exit(1); // remove it later
	return (map);
}
