/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:38:32 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/20 01:38:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h> //TODO: remove it
#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct	s_data
{
	void			*data;
	struct s_data	*next;
}				t_data;

void			lstadd_back(t_data **database, t_data *data);
void			lstclear(t_data *database);
void			add(t_data *database, void *data);
void			initdatabase(t_data **database);

#endif
