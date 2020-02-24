/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:36:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/12/29 14:41:58 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** [Description]:
** This function search the last data in the list,
** and return it.
**
** [Return Values]:
**  t_lilst*: the last "data" in the list.
**      NULL: if no "data" found in the list.
*/

static t_data	*lstlast(t_data *data)
{
	if (!data)
		return (NULL);
	while (data->next)
		data = data->next;
	return (data);
}

/*
** [Description]:
** This function add "data" data to the front of the list.
*/

static void		lstadd_front(t_data **database, t_data *data)
{
	if (*database)
		data->next = *database;
	else
		*database = data;
}

/*
** [Description]:
** This function add data (node) to the list.
** if list is empty it add it in the front.
*/

void			ft_lstadd_back(t_data **database, t_data *data)
{
	if (!*database)
		lstadd_front(database, data);
	else
		(lstlast(*database))->next = data;
}

static void		lstremove(t_data *data)
{
	if (!data)
		return ;
	if (data->data)
		free(data->data);
	data->data = NULL;
	data->next = NULL;
}

void			lstclear(t_data *database)
{
	t_data	*tmp;

	while (database)
	{
		tmp = database->next;
		lstremove(database);
		database = tmp;
	}
}
