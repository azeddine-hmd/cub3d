#include "map.h"

static t_map	*new_map()
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->height = 0;
	map->width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->frgb[0] = 255;
	map->frgb[1] = 255;
	map->frgb[2] = 255;
	map->crgb[0] = 255;
	map->crgb[1] = 255;
	map->crgb[2] = 255;
	map->arr = NULL;
	return (map);
}

t_map			*read_map(char *file_name)
{
	char	*line;
	int		fd;
	int		line_end;
	t_map	*map;

	map = new_map();
	fd = open(file_name, O_RDONLY);
	line_end = 1;
	while (line_end)
	{
		line_end = get_next_line(fd, &line);
		fill_r(map, line);
		fill_no(map, line);
		fill_so(map, line);
		fill_we(map, line);
		fill_ea(map, line);
		fill_s(map, line);
		fill_f(map, line);
		fill_c(map, line);
	}
	return (map);
}
