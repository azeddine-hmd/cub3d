/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:32:28 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/02 16:56:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			*getmlx(void)
{
	static void	*mlx;

	if (!mlx)
	{
		mlx = mlx_init();
		if (!mlx)
			error_message("failed to initialize mlx");
	}
	return (mlx);
}

static t_map	**map_double(void)
{
	static t_map	*map;

	return (&map);
}

/*
** make sure to call map_init before calling this function
*/

t_map			*game(void)
{
	return (*map_double());
}

void			map_init(const char *map_name, int max_info)
{
	t_map **map;

	map = map_double();
	if (*map)
		error_message("double map initializition");
	*map = load_map(map_name, max_info);
}
