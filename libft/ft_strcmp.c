/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:12:01 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 10:02:53 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
		{
			return (0);
		}
		else
		{
			return (((unsigned char)s1[i + 1]) - ((unsigned char)s2[i + 1]));
		}
	}
	return (0);
}
