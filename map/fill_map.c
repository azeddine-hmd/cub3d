/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:13:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/11 12:06:29 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	fill_maparr(t_map *map, t_data *maparr)
{
	char	*temp;

	while (maparr)
	{
		temp = (char*)map->maparr;
		map->maparr = xstrjoin((char*)maparr->data, (char*)map->maparr);
		free(temp);
		maparr = maparr->next;
	}
	printf("map->maparr = '%s'\n", map->maparr);
}
