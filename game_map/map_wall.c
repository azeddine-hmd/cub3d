/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:06:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 16:46:28 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void			add_sp(char *line, unsigned int start, unsigned int end)
{
	while (start < end)
	{
		line[start] = ' ';
		start++;
	}
}

static void			fill_map_withspaces(t_data *tmp_map, int map_width)
{
	char	*line;
	int		data_len;
	t_data	*head;

	head = tmp_map;
	while (head)
	{
		data_len = ft_strlen((char*)head->data);
		if (data_len != map_width)
		{
			line = (char*)malloc(map_width + 1);
			if (!line)
			{
				lst_clear(tmp_map);
				error();
			}
			ft_memset(line, 0, map_width + 1);
			ft_memmove(line, head->data, data_len);
			add_sp(line, data_len, map_width);
			free(head->data);
			head->data = line;
		}
		head = head->next;
	}
}

static int			walls_closed(t_data *tmp_map)
{
	char	*previous;
	char	*current;
	char	*next;

	previous = NULL;
	while (tmp_map)
	{
		current = (char*)tmp_map->data;
		if (!tmp_map->next)
			next = NULL;
		else
			next = (char*)tmp_map->next->data;
		if (!fill_directions(previous, current, next))
			return (0);
		previous = current;
		tmp_map = tmp_map->next;
	}
	return (1);
}

int					is_map_walls_closed(t_data *tmp_map, int cols)
{
	fill_map_withspaces(tmp_map, cols);
	if (!walls_closed(tmp_map))
		return (0);
	return (1);
}
