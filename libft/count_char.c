/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:40:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/30 12:40:05 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_char(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			counter++;
	return (counter);
}
