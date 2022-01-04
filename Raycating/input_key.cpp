#include "SDL_Project.h"

void	update_arrow(t_player *player)
{
	player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;
}

int	check_wall(t_player* player, int keycode)
{
	int next_x, next_y;
	int ret = 1;

	next_x = player->p_rect.x;
	next_y = player->p_rect.y;
	if (keycode == SDLK_d)
	{
		if (next_x+5 + 10 > SCREEN_WIDTH)
			ret = 0;
	}
	else if (keycode == SDLK_a)
	{
		if (next_x-5 < 1)
			ret = 0;
	}
	else if (keycode == SDLK_w)
	{
		if (next_y-5 < 1)
			ret = 0;
	}
	else if (keycode == SDLK_s)
	{
		if (next_y+5 + 10 > SCREEN_HEIGHT)
			ret = 0;
	}
	return (ret);
}

int	move_player(t_player *player)
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
				player->p_rect.x += 5;
			else if (keycode == SDLK_a)
				player->p_rect.x -= 5;
			else if (keycode == SDLK_w)
				player->p_rect.y -= 5;
			else if (keycode == SDLK_s)
				player->p_rect.y += 5;
			if (keycode == SDLK_q)
				player->angle += 5.0f;
			if (keycode == SDLK_e)
				player->angle -= 5.0f;
			if (player->angle > 360.0f)
				player->angle = 0.0f;
			else if (player->angle < -360.0f)
				player->angle = 0.0f;
		}
		update_arrow(player);
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
				player->p_rect.x += 5;
			else if (keycode == SDLK_a)
				player->p_rect.x -= 5;
			else if (keycode == SDLK_w)
				player->p_rect.y -= 5;
			else if (keycode == SDLK_s)
				player->p_rect.y += 5;
			if (keycode == SDLK_q)
				player->angle += 5.0f;
			if (keycode == SDLK_e)
				player->angle -= 5.0f;
			if (player->angle > 360.0f)
				player->angle = 0.0f;
			else if (player->angle < -360.0f)
				player->angle = 0.0f;
		}
		update_arrow(player);
	}
	return (1);
}