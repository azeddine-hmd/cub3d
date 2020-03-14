/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:13:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/14 17:39:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		have_strings(const char **strings, int count)
{
	int	i;

	i = -1;
	while (strings[++i])
		count--;
	if (count != 0)
		return (0);
	return (1);
}

void	fill_maparr(t_map *map, t_data *maparr)
{
	char	*temp;

	while (maparr)
	{
		temp = map->maparr;
		map->maparr = xstrjoin((char*)map->maparr, (char*)maparr->data);
		if (temp)
			xfree(temp);
		maparr = maparr->next;
	}
}
