/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:07:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 15:07:38 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

t_data	*newdata(void *data)
{
	t_data	*node;

	if (!data)
		return (NULL);
	if (!(node = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	add(t_data **database, void *data)
{
	t_data	*node;

	if (!data)
		error();
	if (!(node = newdata(data)))
	{
		lstclear(database);
		exit(1);
	}
	lstadd_back(&database, node);
}


void		error(t_data *database)
{
	lstclear(database);
	exit(1);
}
void		finish(t_data *database)
{
	lstclear(database);
	exit(0);
}
