/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/31 10:23:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_txt	**txts(void)
{
	static t_txt	**txts;

	if (!txts)
	{
		txts =
	}
	return (txts);
}

void	txt_init(void)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		//TODO:
	}
}

t_txt	*get_texture(t_ray *ray)
{

}

void	release_textures(void)
{
	mlx_destroy_image(vars()->mlx, map()->no->imgarr);
	mlx_destroy_image(vars()->mlx, map()->so->imgarr);
	mlx_destroy_image(vars()->mlx, map()->we->imgarr);
	mlx_destroy_image(vars()->mlx, map()->ea->imgarr);
}
