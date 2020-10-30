/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/30 17:49:13 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	release_textures(void)
{
	mlx_destroy_image(vars()->mlx, map()->no->imgarr);
	mlx_destroy_image(vars()->mlx, map()->so->imgarr);
	mlx_destroy_image(vars()->mlx, map()->we->imgarr);
	mlx_destroy_image(vars()->mlx, map()->ea->imgarr);
}
