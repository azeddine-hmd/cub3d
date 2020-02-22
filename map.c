#include "cub3d.h"

static t_map	*new_map()
{
	t_map	*map;
	int		i;

	map = (t_map*)malloc(sizeof(t_map));
	map->height = 0;
	map->width = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	i = 0;
	while (i < 3)
		map->frgb[i] = 255;
	i = 0;
	while (i < 3)
		map->crgb[i] = 255;
	map->frgb[]
	map->arr = NULL;
	return (map);
}

void			free_map(t_map *map)
{
	free(map);
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
		free(line);
	}
	return (map);
}
