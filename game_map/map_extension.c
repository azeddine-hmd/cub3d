/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:04:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/20 18:29:00 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
** check map file's name extension is 'cub'
*/

void	check_file_extension(const char *file_name)
{
	if (ft_strlen(file_name) < 4)
		error_file(file_name, "invalid file name");
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".cub", 4))
		error_file(file_name, "file extension is not 'cub'");
}
