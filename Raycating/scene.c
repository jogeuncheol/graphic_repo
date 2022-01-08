#include "SDL_Project.h"

SDL_Surface* init_background(SDL_Window *window)
{
	SDL_Surface* background_surface = NULL;
	SDL_Rect bg_rect;

	bg_rect.x = 0;
	bg_rect.y = 0;
	bg_rect.w = SCREEN_WIDTH;
	bg_rect.h = SCREEN_HEIGHT;
	background_surface = SDL_GetWindowSurface(window);
	SDL_FillRect(background_surface, &bg_rect, SDL_MapRGB(background_surface->format, 0x60, 0x60, 0x60));
	return (background_surface);
}

void	draw_map(t_data* game_data)
{
	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = SCREEN_WIDTH;
	src_rect.h = SCREEN_HEIGHT;
	dst_rect.x = 0;
	dst_rect.y = 0;
	dst_rect.w = SCREEN_WIDTH / 4;
	dst_rect.h = SCREEN_HEIGHT / 4;
	if (game_data->player->is_map_visible)
		SDL_RenderCopy(game_data->renderer, game_data->texture, &src_rect, &dst_rect);
}