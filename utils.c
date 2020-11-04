/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:12:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/04 18:24:56 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(int x, int y, int color)
{
	int	*buf;
	int	unused;

	if (!is_inside_window(x, y))
		return ;
	buf = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	buf[x + y * map()->win_width] = color;
}

int		pixel_get(int x, int y)
{
	int	*buf;
	int	unused;

	if (!is_inside_texture(x, y, gettxt()->width, gettxt()->height))
		return rgb(255, 0, 0);
	buf = (int*)mlx_get_data_addr(gettxt()->img, &unused, &unused, &unused);
	return (buf[x + y * gettxt()->width]);
}

void	line(t_point p0, t_point p1, int color)
{
	int	dx;
	int	dy;
	float	steps;
	float	x_inc;
	float	y_inc;
	float	i;

    dx = p1.x - p0.x;
    dy = p1.y - p0.y;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / steps;
    y_inc = dy / steps;
	i = -1;
	while (++i <= steps - 1)
	{
		pixel_put(p0.x, p0.y, color);
		p0.x += x_inc;
		p0.y += y_inc;
	}
}

void	square(int x, int y, int width, int color)
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

float	normalize_angle(float angle) {
    angle = remainder(angle, (2 * M_PI));
    if (angle < 0) {
        angle = (2 * M_PI) + angle;
    }
    return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	clear(int color)
{
	int x;
	int	y;

	x = -1;
	while (++x < map()->win_width)
	{
		y = -1;
		while (++y < map()->win_height)
			pixel_put(x, y, color);
	}
}

float	f_mod(float a, float b)
{
	return (a - (floor(a/b) * b));
}
