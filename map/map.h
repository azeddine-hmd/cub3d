/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:55:51 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/03/09 12:19:24 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../linkedlist/linkedlist.h"
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_image
{
	void	*d;
	int		w;
	int		h;
}				t_image;

typedef struct	s_map
{
	char	*name;
	int		height;
	int		width;
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	t_image	*s;
	int		frgb[3];
	int		crgb[3];
	char	*maparr;
	int		map_width;
	int		map_size;
}				t_map;

typedef struct	s_direction
{
	char	self;
	char	up;
	char	right;
	char	down;
	char	left;
}				t_direction;

void			*get_mlx(void);
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
int				is_map_walls_closed(t_map *map, t_data *maparr);
int				fill_directions(char *previous, char *current, char *next);

#endif
