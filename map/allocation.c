/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:16:55 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 16:28:40 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:54:20 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 16:16:30 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	**getdatabase(void)
{
	static t_map	*database;

	return (&database);
}

void	*xmalloc(int size)
{
	void	*data;

	data = malloc(size);
	add(*getdatabase(), data);
	return (data);
}

static void		removedatanode(int fd, t_list **buffers)
{
	t_map	*tmp;
	t_map	*node;

	if (!*buffers)
		return ;
	if ((*buffers)->fd == fd)
	{
		if ((*buffers)->buffer)
			free((*buffers)->buffer);
		tmp = (*buffers);
		(*buffers) = (*buffers)->next;
		free(tmp);
		return ;
	}
	node = *buffers;
	return (l_lstremove_afterhead(fd, node));
}

static void		l_lstremove_afterhead(int fd, t_list *node)
{
	t_list	*tmp;
	t_list	*node_left;

	while (node->next)
	{
		if (node->next->fd == fd)
		{
			node_left = node;
			node = node->next;
			if (node->buffer)
				free(node->buffer);
			tmp = node;
			node = node->next;
			tmp->next = NULL;
			free(tmp);
			node_left->next = node;
			return ;
		}
		node = node->next;
	}
}
void	xfree(void *data)
{
	t_map	*database;
	t_map	*tmp;
	t_map	*node;

	database = *getdatabase();
	if (!data || !database)
		error("error in xfree() function");
	if (database->data = data)
	{
		free(data);
		tmp = database;
		database = database->next;
		free(tmp);
		return ;
	}
}
