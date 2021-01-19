/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_map_second.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:50:44 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/10 09:28:49 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	preparing_filling_s(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumment in S identifier");
	fill_s(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_c(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumments in ceiling color");
	fill_c(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}

void	preparing_filling_f(t_map *map)
{
	char	**list;

	list = ft_split(g_freader.line, ' ');
	if (length(list + 1) != 1)
		error_line(g_freader.ln,
				"found less or more than one argumments in floor color");
	fill_f(map, list[1]);
	free_double_pointer(list);
	g_freader.info_count++;
}
