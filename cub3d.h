/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:42:02 by ahamdaou          #+#    #+#             */
/*   Updated: 2020/10/31 10:25:23 by ahamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "game_map/map.h"
# define MINIMAP_SCALE 0.1
# define FOV_ANGLE (60 * (M_PI / 180))
# define KEY_ESC 53
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define INT_MAX 2147483647
# define COLOR_BLACK rgb(0, 0, 0)
# define COLOR_WHITE rgb(255, 255, 255)

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
	int		*buf;
	int		width;
	int		height;
}				t_txt;

/*
** file: utils.c
*/

int				rgb(int r, int g, int b);
void			pixel_put(int x, int y, int color);
int				pixel_get(int x, int y, void *arr, int txt_width, int txt_height);
void			line(t_point p0, t_point p1, int color);
void			square(int x, int y, int width, int color);
void			rect(t_point p, int width, int height, int color);
float			normalize_angle(float angle);
float			distance_between_points(float x1, float y1, float x2, float y2);
void			clear(int color);

/*
** file: map_methods.c
*/

void			minimap_render(void);
int				is_inside_map(float x, float y);
int				is_inside_window(float x, float y);
int				is_inside_texture(float x, float y, int txt_width, int txt_height);

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

/*
** file: input.c
*/

void			input_handler(void);

/*
** file: vars.c
*/

t_vars			*vars(void);

/*
** file: rays.c
*/

t_ray			**rays(void);
void			cast_all_rays(void);
void			rays_render(void);
void			cast(t_ray *ray);

/*
** file: projection.c
*/

void			render_projection_walls(void);

/*
** file: game.c
*/

void			game_exit(void);
void			game_loop(void);
void			render(void);

/*
** file: txt.c
*/

void			release_textures(void);

#endif
