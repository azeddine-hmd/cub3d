/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:59:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 01:27:06 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** initialize game objects.
** Note: functions invokation order is essential otherwise game will crash.
*/

void	setup(const char *map_name)
{
	map_init(map_name);
	vars();
	rays_init();
	player();
	texture_init();
}

int		main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		print_usage();
		exit(1);
	}
	if (argc == 3 && check_option(argv[2], "--save"))
		take_screenshot(argv[1]);
	else if (argc == 3)
	{
		print_usage();
		exit(1);
	}
	if (argc == 2)
		run(argv[1]);
	return (0);
}
