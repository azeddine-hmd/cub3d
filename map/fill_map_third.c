#include "map.h"

static int	check_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			continue ;
		printf("%s\n", line);
		if (line[i] != '0' && line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W'
			&& line[i] != 'E')
		{
			printf("\"%s\"\n", line);
			return (0);
		}
	}
	if (line[0] == '\0')
		return (0);
	return (1);
}

int		map_arr(t_data *database, t_map *map, char *line)
{
	char	*newline;

	check_map(line);
	printf("line = '%s'\n", line);
	map->maparr = ft_strdup(line);
	map->width = ft_strlen(line);
	add(database, map->maparr);
	newline = ft_strtrim(line, " ");
	printf("newline = '%s'\n\n", newline);

	add(database, newline);
	return (1);
}
