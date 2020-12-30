/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:18:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/30 11:38:36 by ahamdaou         ###   ########.fr       */
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
# include <stdio.h> // remove it later

# define TILE_SIZE 64
# define UNITIALIZED_COLOR -1
# define INITIAL_MINIMAP_SCALE 0.1
# define MAX_INFO_MENDATORY 8

/*
** window settings
*/

# define WINDOW_NAME "cub3d"
# define MAX_WINDOW_WIDTH 2560
# define MAX_WINDOW_HEIGHT 1440
# define MIN_WINDOW_WIDTH 500
# define MIN_WINDOW_HEIGHT 500

/*
** map states
*/

# define MAP_STATE_PRIOR 0
# define MAP_STATE_READING 1
# define MAP_STATE_FINISHED 2

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
	int		win_height;
	int		win_width;
	int		map_width;
	int		map_height;
	int		cols;
	int		rows;
	int		num_rays;
	float	minimap_scale;
	char	pview;
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

typedef struct	s_fread
{
	char	*line;
	int		ln;
	int		info_count;
	int		max_info;
	int		map_state;
}				t_fread;

t_map			map;
t_fread			freader;

t_map			*load_map(const char *file_name, int max_info);
void			fill_r(t_map *map, char *width, char *height);
void			fill_no(t_map *map, char *path);
void			fill_so(t_map *map, char *path);
void			fill_we(t_map *map, char *path);
void			fill_ea(t_map *map, char *path);
void			fill_s(t_map *map, char *path);
void			fill_f(t_map *map, char *rgb);
void			fill_c(t_map *map, char *rgb);
void			fill_map(t_map *map, t_data **tmp_map);
int				fill_directions(char *previous, char *current, char *next);
int				is_map_walls_closed(t_map *map, t_data *maparr);
int				length(char **array);
void			fill_maparr(t_map *map, t_data *maparr);
void			check_allfilled(t_map *map);
t_map			*read_map(const char *file_name);
t_map			*new_map(void);
void			*getmlx();
t_map			*game();
void			map_init(const char *map_name, int max_info);
void			set_map_information(t_map *map);
void			check_file_extension(const char *file_name);
void			set_sp_initial_position(t_map *map);
void			close_map_file(int fd);
void			free_double_pointer(char **ptr);

#endif
