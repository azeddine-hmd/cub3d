/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 14:48:23 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/16 03:11:52 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countchar(const char *s, char c)
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
