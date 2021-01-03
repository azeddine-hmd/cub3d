/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:21:20 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/02 15:24:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run(const char *map_name)
{
	setup(map_name);
	render();
	mlx_loop_hook(vars()->mlx, input_handler, NULL);
	mlx_loop(vars()->mlx);
}
