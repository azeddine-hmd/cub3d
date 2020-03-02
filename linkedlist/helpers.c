/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:26:12 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 02:59:12 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void		error()
{
	ft_putstr("Error\n");
	lst_clear(*get_head_node());
	exit(1);
}

void		error_message(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	ft_putstr("\n");
	lst_clear(*get_head_node());
	exit(1);
}

void		finish()
{
	lst_clear(*get_head_node());
	exit(0);
}
