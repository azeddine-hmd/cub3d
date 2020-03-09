/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:55:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/09 08:05:29 by ahamdaou         ###   ########.fr       */
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
	char	*name;
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
	int		map_size;
}				t_map;

typedef struct	s_direction
{
	char	up;
	char	right;
	char	down;
	char	left;
}				t_direction;

t_map			*read_map(const char *file_name);
void			fill_r(t_map *map, const char **strings);
void			fill_no(t_map *map, const char **strings);
void			fill_so(t_map *map, const char **strings);
void			fill_we(t_map *map, const char **strings);
void			fill_ea(t_map *map, const char **strings);
void			fill_s(t_map *map, const char **strings);
void			fill_f(t_map *map, const char **strings);
void			fill_c(t_map *map, const char **strings);
void			fill_map(t_map *map, t_data **maparr, const char *line);
int				is_map_closed(t_map *map, t_data *maparr);

#endif
