/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_third.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 03:27:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 03:42:59 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "map.h"

static int	check_map(const char *line)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (line[i] == ' ')
			continue ;
		printf("%s\n", line);
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E')
		{
			printf("\"%s\"\n", line);
			return (0);
		}
	}
	if (line[0] == '\0')
		return (0);
	return (1);
}

void		map_arr(t_map *map, const char **strings)
{
	check_line(strings);
	return (1);
}
