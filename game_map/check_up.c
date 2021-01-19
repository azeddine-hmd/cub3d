/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:56:09 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/17 12:35:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	joinmap(t_map *map, t_data *head)
{
	char *tmp_line;

	while (head)
	{
		tmp_line = (char*)head->data;
		map->maparr = xstrjoin(map->maparr, tmp_line);
		head = head->next;
	}
}

void	check_player_instance(void)
{
	if (g_freader.player_count == 0)
		error_message("no player have been found in the map");
	else if (g_freader.player_count > 1)
		error_message("multiple instance of player have been found");
}

int		is_information(char *info)
{
	char	*new_info;
	int		exist;

	exist = 0;
	if (!ft_strncmp(g_freader.line, info, ft_strlen(info)))
		exist = 1;
	new_info = xstrjoin(info, " ");
	if (!new_info)
		error();
	if (!ft_strncmp(g_freader.line, new_info, ft_strlen(new_info)))
	{
		exist = 2;
		if (g_freader.info_count != g_freader.max_info &&
				g_freader.line[ft_strlen(g_freader.line) - 1] == ' ')
			error_line(g_freader.ln, "space at the end of line");
		xfree(new_info);
		return (TRUE);
	}
	if (exist == 2)
		error_line(g_freader.ln, "no argumment specified");
	xfree(new_info);
	return (FALSE);
}
