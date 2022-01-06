#include "SDL_Project.h"

void	select_short_ray(t_data *g_data)
{
	t_player* p = g_data->player;
	float ray_distance_h, ray_distance_v;

	ray_distance_h = sqrt(pow(p->ray_hx, 2) + pow(p->ray_hy, 2));
	ray_distance_v = sqrt(pow(p->ray_vx, 2) + pow(p->ray_vy, 2));

	if (ray_distance_h < ray_distance_v)
	{
		SDL_SetRenderDrawColor(g_data->renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, p->p_rect.x, p->p_rect.y, p->ray_hx, p->ray_hy);
	}
	else
	{
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, p->p_rect.x, p->p_rect.y, p->ray_vx, p->ray_vy);
	}
}