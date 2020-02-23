/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:38:32 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/02/20 01:38:34 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct	s_map {
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		frgb[3];
	int		crgb[3];
	int		**arr;
}				t_map;

t_map		*read_map(char *file_name);
void		free_map(t_map *map);
void		free_strings(char **strings);
void		fill_r(t_map *map, char *line);
void		fill_no(t_map *map, char *line);
void		fill_so(t_map *map, char *line);
void		fill_we(t_map *map, char *line);
void		fill_ea(t_map *map, char *line);
void		fill_s(t_map *map, char *line);
void		fill_f(t_map *map, char *line);
void		fill_c(t_map *map, char *line);

#endif
