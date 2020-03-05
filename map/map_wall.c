/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 04:18:46 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/05 09:56:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		is_map_closed(t_data *maparr)
{
	while (maparr->next)
	{
		printf("line = '%s'\n", (char*)maparr->data);
		maparr = maparr->next;
	}
	return (1);
}
