/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:13:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/30 12:51:13 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			check_line_element(t_map *map, const char *line)
{
	const char	*elements;
	int i;
	int	j;

	elements = "NSWE012";
	i = -1;
	while (++i < ft_strlen(line))
	{
		j = -1;
		while (++j < ft_strlen(elements))
		{
			//TODO: check if character is valid as map element.
			if (line[i] != elements[j])
			{

				return (0);
			}
		}
	}
	return (1);
}

void		fill_map(t_map *map, t_data **tmp_map)
{
	char	*tmp_line;

	tmp_line = ft_strdup(freader.line);
	if (!tmp_line)
	{
		lst_clear(*tmp_map);
		error();
	}
	set_cols(map, freader.line);
	add(tmp_map, (void*)tmp_line);
}
