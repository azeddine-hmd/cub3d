/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:04:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/04 20:20:36 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#define EXTENSION_ERR "map extension is not cub!"

/*
** check map file name extension is 'cub'
*/

void	check_file_extension(const char *file_name)
{
	int		ext_index;

	ext_index = ft_strlen(file_name) - 3;
	if (ft_strcmp(file_name + ext_index, "cub"))
		error_map(file_name, EXTENSION_ERR);
}
