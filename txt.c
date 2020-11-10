/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:08:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 12:10:03 by ahamdaou         ###   ########.fr       */
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
			game_exit();
	}
	return (txt);
}

void			texture_init(void)
{
	t_txt	*txt;

	txt = gettxt();
	txt->img = NULL;
	txt->width = 0;
	txt->height = 0;
}

void			settexture(t_ray *ray)
{
	t_txt	*txt = NULL;

	txt = gettxt();
	if (!ray->was_hit_vertical && ray->is_ray_facing_up)
		set_north_texture(txt);
	else if (!ray->was_hit_vertical && ray->is_ray_facing_down)
		set_south_texture(txt);
	else if (ray->was_hit_vertical && ray->is_ray_facing_left)
		set_west_texture(txt);
	else if (ray->was_hit_vertical && ray->is_ray_facing_right)
		set_east_texture(txt);
}

/*
** make sure to call this function after done work with textures.
*/

void			release_textures(void)
{
	mlx_destroy_image(vars()->mlx, map()->no->img);
	mlx_destroy_image(vars()->mlx, map()->so->img);
	mlx_destroy_image(vars()->mlx, map()->we->img);
	mlx_destroy_image(vars()->mlx, map()->ea->img);
}
