/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:01:29 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/08 11:01:44 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

void	error(void)
{
	perror("Error\n");
	lst_clear(*get_head_node());
	exit(1);
}

void	error_message(const char *message)
{
	perror("Error\n");
	ft_putstr(message);
	ft_putstr("\n");
	lst_clear(*get_head_node());
	exit(1);
}

void	error_map(const char *file_name, const char *message)
{
	ft_putstr("Error\n");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(message);
	ft_putstr("\n");
	lst_clear(*get_head_node());
	exit(1);
}

void	finish(void)
{
	lst_clear(*get_head_node());
	exit(0);
}