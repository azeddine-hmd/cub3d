/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:59:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/08 06:22:27 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define ERROR_CL "less or more than two command line argumment have been found"

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
	input_handler();
	texture_init();
	play_song();
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		error_message(ERROR_CL);
	setup(argv[1]);
	game_loop();
	return (0);
}
