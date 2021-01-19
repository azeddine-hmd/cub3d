/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:07:20 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 15:50:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_binding(int key)
{
	if (key == KEY_EQUAL)
		change_win(game()->win_width + 10, game()->win_height + 10, "changed");
	else if (key == KEY_MINUS)
		change_win(game()->win_width - 10, game()->win_height - 10, "changed");
}

void	change_win(int width, int height, char *win_name)
{
	void	*new_win;
	void	*new_img;

	if (width < MIN_WINDOW_WIDTH || width > MAX_WINDOW_WIDTH ||
			height < MIN_WINDOW_HEIGHT || height > MAX_WINDOW_HEIGHT)
		return ;
	new_win = mlx_new_window(vars()->mlx, width, height, win_name);
	if (new_win == NULL)
		game_exit(1);
	new_img = mlx_new_image(vars()->mlx, width, height);
	if (new_img == NULL)
		game_exit(1);
	mlx_destroy_window(vars()->mlx, vars()->win);
	mlx_destroy_image(vars()->mlx, vars()->img);
	vars()->win = new_win;
	vars()->img = new_img;
	game()->win_width = width;
	game()->win_height = height;
	game()->win_name = win_name;
	game()->num_rays = width;
	render();
}
