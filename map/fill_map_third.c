/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 03:27:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/05 09:53:57 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	set_map_width(t_map *map, const char *strings)
{
	int	strings_len;

	strings_len = ft_strlen(strings);
	if (map->map_width == 0)
		map->map_width = strings_len;
	else if (map->map_width < strings_len)
		map->map_width = strings_len;
}

void		fill_map(t_map *map, const char **strings, t_data **maparr)
{
	set_map_width(map, *strings);
	add(maparr, (void*)(*strings));
}
