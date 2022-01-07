#include "SDL_Project.h"

/*
void	update_arrow(t_player *player)
{
	player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;
}
*/

void	update_player_padding(t_player* player)
{
	/* 플레이어 패딩 업데이트 */
	player->p_padding_n = player->p_rect.y - 5;
	player->p_padding_s = player->p_rect.y + 5;
	player->p_padding_e = player->p_rect.x + 5;
	player->p_padding_w = player->p_rect.x - 5;
}

int	check_padding_wall(t_player* p, int keycode)
{
	// float c_x, c_y; // collision_x_, collision_y_
	int ret = 1;
	int north_lock = 0;
	int south_lock = 0;
	int east_lock = 0;
	int west_lock = 0;

	if (keycode == SDLK_w)
	{
		// 남쪽
		if (map[(int)floor(p->p_padding_s / TILE_SIZE)][(int)floor(p->p_rect.x / TILE_SIZE)] == 1)
		{
			south_lock = 1;
		}
		// 북쪽
		if (map[(int)floor(p->p_padding_n / TILE_SIZE)][(int)floor(p->p_rect.x / TILE_SIZE)] == 1)
		{
			north_lock = 1;
		}
		// 동쪽
		if (map[(int)floor(p->p_rect.y / TILE_SIZE)][(int)floor(p->p_padding_e / TILE_SIZE)] == 1)
		{
			east_lock = 1;
		}
		// 서쪽
		if (map[(int)floor(p->p_rect.y / TILE_SIZE)][(int)floor(p->p_padding_w / TILE_SIZE)] == 1)
		{
			west_lock = 1;
		}
	}
	if (north_lock)
	{

	}
	else
	{

	}
	return (ret);
}

int	check_wall(t_player* player, int keycode)
{
	float next_x, next_y;
	int ret = 1;

	next_x = player->p_rect.x;
	next_y = player->p_rect.y;

	if (keycode == SDLK_d)
	{
		next_x += (5 * (float)cos(M_PI / 180 * player->angle + M_PI / 2));
		next_y += (5 * (float)sin(M_PI / 180 * player->angle + M_PI / 2));
	}
	else if (keycode == SDLK_a)
	{
		next_x -= (5 * (float)cos(M_PI / 180 * player->angle + M_PI / 2));
		next_y -= (5 * (float)sin(M_PI / 180 * player->angle + M_PI / 2));
	}
	else if (keycode == SDLK_w)
	{
		next_x += (5 * (float)cos(M_PI / 180 * player->angle));
		next_y += (5 * (float)sin(M_PI / 180 * player->angle));
	}
	else if (keycode == SDLK_s)
	{
		next_x -= (5 * (float)cos(M_PI / 180 * player->angle));
		next_y -= (5 * (float)sin(M_PI / 180 * player->angle));
	}
	if (map[(int)floor(next_y) / TILE_SIZE][(int)floor(next_x) / TILE_SIZE] == 1)
		ret = 0;
	return (ret);
}

int	move_player(t_player *player)
{
	SDL_Event event;
	int keycode;

	if (SDL_PollEvent(&event))
	{
		// 플레이어 패딩 업데이트
		update_player_padding(player);
		if (event.type == SDL_QUIT)
		{
			return (0);
		}
		else if (event.type == SDL_KEYDOWN)
		{
			keycode = event.key.keysym.sym;
			if (keycode == SDLK_ESCAPE)
				return (0);
			if (!check_padding_wall(player, keycode))
				return (1);
			else if (keycode == SDLK_d)
			{
				player->p_rect.x += (2 * (float)cos(M_PI / 180 * player->angle + M_PI / 2));
				player->p_rect.y += (2 * (float)sin(M_PI / 180 * player->angle + M_PI / 2));
			}
			else if (keycode == SDLK_a)
			{
				player->p_rect.x -= (2 * (float)cos(M_PI / 180 * player->angle + M_PI / 2));
				player->p_rect.y -= (2 * (float)sin(M_PI / 180 * player->angle + M_PI / 2));
			}
			else if (keycode == SDLK_w)
			{
				player->p_rect.x += (2 * (float)cos(M_PI / 180 * player->angle));
				player->p_rect.y += (2 * (float)sin(M_PI / 180 * player->angle));
			}
			else if (keycode == SDLK_s)
			{
				player->p_rect.x -= (2 * (float)cos(M_PI / 180 * player->angle));
				player->p_rect.y -= (2 * (float)sin(M_PI / 180 * player->angle));
			}
			if (keycode == SDLK_q)
				player->angle -= 5.0f;
			if (keycode == SDLK_e)
				player->angle += 5.0f;
			if (player->angle >= 360.0f)
				player->angle = 0.0f;
			else if (player->angle <= -360.0f)
				player->angle = 0.0f;
		}
		if (event.type == SDL_KEYUP)
		{
			if (player->move_left_right)
				player->move_left_right = 0;
			if (player->move_forword_back)
				player->move_forword_back = 0;
		}
		// update_arrow(player);
		// printf("angle : %f\n", player->angle);
	}
	return (1);
}

int	input_key(t_player *player)
{
	SDL_Event event;
	int keycode;

	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return (0);
		}
		else if (event.type == SDL_KEYDOWN)
		{
			keycode = event.key.keysym.sym;
			if (!check_wall(player, keycode))
				return (1);
			if (keycode == SDLK_ESCAPE)
				return (0);
			else if (keycode == SDLK_d)
				player->move_left_right = 1;
			else if (keycode == SDLK_a)
				player->move_left_right = -1;
			else if (keycode == SDLK_w)
				player->move_forword_back = 1;
			else if (keycode == SDLK_s)
				player->move_forword_back = -1;
			if (keycode == SDLK_q)
				player->angle += 5.0f;
			if (keycode == SDLK_e)
				player->angle -= 5.0f;
			if (player->angle > 360.0f)
				player->angle = 0.0f;
			else if (player->angle < -360.0f)
				player->angle = 0.0f;
		}
	}
	return (1);
}