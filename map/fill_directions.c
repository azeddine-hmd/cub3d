/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_directions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 08:30:52 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/09 09:03:23 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_direction	*get_directions(void)
{
	t_direction	*dire;

	dire = (t_direction*)xmalloc(sizeof(t_direction));
	dire->up = '\0';
	dire->down = '\0';
	dire->left = '\0';
	dire->right = '\0';
	return (dire);
}

int					fill_directions(char *previous, char* current, char *next)
{
	int			last_index;
	int			i;
	t_direction *dire;

	dire = get_directions();
	last_index = ft_strlen(current) - 1;
	i = -1;
	while (current[++i])
	{
		if (!previous)
			dire->up = '\0';
		else
			dire->up = previous[i];
		if (!next)
			dire->down = '\0';
		else
			dire->down = next[i];
		if (i == 0)
			dire->left = '\0';
		else
			dire->left = current[i - 1];
		if (i == last_index)
			dire->right = '\0';
		else
			dire->right = current[i + 1];
	}
	xfree(dire);
	return (1);
}
