/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:04:42 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/28 12:38:56 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#define EXTENSION_ERR "map extension is not cub!"

/*
** check map file's name extension is 'cub'
*/

void	check_file_extension(const char *file_name)
{
	char	*extn;

	extn = ft_strrchr(file_name, '.') + 1;
	printf("extn = %s\n", extn);
	if (ft_strncmp(extn, "cub", fmax(ft_strlen(extn), 3)))
		error_message("file extension is not [.cub]");
}
