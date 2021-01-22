/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:59:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:54:59 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** initialize game objects.
** Note: functions invokation order is essential otherwise game will crash.
*/

void	setup(const char *map_name)
{
	g_game = *load_map(map_name, MAX_INFO_MENDATORY);
	vars();
	rays_init();
	player();
	texture_init();
}

int		main(int argc, char **argv)
{
	activate_bonus();
	if (argc == 3 && check_option(argv[2], "--save"))
		take_screenshot(argv[1]);
	else if (g_bonus && argc > 2 && check_option(argv[1], "--maps"))
		multiple_level_setup(argc - 2, argv + 2);
	else if (argc == 2)
		run(argv[1]);
	else
		print_usage();
	return (0);
}
