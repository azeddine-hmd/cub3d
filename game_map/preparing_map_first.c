/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_map_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:50:25 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/20 17:45:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	preparing_filling_r(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 2)
		error_line(g_freader.ln,
				"found less or more than two argumments in R identifier");
	fill_r(map, list[1], list[2]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_no(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumment in NO identifier");
	fill_no(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_so(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumment in WE identifier");
	fill_so(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_we(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumment in WE identifier");
	fill_we(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_ea(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumment in EA identifier");
	fill_ea(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}
