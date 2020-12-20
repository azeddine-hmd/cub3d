/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:59:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/20 04:00:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** initialize game objects.
** Note: functions invokation order is essential otherwise game will crash.
*/

static void	setup(const char *map_name)
{
	map_init(map_name);
	vars();
	rays_init();
	player();
	texture_init();
}

int			main(int argc, char **argv)
{
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		setup(argv[1]);
		take_screenshot();
		game_exit(0);
	}
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_path> ['--save']\n", 2);
		ft_putstr_fd("--save: will take a screenshot then save it as bmp ", 2);
		ft_putstr_fd("file and store it in the current directory.", 2);
		game_exit(1);
	}
	setup(argv[1]);
	render();
	mlx_loop_hook(vars()->mlx, input_handler, NULL);
	mlx_loop(vars()->mlx);
	return (0);
}
