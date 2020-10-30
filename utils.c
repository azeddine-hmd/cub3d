#include "cub3d.h"

int		rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	pixel_put(int x, int y, int color)
{
	int	*buffer;
	int	unused;

	if (!is_inside_window(x, y))
		return ;
	buffer = (int*)mlx_get_data_addr(vars()->img, &unused, &unused, &unused);
	buffer[x + y * map()->win_width] = color;
}

int		pixel_get(int x, int y, void *img, int txt_width, int txt_height)
{
	int	*buffer;
	int	unused;

	if (!is_inside_texture(x, y, txt_width, txt_height))
		return rgb(255, 0, 0);
	buffer = (int*)mlx_get_data_addr(img, &unused, &unused, &unused);
	return (buffer[x + y * txt_width]);
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

int		*cpy_int_arr(const int *arr, size_t size)
{
	int		*cpy;
	size_t	i;

	if (!(cpy = (int*)malloc(sizeof(int) * size)))
		exit(-1);
	i = -1;
	while (++i < size)
		cpy[i] = arr[i];
	return (cpy);
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
