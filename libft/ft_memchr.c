/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:26:36 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/14 15:49:56 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		c_casted;
	const char	*s_casted;

	i = 0;
	c_casted = (unsigned char)c;
	s_casted = (const char *)s;
	while (i < n)
	{
		if (s_casted[i] == c_casted)
			return ((void *)&s_casted[i]);
		i++;
	}
	return (0);
}
