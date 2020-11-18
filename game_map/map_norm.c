/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 20:40:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/18 11:59:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
** function implementation is not human readable
** proceed carefully
** I'm too lazy to refactore it
*/

void		read_map_5(t_localmap *localmap)
{
	xfree_double_pointer(localmap->strings);
	check_allfilled(localmap->map);
	if (localmap->id_count > 8)
		error_map(localmap->map->name, "repeated identifier.");
	if (*(localmap->line) != '\0')
		fill_map(localmap->map, &(localmap->maparr),
				(const char*)localmap->line, &(localmap->player_state));
	xfree(localmap->line);
}

/*
** function implementation is not human readable
** proceed carefully
** I'm too lazy to refactore it
*/

void		read_map_6(t_localmap *localmap)
{
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
}
