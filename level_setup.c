/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:41:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/23 09:02:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		bonus_init(void)
{
	play_audio(1);
	g_pref.is_collision_enabled = TRUE;
}

static void	run_bonus(void)
{
	bonus_init();
	render();
	mlx_loop_hook(vars()->mlx, input_handler, NULL);
	mlx_loop(vars()->mlx);
}

void		multiple_level_setup(int total_maps, char **path_value)
{
	int	map_index;

	g_lvls = (t_map**)xmalloc(sizeof(t_map*) * total_maps);
	g_lvlinfo.max_level = total_maps;
	g_lvlinfo.current_level = 1;
	map_index = -1;
	while (++map_index < total_maps)
		g_lvls[map_index] = load_map(path_value[map_index], MAX_INFO_BONUS);
	g_game = *g_lvls[0];
	vars();
	rays_init();
	player_init();
	texture_init();
	run_bonus();
}
