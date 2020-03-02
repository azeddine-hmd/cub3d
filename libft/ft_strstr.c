/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 01:29:33 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 10:53:08 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_equality(const char *h, const char *n, int i)
{
	size_t	j;

	j = 0;
	while (n[j])
	{
		if (n[j] != h[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char		*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	int		position;
	size_t	len;

	len = ft_strlen(h);
	if (*n == '\0')
		return ((char*)h);
	if (len == 0)
		return (NULL);
	i = -1;
	position = -1;
	while (++i <= (len - ft_strlen(n)) && h[i])
		if (h[i] == n[0])
			if (check_equality(h, n, i))
			{
				position = i;
				break ;
			}
	if (position >= 0)
		return ((char*)&h[position]);
	return (NULL);
}
