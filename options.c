/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:42:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 02:16:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_option(const char *option, const char *target)
{
	if (!ft_strncmp(target, option, fmax(ft_strlen(target), ft_strlen(option))))
		return (TRUE);
	return (FALSE);
}
