/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:51:33 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 15:40:56 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** [Description]
** first create static head.
** after first call, function will return the exist list.
** [Return Values]
** void** (static): the list's head;
*/

t_data		**get_head_node(void)
{
	static t_data	*head;

	return (&head);
}

/*
** [Description]
** allocate data and add it to the list.
**
** [Return Values]
** void*: address of the first byte in allocated bytes.
*/

void		*xmalloc(size_t size)
{
	void	*data;

	data = malloc(size);
	ft_bzero(data, size);
	if (data == NULL)
		error();
	add(get_head_node(), data);
	return (data);
}

/*
** [Description]
** this function is helper for xfree() function below.
** free node if it exist after head.
**
** [Return Values]
** 0: everything went well.
** 1: node not found in the list.
*/

static int	xfree_after_head(t_data *node, void *data)
{
	t_data *tmp;
	t_data *node_left;

	while (node->next)
	{
		if (node->next->data == data)
		{
			node_left = node;
			tmp = node->next;
			node = node->next->next;
			free_node(tmp);
			node_left->next = node;
			return (0);
		}
		node = node->next;
	}
	return (1);
}

/*
** [Description]
** search for node that have data and free it.
** if data is NULL crash prgram.
*/

void		xfree(void *data)
{
	t_data	*tmp;
	t_data	**head;
	char	*tester;
	char	test;

	if (!data)
	{
		tester = (char*)data;
		test = *tester;
		test++;
	}
	head = (t_data**)get_head_node();
	if ((*head)->data == data)
	{
		tmp = (*head);
		*head = (*head)->next;
		free_node(tmp);
		return ;
	}
	xfree_after_head(*head, data);
}
