/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:47:17 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/15 02:42:19 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	line(t_point p0, t_point p1, int color)
{
	int		dx;
	int		dy;
	float	steps;
	float	x_inc;
	float	y_inc;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (steps--)
	{
		pixel_put(p0.x, p0.y, color);
		p0.x += x_inc;
		p0.y += y_inc;
	}
}

void	square(float x, float y, float width, int color)
{
	int i;
	int j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < width)
		{
			pixel_put((x + j), (y + i), color);
			j++;
		}
		i++;
	}
}

void	rect(t_point p, int width, int height, int color)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			pixel_put((p.x + j), (p.y + i), color);
			j++;
		}
		i++;
	}
}
