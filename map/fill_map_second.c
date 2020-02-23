#include "map.h"

void		fill_ea(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		ea_exist;

	strings = ft_split(line, ' ');
	ea_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "EA", 3))
			ea_exist = 1;
		if (ea_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
			map->ea = strings[i];
	}
}

void		fill_s(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		s_exist;

	strings = ft_split(line, ' ');
	s_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "S", 3))
			s_exist = 1;
		if (s_exist && ft_strnstr(strings[i], "/", ft_strlen(strings[i])))
			map->s = strings[i];
	}
}

void		rgbstr_to_rgbint(int *rgbint, char *rgbstr)
{
	char	**rgbarr;
	int		i;

	rgbarr = ft_split(rgbstr, ',');
	i = -1;
	while (rgbarr[++i])
		rgbint[i] = atoi(rgbarr[i]);
}

void		fill_f(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		f_exist;
	char	*frgb;

	strings = ft_split(line, ' ');
	f_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "F", 3))
			f_exist = 1;
		if (f_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
			frgb = strings[i];
	}
	if (f_exist)
		rgbstr_to_rgbint(map->frgb, frgb);
}

void		fill_c(t_map *map, char *line)
{
	char 	**strings;
	int		i;
	int		c_exist;
	char	*crgb;

	strings = ft_split(line, ' ');
	c_exist = 0;
	i = -1;
	while (strings[++i])
	{
		if (!ft_strncmp(strings[i], "C", 3))
			c_exist = 1;
		if (c_exist && ft_strnstr(strings[i], ",", ft_strlen(strings[i])))
			crgb = strings[i];
	}
	if (c_exist)
		rgbstr_to_rgbint(map->frgb, crgb);
}
