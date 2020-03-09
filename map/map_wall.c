/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:06:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/09 08:26:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_direction	*get_direction(void)
{
	t_direction	*dire;

	dire = (t_direction*)xmalloc(sizeof(t_direction));
	dire->up = '\0';
	dire->down = '\0';
	dire->left = '\0';
	dire->right = '\0';
	return (dire);
}

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
			line = (char*)malloc(map_width + 1);
			if (!line)
			{
				lst_clear(maparr);
				error();
			}
			ft_memset(line, 0, map_width + 1);
			ft_memmove(line, node->data, data_len);
			add_sp(line, data_len, map_width);
			free(node->data);
			node->data = line;
		}
		node = node->next;
	}
}

void				checking_walls(t_data *maparr)
{
	char	*previous;
	char	*current;
	char	*next;

	previous = NULL;
	while(maparr)
	{
		current = (char*)maparr->data;
		if (!maparr->next)
			next = NULL;
		else
			next = (char*)maparr->next->data;
		fill_directions(previous, current, next);
		previous = current;
		maparr = maparr->next;
	}
}

int					is_map_closed(t_map *map, t_data *maparr)
{
	t_direction *dire;

	dire = get_direction();
	fill_map_withspaces(maparr, map->map_width);
	checking_walls(maparr);
	return (1);
}
