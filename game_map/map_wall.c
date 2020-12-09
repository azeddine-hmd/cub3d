/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:06:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/09 14:11:28 by ahamdaou         ###   ########.fr       */
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
	t_data	*head;

	head = maparr;
	while (head)
	{
		data_len = ft_strlen((char*)head->data);
		if (data_len != map_width)
		{
			line = (char*)xmalloc(map_width + 1);
			if (!line)
			{
				lst_clear(maparr);
				error();
			}
			ft_memset(line, 0, map_width + 1);
			ft_memmove(line, head->data, data_len);
			add_sp(line, data_len, map_width);
			xfree(head->data);
			head->data = line;
		}
		head = head->next;
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
