/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:00:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 10:08:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb_toint(int r, int g, int b)
{
	int	rgb;

	rgb = (r * pow(256, 2)) + (g * 256) + b;
	return (rgb);
}
