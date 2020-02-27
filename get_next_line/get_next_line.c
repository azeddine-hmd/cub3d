/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:45 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 15:17:14 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		**get_fd_buffer(int fd, t_list **buffers)
{
	t_list	*head;

	if (!*buffers)
	{
		if (!(*buffers = l_lstnew(fd)))
			return (NULL);
		return (&((*buffers)->buffer));
	}
	head = *buffers;
	while (head->next)
	{
		if (head->fd == fd)
			return (&(head->buffer));
		head = head->next;
	}
	if (head->fd == fd)
		return (&(head->buffer));
	if (!(head->next = l_lstnew(fd)))
		return (NULL);
	return (&((head->next)->buffer));
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

static void		l_lstremove(int fd, t_list **buffers)
{
	t_list	*tmp;
	t_list	*node;

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

static int		line_allocation(t_list **bs, char **li, char **buf, int fd)
{
	int		line_return;

	if ((line_return = allocate_line(li, buf)) == -1)
		return (-1);
	else if (line_return == 2)
	{
		l_lstremove(fd, bs);
		if (!(*li = (char*)malloc(1)))
			return (-1);
		**li = '\0';
		return (0);
	}
	else if (line_return == 0)
	{
		l_lstremove(fd, bs);
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*buffers;
	char			**buffer;
	char			*tmp;
	char			*tmp_pointer;
	int				read_return;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = get_fd_buffer(fd, &buffers)))
		return (-1);
	if (!(tmp = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (!have_a_newline(*buffer))
	{
		if (!(read_return = read(fd, tmp, BUFFER_SIZE)) || read_return == -1)
			break ;
		tmp_pointer = *buffer;
		if (!(*buffer = str_join(*buffer, tmp, read_return, 0)))
			return (-1);
		free(tmp_pointer);
	}
	free(tmp);
	if (read_return == -1)
		return (-1);
	return (line_allocation(&buffers, line, buffer, fd));
}
