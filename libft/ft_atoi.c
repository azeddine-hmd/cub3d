/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:49:26 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/26 05:49:31 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\v'
				|| str[i] == '\f' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		if ((result * signe) > 2147483647)
			return (-1);
		else if ((result * signe) < -2147483648)
			return (0);
		i++;
	}
	return ((int)(result * signe));
}
