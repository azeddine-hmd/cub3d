/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:09:48 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 19:49:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	**rays(void)
{
	static t_ray **rays;

	if (!rays)
	{
		rays = (t_ray**)xmalloc(sizeof(t_ray*) * map()->num_rays);
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
	while (++col < map()->num_rays)
	{
		rays_double[col] = (t_ray*)xmalloc(sizeof(t_ray));
		ft_bzero(rays_double[col], sizeof(t_ray));
	}
}
