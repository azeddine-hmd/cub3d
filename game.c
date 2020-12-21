/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/21 03:09:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** free and release game allocation from memory then exit
*/

void		game_exit(int signal)
{
	if (game()->is_audio_running)
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
	//mlx_clear_window(vars()->mlx, vars()->win);
	render_projection_walls();
	render_sprites();
	minimap_render();
	rays_render();
	minimap_sprite_render();
	player_render();
	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->img, 0, 0);
}
