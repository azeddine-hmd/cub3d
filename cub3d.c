#include "cub3d.h"
#define MAP_NAME "map.cub"

int		main(void)
{
	t_map	*map;

	map = read_map(MAP_NAME);

	printf("width = %d\n", map->width);
	printf("height = %d\n", map->height);
	printf("NO = %s\n", map->no);
	printf("SO = %s\n", map->so);
	printf("WE = %s\n", map->we);
	printf("EA = %s\n", map->ea);
	printf("S = %s\n", map->s);

	for (int i = 0; i < 3; i++)
	{
		printf("frgb[%d] = %d\n", i, map->frgb[i]);
	}
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		printf("crgb[%d] = %d\n", i, map->frgb[i]);
	}

	return (0);
}
