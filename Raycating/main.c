// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "SDL_Project.h"

/*
// 타일 크기
const static int TILE_SIZE = 64;

// 화면 크기 지정
const static int SCREEN_WIDTH = TILE_SIZE * 15;
const static int SCREEN_HEIGHT = TILE_SIZE * 10;
*/

void	tile_grid(SDL_Surface *screenSurface)
{
	SDL_Rect rectangle;

	rectangle.w = TILE_SIZE - 1;
	rectangle.h = TILE_SIZE - 1;
	for (int i = 1; i < SCREEN_HEIGHT; i = i + TILE_SIZE)
	{
		rectangle.y = i;
		for (int j = 1; j < SCREEN_WIDTH; j = j + TILE_SIZE)
		{
			rectangle.x = j;
			if (map[(i - 1) / TILE_SIZE][j / TILE_SIZE] == 1) // 지도의 벽
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xa0, 0xa0, 0xa0));
			else // 지도의 바닥
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		}
	}
}

void	draw_line(t_data *game_data)
{
	// x1, y1 플레이어 위치
	// x2, y2 플레이어가 바라보는 방향의 길이
	float x1 = game_data->player->p_rect.x;
	float y1 = game_data->player->p_rect.y;
	float x2 = x1 + (100 * (float)cos(M_PI / 180 * game_data->player->angle));
	float y2 = y1 + (100 * (float)sin(M_PI / 180 * game_data->player->angle));

	horizon_ray(game_data);
	vertical_ray(game_data);
	// SDL_RenderDrawLine(game_data->renderer, x1, y1, x2, y2);
	//SDL_RenderDrawLine(game_data->renderer, x1, y1, game_data->player->next_hx, game_data->player->next_hy);
	//SDL_RenderDrawLine(game_data->renderer, x1, y1, game_data->player->next_vx, game_data->player->next_vy);
}

void	Rendering(t_data *game_data)
{
	SDL_Renderer* renderer = game_data->renderer;
	SDL_Texture* texture = game_data->texture;
	t_player* player = game_data->player;

	// SDL_RenderClear(renderer);

	// 렌더러에 텍스쳐 연결 (현재 texture는 배경 격자)
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// 플레이어 그리기
	// 렌더러의 그리기 색상을 빨강색으로 설정
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// 렌더러에 플레이어 좌표에 사각형 연결. 색상은 위에서 설정한 빨강색이 됨.
	SDL_RenderFillRect(renderer, &player->player_cord);

	// 플레이어의 방향
	draw_line(game_data);

	//// 렌더러의 그리기 색상을 파랑색으로 설정
	//// 수평 격자
	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_hx, game_data->player->ray_hy);

	//// 수직 격자
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_vx, game_data->player->ray_vy);
	//// 렌더러에 플레이어 화살표 좌표에 사각형 연결

	// 수평 광선과 수직 광선 중 더 짧은 광선을 그림.
	select_short_ray(game_data);

	// 숨겨진 대상을 그린다. <--(?) 모든 것을 가져와 렌더러에 연결된 창에 그린다.
	SDL_RenderPresent(renderer);
}

// 플레이어 초기 위치와 크기
void	init_player(t_player *player)
{
	player->p_rect.x = TILE_SIZE + (TILE_SIZE / 2);
	player->p_rect.y = TILE_SIZE + (TILE_SIZE / 2);
	player->p_rect.w = 10;
	player->p_rect.h = 10;
	//player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	//player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;
	player->angle = 0.0f;
}

void	set_player_rect(t_player* p)
{
	p->player_cord.x = (int)floor(p->p_rect.x) - 5;
	p->player_cord.y = (int)floor(p->p_rect.y) - 5;
	p->player_cord.w = 10;
	p->player_cord.h = 10;
}

void	game(t_data* game_data)
{
	int loop = 1;
	while (loop)
	{
		// 플레이어 이동
		loop = move_player(game_data->player);
		// 플레이어 위치 표시용 사각형
		set_player_rect(game_data->player);
		// 렌더링
		Rendering(game_data);
	}
}

int main(int argc, char* args[])
{
	// 게임 종합 정보 구조체
	t_data* game_data = NULL;
	game_data = (t_data*)malloc(sizeof(t_data));
	if (game_data == NULL)
	{
		printf("Failed to allocation\n");
		return (1);
	}

	// The window we'll be rendering to
	// 윈도우 포인터
	SDL_Window* window = NULL;

	// The surface contained by the window
	// 윈도우 안의 화면 포인터
	SDL_Surface* screenSurface = NULL;

	// 렌더러 포인터
	SDL_Renderer* renderer = NULL;

	// 플레이어 좌표 구조체 SDL_Rect
	t_player* player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
	{
		printf("player init error\n");
		return (1);
	}
	init_player(player);

	// Initialize SDL
	// SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create window
		// 윈도우 생성
		window = SDL_CreateWindow("SDL INIT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			// 화면 생성
			screenSurface = SDL_GetWindowSurface(window);
			
			// 렌더러 생성
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer == NULL)
			{
				printf("Failed to create renderer %s\n", SDL_GetError());
				return (1);
			}

			// Fill the surface white
			// 화면을 흰색으로 채우기 NULL or SDL_RECT* << 크기지정 가능
			// SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			// 격자 화면 생성
			tile_grid(screenSurface);

			// surface to texture
			// 하나의 텍스쳐로 만드는 작업 하드웨어 렌더링(gpu)을 사용함
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, screenSurface);
			SDL_FreeSurface(screenSurface);

			// Update the surface
			// 화면 업데이트
			// SDL_UpdateWindowSurface(window);

			// 데이터 저장
			game_data->window = window;
			game_data->texture = texture;
			game_data->renderer = renderer;
			game_data->player = player;

			// 게임 시작
			game(game_data);

			// Wait two seconds
			// SDL_Delay(2000);
		}
	}

	// 플레이어 데이터 해제
	free(player);

	// Destroy window
	// 윈도우 해제
	SDL_DestroyWindow(window);

	// Quit SDL subsystems
	// SDL 끝내기
	SDL_Quit();

	free(game_data);
	return 0;
}