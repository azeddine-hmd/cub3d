/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:06:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/14 13:50:46 by ahamdaou         ###   ########.fr       */
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

static void			fill_map_withspaces(t_data *maparr, int map_width)
{
	char	*line;
	int		data_len;
	t_data	*node;

	node = maparr;
	while (node)
	{
		data_len = ft_strlen((const char*)node->data);
		if (data_len != map_width)
		{
			line = (char*)xmalloc(map_width + 1);
			if (!line)
			{
				lst_clear(maparr);
				error();
			}
			ft_memset(line, 0, map_width + 1);
			ft_memmove(line, node->data, data_len);
			add_sp(line, data_len, map_width);
			xfree(node->data);
			node->data = line;
		}
		node = node->next;
	}
}

static int			walls_closed(t_data *maparr)
{
	char	*previous;
	char	*current;
	char	*next;

	previous = NULL;
	while (maparr)
	{
		current = (char*)maparr->data;
		if (!maparr->next)
			next = NULL;
		else
			next = (char*)maparr->next->data;
		if (!fill_directions(previous, current, next))
			return (0);
		previous = current;
		maparr = maparr->next;
	}
	return (1);
}

int					is_map_walls_closed(t_map *map, t_data *maparr)
{
	fill_map_withspaces(maparr, map->cols);
	if (!walls_closed(maparr))
		return (0);
	return (1);
}
