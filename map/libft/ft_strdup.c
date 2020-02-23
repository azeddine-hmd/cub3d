/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 08:56:08 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/31 14:41:01 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*memory;
	int		i;

	if (!s1)
		return (NULL);
	memory = (char*)ft_calloc(1, ft_strlen(s1) + 1);
	if (!memory)
		return (NULL);
	i = -1;
	while (s1[++i])
		memory[i] = s1[i];
	return (memory);
}
