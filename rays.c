/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:09:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 15:42:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	**rays(void)
{
	static t_ray **rays;

	if (!rays)
	{
		rays = (t_ray**)xmalloc(sizeof(t_ray*) * MAX_WINDOW_WIDTH);
		if (!rays)
			game_exit(1);
	}
	return (rays);
}

void	rays_init(void)
{
	int		col;
	t_ray	**rays_double;

	rays_double = rays();
	col = -1;
	while (++col < MAX_WINDOW_WIDTH)
		rays_double[col] = (t_ray*)xmalloc(sizeof(t_ray));
}
