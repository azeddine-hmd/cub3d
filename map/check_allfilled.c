/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_allfilled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 13:34:00 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/14 17:17:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_allfilled(t_map *map)
{
	if ((map->height) == -1)
		error_map(map->name, "resolution doesn't exist.");
	if (!(map->no))
		error_map(map->name, "north texture doesn't exist.");
	if (!(map->so))
		error_map(map->name, "south texture doesn't exist.");
	if (!(map->we))
		error_map(map->name, "west texture doesn't exist.");
	if (!(map->ea))
		error_map(map->name, "east texture doesn't exist.");
	if (!(map->s))
		error_map(map->name, "sprite texture doesn't exist.");
	if ((map->frgb)[0] == -1)
		error_map(map->name, "floor information doesn't exist.");
	if ((map->crgb)[0] == -1)
		error_map(map->name, "ceiling information doesn't exist.");
}
