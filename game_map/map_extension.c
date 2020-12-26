/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:04:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/26 09:23:09 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#define EXTENSION_ERR "map extension is not cub!"

/*
** check map file name extension is 'cub'
*/

void	check_file_extension(const char *file_name)
{
	int		dot_index;

	dot_index = ft_strlen(file_name) - 4;
	if (ft_strcmp(file_name + dot_index, ".cub"))
		error_message("file extension is not [.cub]");
}
