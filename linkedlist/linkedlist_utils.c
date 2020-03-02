/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:07:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 01:47:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** [Description]
** create new node with data in it.
**
** [Return Values]
** t_data*: a node with data in it.
** NULL: if data is NULL function returns NULL.
*/

t_data	*new_node(void *data)
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

/*
** [Description]
** add data to list.
** this function handles all errors.
*/

void	add(t_data **head, void *data)
{
	t_data	*node;

	if (!data)
		error(*get_head_node());
	if (!(node = new_node(data)))
		error(*get_head_node());
	lst_add_back(head, node);
}
