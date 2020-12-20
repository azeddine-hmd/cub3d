/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_binding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 00:43:16 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/18 00:45:25 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	collision_binding(int key)
{
	if (key == KEY_C)
	{
		if (game()->is_collision_enabled)
			game()->is_collision_enabled = FALSE;
		else
			game()->is_collision_enabled = TRUE;
	}
}
