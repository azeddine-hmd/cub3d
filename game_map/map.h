/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:18:49 by ahamdaou          #+#    #+#             */
/*   Updated: 2021/01/19 15:56:30 by ahamdaou         ###   ########.fr       */
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
# include <stdio.h>

# define TILE_SIZE 64
# define UNITIALIZED_COLOR -1
# define INITIAL_MINIMAP_SCALE 0.1
# define MAX_INFO_MENDATORY 8
# define MAP_ELEMENTS " NEWS0123"
# define MAP_SURROUNDING "NEWS023"

/*
** window settings
*/

# define WINDOW_NAME "cub3D"
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
	char	*win_name;
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
	int		player_count;
}				t_fread;

/*
** global variables
*/

t_map		g_map;
t_fread		g_freader;

/*
** functions prototype
*/

t_map			*load_map(const char *file_name, int max_info);
void			check_file_extension(const char *file_name);
void			fill_r(t_map *map, char *width, char *height);
void			fill_no(t_map *map, char *path);
void			fill_so(t_map *map, char *path);
void			fill_we(t_map *map, char *path);
void			fill_ea(t_map *map, char *path);
void			fill_s(t_map *map, char *path);
void			fill_f(t_map *map, char *rgb);
void			fill_c(t_map *map, char *rgb);
void			preparing_filling_r(t_map *map);
void			preparing_filling_no(t_map *map);
void			preparing_filling_so(t_map *map);
void			preparing_filling_we(t_map *map);
void			preparing_filling_ea(t_map *map);
void			preparing_filling_s(t_map *map);
void			preparing_filling_f(t_map *map);
void			preparing_filling_c(t_map *map);
void			fill_map(t_data **tmp_map);
void			check_line_element(const char *line);
int				is_map_walls_closed(t_data *tmp_map, int cols);
int				fill_directions(char *previous, char *current, char *next);
void			set_initial_player_position(t_map *map);
void			set_sp_initial_position(t_map *map);
void			map_init(const char *map_name, int max_info);
void			free_double_pointer(char **ptr);
int				length(char **array);
void			*getmlx();
t_map			*game();
void			set_cols(t_map *map, t_data *tmp_map);
void			set_rows(t_map *map, t_data *tmp_map);
void			set_map_information(t_map *map, t_data *tmp_map);
void			check_player_instance(void);
void			joinmap(t_map *map, t_data *head);
int				is_information(char *info);
void			linkedlist_bubble_sort(t_data *head);

#endif
