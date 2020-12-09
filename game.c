/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/09 13:30:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>


/*
** free and release game allocation from memory then exit
*/

void	game_exit(int return_signal)
{
	system("killall afplay");
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
	set_sprites_distance();
}

/*
** render game's graphics.
**
** Note: functions order is essential to determine which graphic should
** be rendered first otherwise window will be messy.
*/

void	render(void)
{
	update();
	mlx_clear_window(vars()->mlx, vars()->win);
	render_projection_walls();
	render_sprites();
	minimap_render();
	rays_render();
	player_render();

	// testing
	/*float scale = 8;
	for (int x = 0; x < map()->s->w * scale; x++) {
		for (int y = 0; y < map()->s->h * scale; y++) {



			float offset_x = f_mod(x / scale, map()->s->w * scale);
			float offset_y = f_mod(y / scale, map()->s->h * scale);
			int color = sprite_pixel_get(offset_x, offset_y);


			if (color == sprite_pixel_get(0, 0)) {
				continue ;
			}
			float x1 = x;
			float y1 = y;
			pixel_put(x1, y1, color);
		}
	}*/

	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->img, 0, 0);
}
