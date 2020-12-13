/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:06:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/09 20:28:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_north_texture(t_txt *txt)
{
	txt->img = map()->no->img;
	txt->width = map()->no->w;
	txt->height = map()->no->h;
}

void	set_south_texture(t_txt *txt)
{
	txt->img = map()->so->img;
	txt->width = map()->so->w;
	txt->height = map()->so->h;
}

void	set_west_texture(t_txt *txt)
{
	txt->img = map()->we->img;
	txt->width = map()->we->w;
	txt->height = map()->we->h;
}

void	set_east_texture(t_txt *txt)
{
	txt->img = map()->ea->img;
	txt->width = map()->ea->w;
	txt->height = map()->ea->h;
}
