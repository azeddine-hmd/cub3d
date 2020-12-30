/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:56:53 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/30 11:50:28 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s && f)
	{
		if (!(newstr = (char*)malloc(ft_strlen(s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			newstr[i] = f(i, s[i]);
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
