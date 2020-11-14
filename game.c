/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/14 13:42:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>


/*
** free and release game allocation from memory then exit
*/

void	game_exit(int return_signal)
{
	release_sprites();
	release_textures();
	mlx_destroy_image(vars()->mlx, vars()->img);
	mlx_destroy_window(vars()->mlx, vars()->win);
	lst_clear(*get_head_node());
	exit(return_signal);
}

void	game_loop(void)
{
	render();
	mlx_loop(vars()->mlx);
}

/*
** update game states before rendring.
*/

static void	update(void)
{
	move_player();
	cast_all_rays();
	set_distance_sprites();
}

/*
** render game graphics.
**
** Note: functions order is essential to determine which graphic should
** be rendered first otherwise canvas will be messy.
*/

void	render(void)
{
	update();
	mlx_clear_window(vars()->mlx, vars()->win);
	render_projection_walls();
	minimap_render();
	rays_render();
	player_render();
	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->img, 0, 0);
}
