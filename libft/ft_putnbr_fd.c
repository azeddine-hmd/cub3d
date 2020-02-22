/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:35:32 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/10/26 05:54:41 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	integer_length(int nb)
{
	int length;

	length = 1;
	while (nb / 10 != 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

static int	power_ten(int power)
{
	int result;

	result = 1;
	while (power > 0)
	{
		result = result * 10;
		power--;
	}
	return (result);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned	unb;
	int			length;
	int			tens;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb = -n;
	}
	else
		unb = n;
	length = integer_length(unb);
	tens = power_ten(length - 1);
	while (length != 0)
	{
		ft_putchar_fd((unb / tens) + '0', fd);
		unb = unb % tens;
		length--;
		tens /= 10;
	}
}
