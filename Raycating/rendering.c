#include "SDL_Project.h"

void	draw_fov_ray(t_data *game_data)
{
	int ray_angle = -30;
	
	while (ray_angle < 30)
	{
		horizon_ray(game_data, ray_angle);		// 수평선에 닿는 ray
		vertical_ray(game_data, ray_angle);	// 수직선에 닿는 ray
		draw_short_ray(game_data);	// 두 ray 중 짧은 것을 저장 game_data->ray_x, y

		ray_angle++;
	}
}

void	draw_short_ray(t_data *g_data)
{
	t_player* p = g_data->player;
	float ray_distance_h, ray_distance_v;

	ray_distance_h = sqrtf(powf(p->ray_hx - p->p_rect.x, 2) + powf(p->ray_hy - p->p_rect.y, 2));
	ray_distance_v = sqrtf(powf(p->ray_vx - p->p_rect.x, 2) + powf(p->ray_vy - p->p_rect.y, 2));
	if (ray_distance_h == 0)
	{
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
	else if (ray_distance_v == 0)
	{
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else if (ray_distance_h < ray_distance_v)
	{
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else
	{
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
}

void	Rendering(t_data* game_data)
{
	SDL_Renderer* renderer = game_data->renderer;
	SDL_Texture* texture = game_data->texture;
	t_player* player = game_data->player;

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	/* SDL_RenderClear :: SDL_SetRenderDrawColor 로 지정되어 있는 색으로 화면 전체를 렌더링 함. */
	// SDL_RenderClear(renderer);

	// 렌더러에 텍스쳐 연결 (현재 texture는 배경 격자)
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// 플레이어 그리기
	// 렌더러의 그리기 색상을 빨강색으로 설정
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// 렌더러에 플레이어 좌표에 사각형 연결. 색상은 위에서 설정한 빨강색이 됨.
	SDL_RenderFillRect(renderer, &player->player_cord);

	// 플레이어의 방향
	// draw_line(game_data);

	// 플레이어 시야 표현
	draw_fov_ray(game_data);

	//// 렌더러의 그리기 색상을 파랑색으로 설정
	//// 수평 격자 ray
	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_hx, game_data->player->ray_hy);

	//// 수직 격자 ray
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_vx, game_data->player->ray_vy);
	//// 렌더러에 플레이어 화살표 좌표에 사각형 연결

	// 수평 광선과 수직 광선 중 더 짧은 광선을 그림.
	draw_short_ray(game_data);

	// 숨겨진 대상을 그린다. <--(?) 모든 것을 가져와 렌더러에 연결된 창에 그린다.
	SDL_RenderPresent(renderer);
}