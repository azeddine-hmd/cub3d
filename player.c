#include "cub3d.h"

static float	get_initial_angle(void)
{
	float	initial_angle;
	char	pview;

	initial_angle = 0;
	pview = map()->pview;
	if (pview == 'W')
		initial_angle = M_PI;
	else if (pview == 'N')
		initial_angle = (3 * M_PI) / 2;
	else if (pview == 'S')
		initial_angle = M_PI / 2;
	return (initial_angle);
}

static t_player	*player_init(void)
{
	t_player	*player;

	player = (t_player*)xmalloc(sizeof(t_player));
	player->x = map()->initial_pos[0] * TILE_SIZE - (TILE_SIZE / 2);
	player->y = map()->initial_pos[1] * TILE_SIZE - (TILE_SIZE / 2);
	player->width = 1;
	player->height = 1;
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->rotation_angle = get_initial_angle();
	player->walk_speed = 20;
	player->turn_speed = 4.5 * (M_PI / 180.0);
	player->move_right = 0;
	player->move_right = 0;
	return (player);
}

/*
** before calling this function, 'vars()' should be invoked first.
*/

t_player	*player(void)
{
	static t_player	*player;

	if (!player)
		player = player_init();
	return (player);
}
