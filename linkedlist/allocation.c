/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:51:33 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/05 03:45:46 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"

/*
** [Description]
** first call create static head.
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

/*
** [Description]
** join two strings and make new one with xmalloc.
*/

char		*xstrjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		i;
	int		j;

	if (!s1)
		return (xstrdup(s2));
	if (!s2)
		return (xstrdup(s1));
	joined = xmalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined[i++] = s2[j];
	joined[i] = '\0';
	return (joined);
}
