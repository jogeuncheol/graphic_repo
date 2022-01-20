#include "SDL_Project.h"
//#include "texture/re_wall1.ppm"
//#include "texture/re_texture1.ppm"
//#include "texture/stone_wall3.ppm"
#include "texture/wall_tex3.ppm" // wall_tex1
#include "texture/wall_tex4.ppm" // wall_tex2
#include "texture/wall_texture3.ppm" // wall_texture3
#include "texture/wall_texture4.ppm" // wall_texture4

void	map_over_screen(t_data* game_data)
{
	Uint8* keystatus = SDL_GetKeyboardState(NULL);
	if (keystatus[SDL_SCANCODE_M])
		game_data->player->is_map_visible = 1;

}

void	test_set_color(t_data* game_data, int texel, int *r, int *g, int *b, int wall_h, int* texture)
{
	float shader = 0.0f;
	shader = (float)wall_h / SCREEN_HEIGHT;
	if (shader > 1.0f)
	{
		shader = 1.0f;
	}
	*r = texture[texel + 0] * shader;
	*g = texture[texel + 1] * shader;
	*b = texture[texel + 2] * shader;
}

void	draw_fov_wall(t_data* game_data, float fov_angle, int width_idx)
{
	t_player* p = game_data->player;
	float	dst_x = fabs(game_data->ray_x) - p->p_rect.x;
	float	dst_y = fabs(game_data->ray_y) - p->p_rect.y;
	float	dst = sqrt(pow(dst_x, 2) + pow(dst_y, 2));
	float	dst_test;
	float	rad = (float)((fov_angle) * M_PI / 180);
	int	wall_h;

	dst_test = dst_x * cos(rad) + dst_y * sin(rad); // 04_13 save
	if (dst <= 0 || dst_test <= 0)
		dst_test = 1;

	// 스프라이트 표현 zbuf
	// param->zbuf[width_idx] = dst_test; // 05_05 save

	float ra = fov_angle - p->angle;
	dst = dst * cos(ra * M_PI / 180); // 카메라 평면의 거리로 변환
	// wall_h = TILE_SIZE * ((SCREEN_WIDTH / 1) * (tan(30 * M_PI / 180))) / dst;
	wall_h = TILE_SIZE * ((SCREEN_WIDTH * 0.85f) / dst);

	/* test code :: sprite */
	// 벽까지 거리 값
	game_data->dist_dept[width_idx] = dst;
	/* test code :: sprite */

	//if (wall_h > SCREEN_HEIGHT)
	//	wall_h = SCREEN_HEIGHT;

	int i; // = SCREEN_WIDTH + SCREEN_WIDTH / 2;
	int j = (SCREEN_HEIGHT) / 2;
	i = SCREEN_WIDTH + width_idx;// test : * 8 or 4;
	int top = (SCREEN_HEIGHT - wall_h) / 2;
	int bottom = wall_h + top;
	// printf("top : %d\nbottom : %d\n", top, bottom);

	// SDL_RenderDrawLine(game_data->renderer, width_idx, top, width_idx, bottom);

	/* 테스트 코드 : 텍스쳐 */
	int x = 0;
	int y = 0;
	int z = 0;
	// int pixel = (i * 512 + j) * 3;
	int r = 0; //texture1[pixel + 0];
	int g = 0; //texture1[pixel + 1];
	int b = 0; //texture1[pixel + 2];

	int h = wall_h / 2;
	if (game_data->hit_v)
		y = (int)floor(fmod(game_data->ray_y, 64));
	else
		y = (int)floor(fmod(game_data->ray_x, 64));
	int* texture = (set_texture(game_data) == 1) ? wall_texture3 : wall_texture4;
	float shader = set_color_shader(wall_h);
	SDL_Rect wall_rect;
	wall_rect.w = 2;
	wall_rect.h = 1;
	wall_rect.x = width_idx;
	while (h > 0)// && width_idx > SCREEN_WIDTH / 3 && width_idx < SCREEN_WIDTH * 2 / 3)
	{
		h--;
		x = (z++) * ((float)64 / wall_h);
		if (j - h < 0 || j + h > SCREEN_HEIGHT)
			continue;

		// int texel = (x * 64 + y) * 3;
		// test_set_color(game_data, texel, &r, &g, &b, wall_h, stone_wall3);

		// 상단 그리기
		// test_wall_texel(game_data, x, y, width_idx, h, texture4);
		
		Uint32 color = set_color_from_texture(&wall_rect, game_data, x, y, h, shader, texture);
		SDL_FillRect(game_data->wall_surface, &wall_rect, color);
		// 하단 그리기
		//texel = ((64 - x) * 64 + y) * 3;
		//test_set_color(game_data, texel, &r, &g, &b, wall_h, stone_wall3);
		//wall_rect.y = (int)(floor(SCREEN_HEIGHT / 2) + h);
		color = set_color_from_texture(&wall_rect, game_data, ((TILE_SIZE - 1) - x), y, -h, shader, texture);
		SDL_FillRect(game_data->wall_surface, &wall_rect, color);
	}
}

void	draw_fov_ray(t_data *game_data)
{
	t_player* p = game_data->player;
	float	ray_angle = -30.0f;
	float	fov_angle;
	const float	ray_count = 0.0625;
	int	wall_idx = 0;
	
	while (wall_idx < SCREEN_WIDTH)
	{
		// fov_angle = p->angle + ray_angle;
		ray_angle = atan2((double)(SCREEN_WIDTH / 2) - wall_idx, ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180)));
		fov_angle = p->angle - (ray_angle * (180 / M_PI));
		if (fabs(fov_angle) > 360)
		{
			if (fov_angle > 360)
				fov_angle -= 360;
			else
				fov_angle += 360;
		}
		// 앨리어싱
		if (wall_idx % 2 == 0)
		{
			horizon_ray(game_data, fov_angle);		// 수평선에 닿는 ray
			vertical_ray(game_data, fov_angle);		// 수직선에 닿는 ray
			draw_short_ray(game_data);				// 두 ray 중 짧은 것을 저장 game_data->ray_x, y
		}
		draw_fov_wall(game_data, fov_angle, wall_idx);	// 수직 벽 표현

		// ray_angle = ray_angle + ray_count;
		// 앨리어싱
		wall_idx += 2;
	}
}

// 수평 ray 와 수직 ray 중 더 짧은 ray를 선택해 그림
void	draw_short_ray(t_data *g_data)
{
	t_player* p = g_data->player;
	float	ray_distance_h, ray_distance_v;

	ray_distance_h = sqrtf(powf(p->ray_hx - p->p_rect.x, 2) + powf(p->ray_hy - p->p_rect.y, 2));
	ray_distance_v = sqrtf(powf(p->ray_vx - p->p_rect.x, 2) + powf(p->ray_vy - p->p_rect.y, 2));
	if (ray_distance_h == 0)
	{
		g_data->hit_v = 1;
		g_data->hit_h = 0;
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0xC8, 0xC8, 0xFF);
//		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
	else if (ray_distance_v == 0)
	{
		g_data->hit_v = 0;
		g_data->hit_h = 1;
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xd0, 0xe0, 0xFF, 0xFF);
//		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else if (ray_distance_h < ray_distance_v)
	{
		g_data->hit_v = 0;
		g_data->hit_h = 1;
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xd0, 0xe0, 0xFF, 0xFF);
//		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else
	{
		g_data->hit_v = 1;
		g_data->hit_h = 0;
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0xC8, 0xC8, 0xFF);
//		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
}

void	Rendering(t_data* game_data)
{
	SDL_Renderer* renderer = game_data->renderer;
	SDL_Texture* texture = game_data->texture;
	SDL_Texture* bg_texture = game_data->bg_texture;
	t_player* player = game_data->player;

	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	/* SDL_RenderClear :: SDL_SetRenderDrawColor 로 지정되어 있는 색으로 화면 전체를 렌더링 함. */
	SDL_RenderClear(renderer);

	// 렌더러에 텍스쳐 연결 (현재 texture는 배경 격자)
	// SDL_RenderCopy(renderer, texture, NULL, NULL);

	// 뒷 배경 텍스쳐 연결
	// SDL_RenderCopy(renderer, bg_texture, NULL, NULL);

	// 플레이어 그리기
	// 렌더러의 그리기 색상을 빨강색으로 설정
	// SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// 렌더러에 플레이어 좌표에 사각형 연결. 색상은 위에서 설정한 빨강색이 됨.
	// SDL_RenderFillRect(renderer, &player->player_cord);

	// 플레이어의 방향
	//draw_line(game_data);

	// 플레이어 시야 표현
	game_data->wall_surface = init_background(game_data->window);
	draw_fov_ray(game_data);
	//ft_sprite_calculate(game_data);
	//if (game_data->sprite_count)
	//	test_sprite_(game_data);
	game_data->wall_texture1 = SDL_CreateTextureFromSurface(game_data->renderer, game_data->wall_surface);
	SDL_FreeSurface(game_data->wall_surface);
	SDL_RenderCopy(game_data->renderer, game_data->wall_texture1, NULL, NULL);
	SDL_DestroyTexture(game_data->wall_texture1);

	//// 렌더러의 그리기 색상을 파랑색으로 설정
	//// 수평 격자 ray
	// SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	// SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_hx, game_data->player->ray_hy);

	//// 수직 격자 ray
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_vx, game_data->player->ray_vy);
	//// 렌더러에 플레이어 화살표 좌표에 사각형 연결

	// 수평 광선과 수직 광선 중 더 짧은 광선을 그림.
	// draw_short_ray(game_data);

	/* sprite code */
	// game_data->sp1_surface = SDL_GetWindowSurface(game_data->window);
	ft_sprite_calculate(game_data);
	if (game_data->sprite_count)
		test_sprite_(game_data);
	//game_data->sp1_texture = SDL_CreateTextureFromSurface(game_data->renderer, game_data->sp1_surface);
	//SDL_FreeSurface(game_data->sp1_surface);
	////SDL_RenderCopy(game_data->renderer, game_data->sp1_texture, NULL, NULL);
	//SDL_DestroyTexture(game_data->sp1_texture);

	// 지도 그리기
	draw_map(game_data);
	// test_draw_texture(game_data);
	// ft_test_pmm(game_data);

	// 숨겨진 대상을 그린다. <--(?) 모든 것을 가져와 렌더러에 연결된 창에 그린다.
	SDL_RenderPresent(renderer);
}