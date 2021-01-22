/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:20:02 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** make sure calling this function after invoking first 'texture_init()'.
*/

t_txt	*gettxt(void)
{
	static t_txt	*txt;

	if (!txt)
	{
		txt = (t_txt*)xmalloc(sizeof(t_txt));
		if (!txt)
			game_exit(1);
	}
	return (txt);
}

void	texture_init(void)
{
	t_txt	*txt;

	txt = gettxt();
	txt->img = NULL;
	txt->width = 0;
	txt->height = 0;
}

void	settexture(t_ray *ray)
{
	t_txt	*txt;

	txt = gettxt();
	if (!ray->was_hit_vertical && ray->is_ray_facing_up)
		set_south_texture(txt);
	else if (!ray->was_hit_vertical && ray->is_ray_facing_down)
		set_north_texture(txt);
	else if (ray->was_hit_vertical && ray->is_ray_facing_left)
		set_east_texture(txt);
	else if (ray->was_hit_vertical && ray->is_ray_facing_right)
		set_west_texture(txt);
}

/*
** make sure to call this function after done work with textures.
*/

void	release_textures(void)
{
	mlx_destroy_image(vars()->mlx, g_game.no->img);
	mlx_destroy_image(vars()->mlx, g_game.so->img);
	mlx_destroy_image(vars()->mlx, g_game.we->img);
	mlx_destroy_image(vars()->mlx, g_game.ea->img);
}
