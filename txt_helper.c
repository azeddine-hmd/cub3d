/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txt_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:06:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 12:20:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_north_texture(t_txt *txt)
{
	txt->img = g_game.no->img;
	txt->width = g_game.no->w;
	txt->height = g_game.no->h;
}

void	set_south_texture(t_txt *txt)
{
	txt->img = g_game.so->img;
	txt->width = g_game.so->w;
	txt->height = g_game.so->h;
}

void	set_west_texture(t_txt *txt)
{
	txt->img = g_game.we->img;
	txt->width = g_game.we->w;
	txt->height = g_game.we->h;
}

void	set_east_texture(t_txt *txt)
{
	txt->img = g_game.ea->img;
	txt->width = g_game.ea->w;
	txt->height = g_game.ea->h;
}
