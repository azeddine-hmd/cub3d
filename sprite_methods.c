/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:29:35 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/14 14:08:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculating distance between player and sprites in map
*/

void	set_distance_sprites(void)
{
	t_data	*head;
	t_sp	*sp;

	head = map()->sp_head;
	if (!head)
		return ;
	while (head->next)
	{
		sp = (t_sp*)head->data;
		sp->dist = sqrt((sp->x - player()->x) * (sp->x - player()->x)
				+ (sp->y - player()->y) * (sp->y - player()->y));
		printf("dist = %f\n", sp->dist);
		head = head->next;
	}
}

void	render_sprite(void)
{
	t_data	*data;
	t_sp	*sprite;
	float	distance;

	data = map()->sp_head;
	while (data)
	{
		sprite = data->data;
		distance = sprite->dist;
		printf("distance = %f\n", distance);
		data = data->next;
	}
}

void	release_sprites(void)
{
	mlx_destroy_image(vars()->mlx, map()->s->img);
	lst_clear(map()->sp_head);
}
