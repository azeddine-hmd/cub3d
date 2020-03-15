/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:22:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/15 00:24:42 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void		*get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

t_map		*new_map(void)
{
	t_map	*map;

	map = (t_map*)xmalloc(sizeof(t_map));
	map->name = NULL;
	map->height = -1;
	map->width = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->frgb[0] = -1;
	map->frgb[1] = -1;
	map->frgb[2] = -1;
	map->crgb[0] = -1;
	map->crgb[1] = -1;
	map->crgb[2] = -1;
	map->maparr = NULL;
	map->map_width = 0;
	map->map_size = 0;
	return (map);
}

t_localmap	*init_localmap(void)
{
	t_localmap	*localmap;

	localmap = (t_localmap*)xmalloc(sizeof(t_localmap));
	localmap->map = new_map();
	localmap->line = NULL;
	localmap->fd = -1;
	localmap->line_end = 1;
	localmap->strings = NULL;
	localmap->i = -1;
	localmap->maparr = NULL;
	localmap->map_time = 0;
	localmap->map_reached = 0;
	localmap->player_state = 0;
	localmap->id_count = 0;
	return (localmap);
}
