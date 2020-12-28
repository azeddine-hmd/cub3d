/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:04:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 16:34:39 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/*
** check map file's name extension is 'cub'
*/

void	check_file_extension(const char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.') + 1;
	if (ft_strncmp(extension, "cub", fmax(ft_strlen(extension), 3)))
		error_file(file_name, "file extension is not 'cub'");
}
