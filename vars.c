/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 03:13:07 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/17 14:09:57 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vars	*vars_init(void)
{
	t_vars *vars;

	vars = (t_vars*)xmalloc(sizeof(t_vars));
	vars->mlx = get_mlx();
	vars->win = mlx_new_window(
			vars->mlx, game()->win_width, game()->win_height, WINDOW_NAME);
	if (!vars->win)
		error_message("failed to initialize a new window");
	vars->img = mlx_new_image(vars->mlx, game()->win_width, game()->win_height);
	if (!vars->img)
		error_message("failed to initialize image buffer");
	return (vars);
}

/*
** before calling this function 'game()' should be invoked first.
*/

t_vars			*vars(void)
{
	static t_vars *vars;

	if (!vars)
		vars = vars_init();
	return (vars);
}
