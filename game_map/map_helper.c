/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 01:32:28 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/21 11:56:22 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			*getmlx(void)
{
	static void	*mlx;

	if (!mlx)
	{
		mlx = mlx_init();
		if (!mlx)
			error_message("failed to initialize mlx");
	}
	return (mlx);
}
