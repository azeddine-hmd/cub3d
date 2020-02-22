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
	printf("F = %s\n", map->f);
	printf("C = %s\n", map->c);

	free_map(map);
	return (0);
}
