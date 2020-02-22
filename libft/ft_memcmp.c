/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <ahamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:57:32 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/29 15:28:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_casted;
	unsigned char	*s2_casted;

	i = 0;
	s1_casted = (unsigned char *)s1;
	s2_casted = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_casted[i] != s2_casted[i])
			return (s1_casted[i] - s2_casted[i]);
		i++;
	}
	return (0);
}
