/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:52:43 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/11/14 14:23:16 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H
# include <stdlib.h>
# include <stdio.h>
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
void			add_double_pointer(char **ptr);
void			xfree_double_pointer(char **ptr);
int				lst_size(t_data *head);

/*
** file: allocation.c
*/

t_data			**get_head_node(void);
void			*xmalloc(size_t size);
void			xfree(void *data);
char			*xstrdup(const char *s);
char			*xstrjoin(const char *s1, const char *s2);

/*
** file: error.c
*/

void			error();
void			error_message(const char *message);
void			finish();
void			error_map(const char *file_name, const char *message);
void			error_special(const char *message);


/*
** file: swap.c
*/

void	swap(t_data* this, t_data* other);

#endif
