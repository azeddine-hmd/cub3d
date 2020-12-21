/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:13:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/21 22:45:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		length(const char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
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
