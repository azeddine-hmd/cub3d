/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_methods_cp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:24:58 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/14 17:30:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_render(void)
{
	t_point p0;
	t_point p1;

	p0.x = player()->x * map()->minimap_scale;
	p0.y = player()->y * map()->minimap_scale;
	p1.x = p0.x + cosf(player()->rotation_angle) * TILE_SIZE * 2 * map()->minimap_scale;
	p1.y = p0.y + sinf(player()->rotation_angle) * TILE_SIZE * 2 * map()->minimap_scale;

	line(p0, p1, rgb(255, 0, 0));
	square(player()->x * map()->minimap_scale - 2, player()->y * map()->minimap_scale - 2, 4, rgb(255, 0, 0));
}
