/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:30:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/13 09:52:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int			wall_conditions(t_direction dire)
{
	if (dire.up == '\0' && dire.self == '0')
		return (0);
	if (dire.down == '\0' && dire.self == '0')
		return (0);
	if (dire.right == '\0' && dire.self == '0')
		return (0);
	if (dire.left == '\0' && dire.self == '0')
		return (0);
	if (dire.self == ' ' && (dire.up == '0' || dire.right == '0'
						|| dire.down == '0' || dire.left == '0'))
		return (0);
	return (1);
}

int					fill_directions(char *previous, char *current, char *next)
{
	t_direction dire;
	int			last_index;
	int			i;

	last_index = ft_strlen(current) - 1;
	i = -1;
	while (current[++i])
	{
		dire.self = current[i];
		if (!previous)
			dire.up = '\0';
		else
			dire.up = previous[i];
		if (!next)
			dire.down = '\0';
		else
			dire.down = next[i];
		if (i == 0)
			dire.left = '\0';
		else
			dire.left = current[i - 1];
		if (i == last_index)
			dire.right = '\0';
		else
			dire.right = current[i + 1];
		if (!wall_conditions(dire))
			return (0);
	}
	return (1);
}
