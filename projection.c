#include "cub3d.h"

void	render_projection_walls(void)
{
	int 	i;
	int		y;
	t_ray	*ray;
	float	wall_strip_height;
	float	correct_wall_distance;
	float	distance_proj_plane;

	i = -1;
	while (++i < map()->num_rays)
	{
		ray = rays()[i];

		correct_wall_distance = ray->distance * cos(ray->ray_angle - player()->rotation_angle);

		// calculate the distace to the projection plane
		distance_proj_plane = (map()->win_width / 2) / tan(FOV_ANGLE / 2);

		// projected wall height
		wall_strip_height = (TILE_SIZE / correct_wall_distance) * distance_proj_plane;

        int wall_top_pixel = (map()->win_height / 2) - (wall_strip_height / 2);
        wall_top_pixel = wall_top_pixel < 0 ? 0 : wall_top_pixel;

        int wall_bottom_pixel = (map()->win_height / 2) + (wall_strip_height / 2);
        wall_bottom_pixel = wall_bottom_pixel > map()->win_height ? map()->win_height : wall_bottom_pixel;


		y = -1;
		while (++y < wall_top_pixel)
			pixel_put(i, y, rgb(0, 0, 0));

		// deciding which texture to be set
		void *txt = NULL;
		int	txt_width = 0;
		int	txt_height = 0;

		// north
		if (!ray->was_hit_vertical && ray->is_ray_facing_up)
		{
			txt = map()->no->imgarr;
			txt_width = map()->no->w;
			txt_height = map()->no->h;
		}

		// south
		if (!ray->was_hit_vertical && ray->is_ray_facing_down)
		{
			txt = map()->so->imgarr;
			txt_width = map()->so->w;
			txt_height = map()->so->h;
		}

		// west
		if (ray->was_hit_vertical && ray->is_ray_facing_left)
		{
			txt = map()->we->imgarr;
			txt_width = map()->we->w;
			txt_height = map()->we->h;
		}

		// east
		if (ray->was_hit_vertical && ray->is_ray_facing_right)
		{
			txt = map()->ea->imgarr;
			txt_width = map()->ea->w;
			txt_height = map()->ea->h;
		}

		// applying texture on walls
		int	offset_x;
		int offset_y;
		int	distance_from_top;

		// calculate offset_x
		if (ray->was_hit_vertical)
			//offset_x = (int)ray->wall_hit_y % TILE_SIZE;
			offset_x = (int)ray->wall_hit_y % txt_height;
		else
			//offset_x = (int)ray->wall_hit_x % TILE_SIZE;
			offset_x = (int)ray->wall_hit_x % txt_width;

		y = wall_top_pixel - 1;
		while (++y < wall_bottom_pixel)
		{
			// calculate offset_y
			distance_from_top = y + (wall_strip_height / 2) - (map()->win_height / 2);
			offset_y = distance_from_top * ((float)txt_width / wall_strip_height);

			int texture_color = pixel_get(offset_x, offset_y, txt, txt_width, txt_height);
			//int texture_color = rgb(255,255,255);

			pixel_put(i, y, texture_color);
		}

		y = wall_bottom_pixel - 1;
		while (++y < map()->win_height)
			pixel_put(i, y, rgb(255, 127, 63));
	}
}
