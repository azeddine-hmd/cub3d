#include "cub3d.h"

void		free_strings(char **strings,int dont_free)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		if (i == dont_free)
			continue;
		free(strings[i]);
	}
	free(strings);
}

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
	free_strings(strings, -1);
}

void		fill_no(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		no_exist;
	int		dont_free;

	strings = ft_split(line, ' ');
	no_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "NO", 3))
			no_exist = 1;
		if (no_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->no = strings[i];
			dont_free = i;
		}
	}
	free_strings(strings, dont_free);
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
		{
			map->so = strings[i];
			dont_free = i;
		}
	}
	free_strings(strings, dont_free);
}

void		fill_we(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		we_exist;
	int		dont_free;

	strings = ft_split(line, ' ');
	we_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "WE", 3))
			we_exist = 1;
		if (we_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->we = strings[i];
			dont_free = i;
		}
	}
	free_strings(strings, dont_free);
}
