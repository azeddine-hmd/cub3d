/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:56:57 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 02:59:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	void			*data;
	struct s_data	*next;
}				t_data;

/*
** file: linkedlist.c
*/
t_data			*lst_last(t_data *node);
void			lst_add_front(t_data **head, t_data *node);
void			lst_add_back(t_data **head, t_data *node);
void			free_node(t_data *node);
void			lst_clear(t_data *head);

/*
** file: linkedlist_utils.c
*/
t_data			*new_node(void *data);
void			add(t_data **head, void *data);
void			**get_head_node(void);
void			*xmalloc(size_t size);
void			xfree(void *data);
char			*xstrdup(const char *s);

/*
** file: helpers.c
*/
void			error();
void			error_message(char *message);
void			finish();

#endif
