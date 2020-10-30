/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:25:31 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/27 12:36:29 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		read_map_4(t_localmap *localmap)
{
	if (!ft_strcmp((localmap->strings)[localmap->i], "F"))
	{
		fill_f(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else if (!ft_strcmp((localmap->strings)[localmap->i], "C"))
	{
		fill_c(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else
	{
		localmap->map_time = 1;
		return (1);
	}
	return (0);
}

static int		read_map_3(t_localmap *localmap)
{
	if (!ft_strcmp((localmap->strings)[localmap->i], "WE"))
	{
		fill_we(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else if (!ft_strcmp((localmap->strings)[localmap->i], "EA"))
	{
		fill_ea(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else if (!ft_strcmp((localmap->strings)[localmap->i], "S"))
	{
		fill_s(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	return (0);
}

static int		read_map_2(t_localmap *localmap)
{
	if (!ft_strcmp((localmap->strings)[localmap->i], "R"))
	{
		fill_r(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else if (!ft_strcmp((localmap->strings)[localmap->i], "NO"))
	{
		fill_no(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	else if (!ft_strcmp(localmap->strings[localmap->i], "SO"))
	{
		fill_so(localmap->map,
				(const char**)(localmap->strings + localmap->i + 1));
		(localmap->id_count)++;
		return (1);
	}
	return (0);
}

static void		read_map_1(t_localmap *localmap)
{
	while (localmap->line_end)
	{
		if ((localmap->line_end = get_next_line(localmap->fd,
						&(localmap->line))) == -1)
			error();
		add(get_head_node(), localmap->line);
		localmap->strings = ft_split(localmap->line, ' ');
		add_double_pointer(localmap->strings);
		localmap->i = -1;
		while ((localmap->strings)[++(localmap->i)])
		{
			if (read_map_2(localmap))
				break ;
			if (read_map_3(localmap))
				break ;
			if (read_map_4(localmap))
				break ;
		}
		if (localmap->map_time)
			break ;
		xfree(localmap->line);
	}
}

t_map			*read_map(const char *file_name)
{
	t_localmap	*localmap;

	localmap = init_localmap();
	localmap->map->name = xstrdup(file_name);
	if ((localmap->fd = open(file_name, O_RDONLY)) == -1)
		error();
	read_map_1(localmap);
	read_map_5(localmap);
	read_map_6(localmap);
	if (localmap->player_state > 1)
		error_map(localmap->map->name, "found multiple players.");
	if (localmap->player_state < 1)
		error_map(localmap->map->name, "no player found in the map.");
	if (!is_map_walls_closed(localmap->map, localmap->maparr))
		error_map(localmap->map->name, "map walls not closed!");
	localmap->map->rows = lst_size(localmap->maparr);
	localmap->map->map_height = localmap->map->rows * TILE_SIZE;
	fill_maparr(localmap->map, localmap->maparr);
	set_map_information(localmap->map);
	lst_clear(localmap->maparr);
	return (localmap->map);
}
