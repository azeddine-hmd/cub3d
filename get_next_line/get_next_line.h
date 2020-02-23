/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <ahamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:07:54 by ahamdaou          #+#    #+#             */
/*   Updated: 2019/11/19 06:06:47 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	char			*buffer;
	struct s_list	*next;
	int				fd;
}				t_list;

t_list			*l_lstnew(int fd);
int				get_next_line(int fd, char **line);
char			*str_join(char *buffer, char *tmp, int read_return, int i);
int				have_a_newline(char *str);
char			*sub_str(char const *s, unsigned int start);
int				allocate_line(char **line, char **buffer);

#endif
