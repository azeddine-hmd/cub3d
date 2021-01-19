/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:30:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/10 10:41:59 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int			check_element_surrounding(char element, t_direction dire)
{
	char	*message;

	message = xstrdup("please surround 'x' with walls");
	message[17] = element;
	if (dire.self == element && (dire.up == ' ' || dire.up == '\0' ||
							dire.right == ' ' || dire.right == '\0' ||
							dire.down == ' ' || dire.down == '\0' ||
							dire.left == ' ' || dire.left == '\0'))
	{
		error_message(message);
		xfree(message);
		return (0);
	}
	xfree(message);
	return (1);
}

static int			wall_conditions(t_direction dire)
{
	const char	*elements;
	int			i;

	if (dire.self == '1' || dire.self == ' ')
		return (1);
	elements = MAP_SURROUNDING;
	i = -1;
	while (elements[++i])
		if (!check_element_surrounding(elements[i], dire))
			return (0);
	return (1);
}

static void			norm(t_direction *dire, char *previous,
		char *current, int i)
{
	dire->self = current[i];
	if (!previous)
		dire->up = '\0';
	else
		dire->up = previous[i];
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
		norm(&dire, previous, current, i);
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
