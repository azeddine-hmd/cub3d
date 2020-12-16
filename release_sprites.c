/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 04:09:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/16 04:10:03 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Make sure to call this function before game ends, otherwise memory leak.
** Deallocate sprites memory only if sprite's head is exists
** otherwise do nothing.
*/

void		release_sprites(void)
{
	if (map()->sp_head)
		lst_clear(map()->sp_head);
	mlx_destroy_image(vars()->mlx, map()->s->img);
}
