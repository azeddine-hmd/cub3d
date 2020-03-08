/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:06:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/08 11:22:06 by ahamdaou         ###   ########.fr       */
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

static void			fill_map_withspaces(t_data *head, int map_width)
{
	char	*line;
	int		data_len;

	while (head)
	{
		data_len = ft_strlen((const char*)head->data);
		if (data_len != map_width)
		{
			line = (char*)xmalloc(map_width + 1);
			ft_memset(line, 0, map_width + 1);
			ft_memmove(line, head->data, data_len);
			add_sp(line, data_len, map_width);
		}
		head = head->next;
	}
}

int					is_map_closed(t_map *map, t_data *current)
{
	t_direction *dire;

	dire = get_direction();
	fill_map_withspaces(current, map->map_width);
	return (1);
}
