/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:55:50 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/30 18:15:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtoupper(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		if (ft_isalpha(s[i]))
			s[i] = ft_toupper(s[i]);
	return (s);
}
