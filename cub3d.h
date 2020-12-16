/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:42:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/12/16 04:12:18 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "game_map/map.h"

# define FOV_ANGLE (60 * (M_PI / 180))
# define INT_MAX 2147483647
# define MAX_SONGS 2
# define AUDIO_PLAYER mplayer

/*
** Colors
*/

# define COLOR_BLACK 0x000000
# define COLOR_WHITE 0xFFFFFF
# define COLOR_RED 0xFF0000
# define COLOR_ORANGE 0xFFA500

/*
** Keys
*/

# define KEY_ESC 53
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_O 31
# define KEY_P 35
# define KEY_M 46
# define KEY_0 29
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25

typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct	s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	walk_speed;
	float	turn_speed;
	float	rotation_angle;
	int		move_right;
	int		move_left;
	int		move_forward_or_backward;
}				t_player;

typedef struct	s_ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		wall_hit_content;
}				t_ray;

typedef struct	s_txt
{
	void	*img;
	int		width;
	int		height;
}				t_txt;

typedef struct	s_bitmapheader
{
	uint32_t	file_size;
	uint32_t	off_bits;
	uint32_t	size;
	uint32_t	info_size;
	int32_t		width;
	int32_t		height;
	uint16_t	planes;
	uint16_t	bit_count;
	uint32_t	image_size;
	int			width_in_bytes;
	int			fd;
}				t_bitmapheader;

typedef struct	s_wall
{
	float		correct_wall_distance;
	float		distance_proj_plane;
	float		wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
}				t_wall;

typedef struct	s_horz
{
	float	next_horz_touch_x;
	float	next_horz_touch_y;
	int		found_horz_wall_hit;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	int		horz_wall_content;
}				t_horz;

typedef struct	s_vert
{
	int		found_vert_wall_hit;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	int		vert_wall_content;
}				t_vert;

/*
** file: math_helper.c
*/

float			normalize_angle(float angle);
float			distance_between_points(t_point p1, t_point p2);
float			f_mod(float a, float b);
void			setpoint(t_point *p, int x, int y);

/*
** file: draw.c
*/

int				rgb(int r, int g, int b);
void			line(t_point p0, t_point p1, int color);
void			square(float x, float y, float width, int color);
void			rect(t_point p, int width, int height, int color);

/*
** file: map_methods.c
*/

void			minimap_sprite_render(void);
void			minimap_render(void);
int				is_inside_map(float x, float y);
int				is_inside_window(float x, float y);
int				is_inside_texture(float x, float y, int width, int height);
int				is_inside_sprite(float x, float y, int width, int height);

/*
** file: player.c
*/

t_player		*player(void);

/*
** file: player_method.c
*/

void			move_player(void);
void			player_render(void);

/*
** file: collision.c
*/

int				has_wall_at(float x, float y);
int				has_hidden_wall_at(float x, float y);
int				has_player_at(float x, float y);
int				has_sprite_at(float x, float y);

/*
** file: input.c
*/

void			input_handler(void);

/*
** file: mlx_helper.c
*/

void			pixel_put(float x, float y, int color);
int				pixel_get(float x, float y);
int				texture_pixel_get(int x, int y);
int				sprite_pixel_get(int x, int y);

/*
** file: vars.c
*/

t_vars			*vars(void);

/*
** file: rays.c
*/

t_ray			**rays(void);
void			rays_init(void);

/*
** file: rays_helper.c
*/

void			set_ray_direction(t_ray *ray);

/*
** file: rays_methods.c
*/

void			rays_render(void);
void			cast_all_rays(void);
void			cast(t_ray *ray);

/*
** file: projection.c
*/

void			render_projection_walls(void);

/*
** file: game.c
*/

void			game_exit(int return_signal);
void			render(void);

/*
** file: txt.c
*/

t_txt			*gettxt(void);
void			texture_init(void);
void			settexture(t_ray *ray);
void			release_textures(void);

/*
** file: txt_helper.c
*/

void			set_north_texture(t_txt *txt);
void			set_south_texture(t_txt *txt);
void			set_west_texture(t_txt *txt);
void			set_east_texture(t_txt *txt);

/*
** file: rays_helper.c
*/

void			set_ray_direction(t_ray *ray);

/*
** file: rays_methods.c
*/

void			rays_render(void);
void			cast_all_rays(void);

/*
** file: sprite_methods.c
*/

void			set_sprites_distance(void);
void			linkedlist_bubble_sort(t_data *head);
void			render_sprites(void);

/*
** file: audio.c
*/
void			play_song(void);

/*
** file: screenshot.c
*/

void			take_screenshot(void);

/*
** file: binding.c
*/

void			movement_binding(int key);
void			minimap_resezing_binding(int key);
void			rotation_binding(int key);
void			global_binding(int key);

/*
** file: protection.c
*/

int				is_inside_map(float x, float y);
int				is_inside_window(float x, float y);
int				is_inside_texture(float x, float y, int width, int height);
int				is_inside_sprite(float x, float y, int width, int height);

/*
** file: movement.c
*/

void			move_right(float *nplayer_x, float *nplayer_y);
void			move_left(float *nplayer_x, float *nplayer_y);
void			move(float *move_step, float *nplayer_x, float *nplayer_y);
void			no_movement(void);

/*
** file: projection_helper.c
*/

void			ceilling_projection(int col, t_wall *wall);
void			floor_projection(int col, t_wall *wall);
void			wall_projection(int col, t_ray *ray, t_wall *wall);

/*
** file: cast.c
*/

void			cast(t_ray *ray);

/*
** file: horz_intersection.c
*/

void			horizontal_intersection(t_ray *ray, t_horz *horz);

/*
** file: horz_intersection.c
*/

void			vertical_intersection(t_ray *ray, t_vert *vert);

/*
** file: release_sprites.c
*/

void		release_sprites(void);

#endif
