/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:29:40 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/25 06:01:17 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		str_length;

	if (!s1 || !s2)
		return (NULL);
	str_length = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(str_length + 1)))
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j] != '\0')
		str[i++] = s1[j];
	j = -1;
	while (s2[++j] != '\0')
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
