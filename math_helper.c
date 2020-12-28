/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:48:34 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 09:55:07 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

float	distance_between_points(t_point p1, t_point p2)
{
	float result;

	result = sqrt(
			(p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	return (result);
}

float	f_mod(float a, float b)
{
	return (a - (floor(a / b) * b));
}

void	setpoint(t_point *p, float x, float y)
{
	p->x = x;
	p->y = y;
}
