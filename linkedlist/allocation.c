/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 20:18:18 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 10:56:50 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** [Description]
** .
** [Return Values]
** void** (static): the list's head;
*/

void		**get_head_node(void)
{
	static t_data	*head;

	return ((void**)&head);
}

/*
** [Description]
** alloc data and add it to the list.
**
** [Return Values]
** void*: address of the first byte in allocated bytes.
*/

void		*xmalloc(size_t size)
{
	void	*data;

	data = malloc(size);
	add((t_data**)get_head_node(), data);
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
*/

void		xfree(void *data)
{
	t_data	*tmp;
	t_data	**head;

	head = (t_data**)get_head_node();
	if (!data || !*head)
		return ;
	if ((*head)->data == data)
	{
		tmp = (*head);
		*head = (*head)->next;
		free_node(tmp);
		return ;
	}
	if (xfree_after_head(*head, data))
		error_message("node to free not found!");
}

/*
** [Description]
** duplicate string in heap with xmalloc.
*/

char		*xstrdup(const char *s)
{
	char	*strdup;
	int		i;

	if (!s)
		return (NULL);
	strdup = (char*)xmalloc(ft_strlen(s) + 1);
	i = -1;
	while (s[++i])
		strdup[i] = s[i];
	strdup[i] = '\0';
	return (strdup);
}
