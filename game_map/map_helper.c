/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:32:28 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 20:00:53 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			*get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
	{
		mlx = mlx_init();
		if (!mlx)
			error("failed to initialize mlx");
	}
	return (mlx);
}

static t_map	**map_double(void)
{
	static t_map	*map;

	return (&map);
}

/*
** this function depends on 'map_init(map_name)' to function correctly.
*/

t_map			*map(void)
{
	return (*map_double());
}

void			map_init(const char *map_name)
{
	t_map **map;

	map = map_double();
	if (*map)
		error_message("map_init(): map already initialized");
	*map = read_map(map_name);
}
