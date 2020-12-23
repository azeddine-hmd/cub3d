/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_activation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:49:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 03:43:33 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	activate_bonus(void)
{
	g_bonus = TRUE;
	play_audio(1);
	g_pref.is_collision_enabled = TRUE;
}
