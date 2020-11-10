/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:29:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/10 19:38:20 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			release_sprites(void)
{
	mlx_destroy_image(vars()->mlx, map()->s->img);
	lst_clear(map()->sp_head);
}
