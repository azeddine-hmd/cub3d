/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:13:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/02 15:39:36 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	element_not_exist_error(char element)
{
	char *message;

	message = xstrdup("'x' is not valid map element");
	message[1] = element;
	error_line(freader.ln, message);
}

void		check_line_element(const char *line)
{
	const char	*elements;
	size_t 		i;

	elements = " NSWE012";
	i = -1;
	while (++i < ft_strlen(line))
	{
		if (ft_strchr("NSWE", line[i]))
			freader.player_count++;
		if (!ft_strchr(elements, line[i]))
			element_not_exist_error(line[i]);
	}
}

void		fill_map(t_data **tmp_map)
{
	char	*tmp_line;

	tmp_line = ft_strdup(freader.line);
	if (!tmp_line)
	{
		lst_clear(*tmp_map);
		error();
	}
	add(tmp_map, (void*)tmp_line);
}
