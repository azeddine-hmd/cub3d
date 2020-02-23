/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 00:26:03 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/27 01:56:55 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	dst_len;
	int		src_len;
	int		j;

	dst_len = 0;
	src_len = 0;
	j = 0;
	if (!dst && size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= size)
		return (src_len + size);
	else
		res = src_len + dst_len;
	while (src[j] && dst_len < size - 1)
	{
		dst[dst_len] = src[j];
		dst_len++;
		j++;
	}
	dst[dst_len] = '\0';
	return (res);
}
