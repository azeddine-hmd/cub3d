/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/11 21:04:22 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>


void	translate_image()
{
	int		*img_adr;
	int		unused;
	int		x;
	int		y;

	vars()->fimg = mlx_new_image(vars()->mlx, map()->win_width, map()->win_height);
	img_adr = (int*)mlx_get_data_addr(vars()->fimg, &unused, &unused, &unused);
	y = -1;
	while (++y < map()->win_height)
	{
		x = -1;
		while (++x < map()->win_width)
		{
			if (y + player()->look >= 0 && y + player()->look < map()->win_height)
				img_adr[(y + player()->look) * map()->win_width + x] = get_window_color(x, y);
			else if (y + player()->look < map()->win_height / 2 && y + player()->look >= 0)
				img_adr[(y + player()->look) * map()->win_width + x]
					= rgb(map()->crgb[0], map()->crgb[1], map()->crgb[2]);
			else if (y + player()->look < map()->win_height)
				img_adr[(y + player()->look) * map()->win_width + x]
					= rgb(map()->frgb[0], map()->frgb[1], map()->frgb[2]);
		}
	}
}

/*
** free and release game allocation from memory then exit
*/

void	game_exit(int return_signal)
{
	system("killall mplayer");
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
	minimap_sprite_render();
	player_render();
	translate_image();
	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->fimg, 0, 0);
}
