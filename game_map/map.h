/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:18:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/22 05:15:43 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../linkedlist/linkedlist.h"
# include <math.h>
# include <fcntl.h>
# include <float.h>
# include <mlx.h>

# define WINDOW_NAME "cub3d"
# define TILE_SIZE 64
# define MAX_WINDOW_WIDTH 2560
# define MAX_WINDOW_HEIGHT 1440
# define MIN_WINDOW_WIDTH 500
# define MIN_WINDOW_HEIGHT 500
# define TRUE 1
# define FALSE 0

typedef struct	s_vars
{
	void *mlx;
	void *win;
	void *img;
}				t_vars;

typedef struct	s_image
{
	void	*img;
	int		w;
	int		h;
}				t_image;

typedef struct	s_map
{
	char	*name;
	int		win_height;
	int		win_width;
	int		map_width;
	int		map_height;
	int		cols;
	int		rows;
	int		num_rays;
	float	minimap_scale;
	char	pview;
	int		is_minimap_enabled;
	int		is_collision_enabled;
	int		is_audio_running;
	int		is_slide_enabled;
	int		initial_pos[2];
	t_data	*sp_head;
	t_image	*no;
	t_image	*so;
	t_image	*we;
	t_image	*ea;
	t_image	*s;
	int		frgb[3];
	int		crgb[3];
	char	*maparr;
}				t_map;

typedef struct	s_direction
{
	char	self;
	char	up;
	char	right;
	char	down;
	char	left;
}				t_direction;

typedef struct	s_sp
{
	float	x;
	float	y;
	float	dist;
}				t_sp;

typedef struct	s_localmap
{
	t_map	*map;
	char	*line;
	int		fd;
	int		line_end;
	char	**strings;
	int		i;
	t_data	*maparr;
	int		map_time;
	int		map_reached;
	int		player_state;
	int		id_count;
}				t_localmap;

/*
** file: map.c
*/

t_map			*read_map(const char *file_name);

/*
** file: fill_map_first.c
*/

void			fill_r(t_map *map, const char **arglst);
void			fill_no(t_map *map, const char **arglst);
void			fill_so(t_map *map, const char **arglst);
void			fill_we(t_map *map, const char **arglst);

/*
** file: fill_map_second.c
*/

void			fill_ea(t_map *map, const char **arglst);
void			fill_s(t_map *map, const char **arglst);
void			fill_f(t_map *map, const char **arglst);
void			fill_c(t_map *map, const char **arglst);

/*
** file: fill_map_third.c
*/

void			fill_map(t_map *map, t_data **maparr, const char *line, int *p);

/*
** file: fill_directions.c
*/

int				fill_directions(char *previous, char *current, char *next);

/*
** file: map_wall.c
*/

int				is_map_walls_closed(t_map *map, t_data *maparr);

/*
** file: fill_map.c
*/

int				length(const char **array);
void			fill_maparr(t_map *map, t_data *maparr);

/*
** file: fill_map.c
*/

void			check_allfilled(t_map *map);

/*
** file: map_utils.c
*/

t_map			*new_map(void);
t_localmap		*init_localmap(void);

/*
** file: fill_map.c
*/

void			read_map_5(t_localmap *localmap);
void			read_map_6(t_localmap *localmap);

/*
** file: map_helper.c
*/

void			*get_mlx();
t_map			*game();
void			map_init(const char *map_name);

/*
** file: map_information.c
*/

void			set_map_information(t_map *map);

/*
** file: map_extension.c
*/

void			check_file_extension(const char *file_name);

/*
** file: sprite.c
*/

void			set_sp_initial_position(t_map *map);

/*
** file: close_map.c
*/

void			close_map_file(int fd);

#endif
