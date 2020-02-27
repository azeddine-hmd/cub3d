/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 21:32:28 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/27 12:09:16 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../linkedlist/linkedlist.h"
# include <stdlib.h>
# include <fcntl.h>
# define malloc(x) xmaloc(x);

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

t_map			*read_map(t_data *database, char *file_name);
void			error(t_data *database);
void			finish(t_data *database);
int				fill_r(t_data *database, t_map *map, char *line);
int				fill_no(t_data *database, t_map *map, char *line);
int				fill_so(t_data *database, t_map *map, char *line);
int				fill_we(t_data *database, t_map *map, char *line);
int				fill_ea(t_data *database, t_map *map, char *line);
int				fill_s(t_data *database, t_map *map, char *line);
int				fill_f(t_data *database, t_map *map, char *line);
int				fill_c(t_data *database, t_map *map, char *line);
int				map_arr(t_data *database, t_map *map, char *line);
void			*xmalloc(int size);

#endif
