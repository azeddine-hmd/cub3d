/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:01:29 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/31 11:17:22 by ahamdaou         ###   ########.fr       */
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
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}

void	error_map(const char *file_name, const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}

void	finish(void)
{
	lst_clear(*get_head_node());
	exit(0);
}

void	error_special(const char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	lst_clear(*get_head_node());
	exit(1);
}
