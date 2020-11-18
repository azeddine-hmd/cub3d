/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkedlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 20:36:37 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/16 14:53:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** [Description]:
** This function search the last data in the list,
** and return it.
**
** [Return Values]:
**  t_data*: the last node in the list.
**     NULL: if no node found in the list.
*/

t_data	*lst_last(t_data *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/*
** [Description]:
** This function add node to the front of the list.
*/

void	lst_add_front(t_data **head, t_data *node)
{
	if (*head)
		node->next = *head;
	else
		*head = node;
}

/*
** [Description]:
** This function add node to the list.
** if list is empty it add it in the front.
*/

void	lst_add_back(t_data **head, t_data *node)
{
	if (!*head)
		lst_add_front(head, node);
	else
		(lst_last(*head))->next = node;
}

/*
** [Description]:
** This function free node in the list.
** if node is NULL function will do nothing.
*/

void	free_node(t_data *node)
{
	if (!node)
		return ;
	free(node->data);
	node->data = NULL;
	node->next = NULL;
	free(node);
}

/*
** [Description]:
** This function clear all node in the list.
** if head is NULL function will do nothing.
*/

void	lst_clear(t_data *head)
{
	t_data	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head->next;
		free_node(head);
		head = tmp;
	}
}
