/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:42:47 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/23 01:26:54 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_option(const char *option, const char *target)
{
	if (!ft_strncmp(target, option, ft_strlen(target)))
		return (TRUE);
	return (FALSE);
}
