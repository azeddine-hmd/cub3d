/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:06:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:01:41 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_north_texture(t_txt *txt)
{
	txt->img = game()->no->img;
	txt->width = game()->no->w;
	txt->height = game()->no->h;
}

void	set_south_texture(t_txt *txt)
{
	txt->img = game()->so->img;
	txt->width = game()->so->w;
	txt->height = game()->so->h;
}

void	set_west_texture(t_txt *txt)
{
	txt->img = game()->we->img;
	txt->width = game()->we->w;
	txt->height = game()->we->h;
}

void	set_east_texture(t_txt *txt)
{
	txt->img = game()->ea->img;
	txt->width = game()->ea->w;
	txt->height = game()->ea->h;
}
