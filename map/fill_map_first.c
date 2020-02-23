#include "map.h"

void		fill_r(t_map *map, char *line)
{
	char	**strings;
	int		i;
	int		r_exist;
	int		pos;

	strings = ft_split(line, ' ');
	r_exist = 0;
	pos = 1;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "R", 2))
			r_exist = 1;
		if (r_exist && pos == 2 && ft_isstrdigit(strings[i]))
			map->height = atoi(strings[i]);
		if (r_exist && pos == 1 && ft_isstrdigit(strings[i]))
		{
			map->width = atoi(strings[i]);
			pos++;
		}
	}
}

void		fill_no(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		no_exist;

	strings = ft_split(line, ' ');
	no_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "NO", 3))
			no_exist = 1;
		if (no_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
			map->no = strings[i];
	}
}

void		fill_so(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		so_exist;

	strings = ft_split(line, ' ');
	so_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "SO", 3))
			so_exist = 1;
		if (so_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
			map->so = strings[i];
	}
}

void		fill_we(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		we_exist;

	strings = ft_split(line, ' ');
	we_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "WE", 3))
			we_exist = 1;
		if (we_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
			map->we = strings[i];
	}
}
