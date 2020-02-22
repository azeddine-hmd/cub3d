#include "cub3d.h"

void		fill_ea(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		ea_exist;
	int		dont_free;

	strings = ft_split(line, ' ');
	ea_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "EA", 3))
			ea_exist = 1;
		if (ea_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->ea = strings[i];
			dont_free = i;
		}
	}
	free_strings(strings, dont_free);
}

void		fill_s(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		s_exist;
	int		dont_free;

	strings = ft_split(line, ' ');
	s_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "S", 3))
			s_exist = 1;
		if (s_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
		{
			map->s = strings[i];
			dont_free = i;
		}
	}
	free_strings(strings, dont_free);
}

/*void		fill_f(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		f_exist;

	strings = ft_split(line, ' ');
	f_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "F", 3))
			f_exist = 1;
		if (f_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
			map->f = strings[i];
	}
	free_strings(strings);
}

void		fill_c(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		c_exist;

	strings = ft_split(line, ' ');
	c_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "C", 3))
			c_exist = 1;
		if (c_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
		{
			map->c = strings[i];
		}
	}
	free_strings(strings);
}*/
