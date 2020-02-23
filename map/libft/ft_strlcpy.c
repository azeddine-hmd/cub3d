/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <ahamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:32:15 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/26 08:56:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (size == 0)
		return (ft_strlen(src));
	if (!dst || !src)
		return (0);
	i = -1;
	while (++i < size - 1)
	{
		if (src[i] == '\0')
			break ;
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
