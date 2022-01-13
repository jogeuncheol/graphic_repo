#include "SDL_Project.h"

SDL_Surface* init_background(SDL_Window *window)
{
	SDL_Surface* background_surface = NULL;
	SDL_Rect bg_rect;
	int r, g, b;
	float shader = 0.0f;

	bg_rect.x = 0;
	bg_rect.y = 0;
	bg_rect.w = SCREEN_WIDTH;
	bg_rect.h = 1;
	background_surface = SDL_GetWindowSurface(window);
	while (bg_rect.y < SCREEN_HEIGHT)
	{
		shader = 0x60 / (SCREEN_HEIGHT / 2);
		if (shader > 1.0f)
			shader = 1.0f;
		SDL_FillRect(background_surface, &bg_rect, SDL_MapRGB(background_surface->format, 0x60, 0x60, 0x60));
		bg_rect.y++;
	}
	return (background_surface);
}

void	test_wall_texel(t_data *game_data, int x, int y, int width_idx, int h, int *texture1)
{
	SDL_Rect wall_rect;

	wall_rect.x = width_idx;
	wall_rect.y = (int)(floor(SCREEN_HEIGHT / 2) - h);
	wall_rect.w = 1;
	wall_rect.h = 1;

	int r = 0;
	int g = 0;
	int b = 0;
	int z = 0;
	int texel = (x * 64 + y) * 3;
	r = texture1[texel + 0];
	g = texture1[texel + 1];
	b = texture1[texel + 2];
	SDL_FillRect(game_data->wall_surface, &wall_rect, SDL_MapRGB(game_data->wall_surface->format, r, g, b));
	wall_rect.y = (int)(floor(SCREEN_HEIGHT / 2) + h);
	texel = ((64 - x) * 64 + y) * 3;
	r = texture1[texel + 0];
	g = texture1[texel + 1];
	b = texture1[texel + 2];
	SDL_FillRect(game_data->wall_surface, &wall_rect, SDL_MapRGB(game_data->wall_surface->format, r, g, b));
}

void	draw_map(t_data* game_data)
{
	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = WORLD_WIDTH;
	src_rect.h = WORLD_HEIGHT;
	dst_rect.x = 0;
	dst_rect.y = 0;
	dst_rect.w = WORLD_WIDTH / 4;
	dst_rect.h = WORLD_HEIGHT / 4;
	if (game_data->player->is_map_visible)
		SDL_RenderCopy(game_data->renderer, game_data->texture, &src_rect, &dst_rect);
}

void	test_draw_texture(t_data* game_data)
{
	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = SCREEN_WIDTH;
	src_rect.h = SCREEN_HEIGHT;
	// SDL_QueryTexture(game_data->wall_texture1, NULL, NULL, &src_rect.w, &src_rect.h);

	dst_rect.x = 0;
	dst_rect.y = 0;
	dst_rect.w = SCREEN_WIDTH;
	dst_rect.h = SCREEN_HEIGHT;
	if (game_data->player->is_map_visible)
		SDL_RenderCopy(game_data->renderer, game_data->wall_texture1, &src_rect, &dst_rect);
}