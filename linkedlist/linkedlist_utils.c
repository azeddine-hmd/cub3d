/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:52:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 16:29:27 by ahamdaou         ###   ########.fr       */
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

	if (!data || !head)
		error();
	if (!(node = new_node(data)))
		error();
	lst_add_back(head, node);
}

/*
** [Description]
** add double pointers to the list.
*/

void	add_double_pointer(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		add(get_head_node(), ptr[i]);
	add(get_head_node(), ptr);
}

/*
** [Description]
** free double pointers
*/

void	xfree_double_pointer(char **ptr)
{
	int i;

	i = -1;
	while (ptr[++i])
		xfree(ptr[i]);
	xfree(ptr);
}

/*
** [Description]
** count size of nodes in the list.
**
** [Return Values]
** int: size of list.
*/

int		lst_size(t_data *head)
{
	int	size;

	if (!head)
		error_message("lst_size: list head is NULL");
	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}
