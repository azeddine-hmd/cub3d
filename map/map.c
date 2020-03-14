/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 23:25:31 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/14 18:42:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			*get_mlx(void)
{
	static void	*mlx;

	if (!mlx)
		mlx = mlx_init();
	return (mlx);
}

static t_map	*new_map(void)
{
	t_map	*map;

	map = (t_map*)xmalloc(sizeof(t_map));
	map->name = NULL;
	map->height = -1;
	map->width = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->s = NULL;
	map->frgb[0] = -1;
	map->frgb[1] = -1;
	map->frgb[2] = -1;
	map->crgb[0] = -1;
	map->crgb[1] = -1;
	map->crgb[2] = -1;
	map->maparr = NULL;
	map->map_width = 0;
	map->map_size = 0;
	return (map);
}

static t_localmap	*init_localmap()
{
	t_localmap	*localmap;

	localmap = (t_localmap*)xmalloc(sizeof(t_localmap));
	localmap->map = new_map();
	localmap->line = NULL;
	localmap->fd = -1;
	localmap->line_end = 1;
	localmap->strings = NULL;
	localmap->i = -1;
	localmap->maparr = NULL;
	localmap->map_time = 0;
	localmap->map_reached = 0;
	localmap->player_state = 0;
	localmap->id_count = 0;
	return (localmap);
}

t_map			*read_map(const char *file_name)
{
	t_localmap	*localmap;

	localmap = init_localmap();
	localmap->map->name = xstrdup(file_name);
	if ((localmap->fd = open(file_name, O_RDONLY)) == -1)
		error();
	while (localmap->line_end)
	{
		if ((localmap->line_end = get_next_line(localmap->fd,
						&(localmap->line))) == -1)
			error();
		add(get_head_node(), localmap->line);
		localmap->strings = ft_split(localmap->line, ' ');
		add_double_pointer(localmap->strings);
		while ((localmap->strings)[++(localmap->i)])
		{
			if (!ft_strcmp((localmap->strings)[localmap->i], "R"))
			{
				fill_r(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "NO"))
			{
				fill_no(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp(localmap->strings[localmap->i], "SO"))
			{
				fill_so(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "WE"))
			{
				fill_we(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "EA"))
			{
				fill_ea(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "S"))
			{
				fill_s(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "F"))
			{
				fill_f(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else if (!ft_strcmp((localmap->strings)[localmap->i], "C"))
			{
				fill_c(localmap->map,
						(const char**)(localmap->strings + localmap->i + 1));
				(localmap->id_count)++;
				break ;
			}
			else
			{
				localmap->map_time = 1;
				break ;
			}
		}
		if (localmap->map_time)
			break ;
		xfree(localmap->line);
	}
	xfree_double_pointer(localmap->strings);
	check_allfilled(localmap->map);
	if (localmap->id_count > 8)
		error_map(localmap->map->name, "repeated identifier.");
	if (*(localmap->line) != '\0')
		fill_map(localmap->map, &(localmap->maparr),
				(const char*)localmap->line, &(localmap->player_state));
	xfree(localmap->line);
	while (localmap->line_end)
	{
		if ((localmap->line_end = get_next_line(localmap->fd,
						&(localmap->line))) == -1)
			error();
		add(get_head_node(), localmap->line);
		if (!localmap->map_reached && *(localmap->line) == '\0')
			continue ;
		localmap->map_reached = 1;
		fill_map(localmap->map, &(localmap->maparr),
				(const char*)localmap->line, &(localmap->player_state));
		xfree(localmap->line);
	}
	if (localmap->player_state > 1)
		error_map(localmap->map->name, "found multiple players.");
	if (localmap->player_state < 1)
		error_map(localmap->map->name, "no player in the map.");
	if (!is_map_walls_closed(localmap->map, localmap->maparr))
		error_map(localmap->map->name, "map walls not closed!");
	fill_maparr(localmap->map, localmap->maparr);
	lst_clear(localmap->maparr);
	return (localmap->map);
}
