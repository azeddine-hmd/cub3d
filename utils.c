#include "cub3d.h"

int		rgb_toint(int r, int g, int b)
{
	int	rgb;

	rgb = (r * pow(256, 2)) + (g * 256) + b;
	return (rgb);
}
