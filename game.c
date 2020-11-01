/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 12:49:10 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/31 12:50:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <time.h>

void	game_exit(void)
{
	puts("\nshutting down game...\n");
	release_textures();
	mlx_destroy_image(vars()->mlx, vars()->img);
	mlx_destroy_window(vars()->mlx, vars()->win);
	finish();
	exit(0);
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
}

/*
** render game graphics.
**
** Note: functions order is essential to determine which graphic should
** be rendered first otherwise canvas will be messy.
*/

void	render(void)
{
	// DEBUG: measure clocks times.
	clock_t start = clock();


	int memsize = lst_size(*get_head_node());
	printf("memsize = %d\n", memsize);

	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("seconds = %f\n", seconds);

	update();
	mlx_clear_window(vars()->mlx, vars()->win);
	render_projection_walls();


	minimap_render();
	rays_render();
	player_render();
	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->img, 0, 0);
}
