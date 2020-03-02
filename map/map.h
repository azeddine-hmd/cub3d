/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:28 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/02 03:37:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../linkedlist/linkedlist.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_map
{
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		frgb[3];
	int		crgb[3];
	char	*maparr;
	int		map_width;
}				t_map;

t_map			*read_map(const char *file_name);
void			fill_r(t_map *map, const char **strings);
void			fill_no(t_map *map, const char **strings);
void			fill_so(t_map *map, const char **strings);
void			fill_we(t_map *map, const char **strings);
void			fill_ea(t_map *map, const char **strings);
void			fill_s(t_map *map, const char **strings);
void			fill_f(t_map *map, const char **strings);
void			fill_c(t_map *map, const char **strings);

#endif
