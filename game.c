/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/23 09:06:37 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_usage(void)
{
	ft_putstr_fd("Error\n"
			, 2);
	ft_putstr_fd("Usage: ./cub3D [map_path [--save]] [--maps map_path ...]\n"
			, 2);
	ft_putstr_fd("--save: take a screenshot and save it as bmp "
			, 2);
	ft_putstr_fd("in the project root directory\n"
			, 2);
	exit(1);
}

/*
** free and release game allocation from memory then exit
*/

void		game_exit(int signal)
{
	if (g_pref.is_audio_running)
		stop_audio();
	release_sprites();
	release_textures();
	mlx_destroy_image(vars()->mlx, vars()->img);
	mlx_destroy_window(vars()->mlx, vars()->win);
	lst_clear(*get_head_node());
	exit(signal);
}

/*
** update game states before rendring.
*/

static void	update(void)
{
	move_player();
	cast_all_rays();
	set_sprites_distance();
}

/*
** render game's graphics.
**
** Note: functions order is essential to determine which graphic should
** be rendered first otherwise window will be messy.
*/

void		render(void)
{
	update();
	render_projection_walls();
	render_sprites();
	minimap_render();
	rays_render();
	minimap_other_elements_render();
	player_render();
	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->img, 0, 0);
}
