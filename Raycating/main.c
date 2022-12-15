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

int	break_init_map(t_data *game_data, int i)
{
	for (int j = 0; j < i; j++)
	{
		free(game_data->map[j]);
		game_data->map[j] = NULL;
	}
	free(game_data->map);
	game_data->map = NULL;
	return (1);
}

int	init_main_map(t_data *game_data)
{
	game_data->map = (int**)malloc(sizeof(int *) * map_h);
	if (game_data->map != NULL)
	{
		for (int i = 0; i < map_h; i++)
		{
			game_data->map[i] = (int*)malloc(sizeof(int) * map_w);
			if (game_data->map[i] == NULL)
				return (break_init_map(game_data, i));
		}
	}
	printf("map init pass\n");
	return (0);
}

int copy_main_map(t_data* game_data, int (*map)[map_w])
{
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			game_data->map[i][j] = map[i][j];
		}
	}
}

void	tile_grid(SDL_Surface *screenSurface, t_data *game_data)
{
	SDL_Rect rectangle;

	rectangle.w = 10 - 1;
	rectangle.h = 10 - 1;
	for (int i = 1; i < map_h * 10; i = i + 10)
	{
		rectangle.y = i;
		for (int j = 1; j < map_w * 10; j = j + 10)
		{
			rectangle.x = j;
			if (game_data->map[(i - 1) / 10][j / 10] != 0) // 지도의 벽
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xa0, 0xa0, 0xa0));
			else if ((i / 10 == 8 && j / 10 == 8) || (i / 10 == 10 && j / 10 == 13))
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
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

	// horizon_ray(game_data);
	// vertical_ray(game_data);
	// SDL_RenderDrawLine(game_data->renderer, x1, y1, x2, y2);
	//SDL_RenderDrawLine(game_data->renderer, x1, y1, game_data->player->next_hx, game_data->player->next_hy);
	//SDL_RenderDrawLine(game_data->renderer, x1, y1, game_data->player->next_vx, game_data->player->next_vy);
}

// 플레이어 초기 위치와 크기
void	init_player(t_player *player)
{
	player->p_rect.x = 7 * TILE_SIZE + (TILE_SIZE / 2);
	player->p_rect.y = 5 * TILE_SIZE + (TILE_SIZE / 2);
	player->p_rect.w = 10;
	player->p_rect.h = 10;
	//player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	//player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;
	player->angle = 90.0f;

	/* 플레이어 패딩 초기화 */
	player->p_padding_n = player->p_rect.y - 5;
	player->p_padding_s = player->p_rect.y + 5;
	player->p_padding_e = player->p_rect.x + 5;
	player->p_padding_w = player->p_rect.x - 5;

	player->velocity = 1.0f;
	player->is_map_visible = 0;
	player->is_key_map_visible = 0;

	player->inventory = 0;
}

void	set_player_rect(t_player* p)
{
	p->player_cord.x = (int)floor(p->p_rect.x) - 5;
	p->player_cord.y = (int)floor(p->p_rect.y) - 5;
	p->player_cord.w = 10;
	p->player_cord.h = 10;
}

void	ft_test()
{
	SDL_Event event;
	Uint8* keystatus = SDL_GetKeyboardState(NULL);
	
	if (keystatus[SDL_SCANCODE_W])
	{
		printf("press up ");
	}
	if (keystatus[SDL_SCANCODE_S])
	{
		printf("press down ");
	}
	if (keystatus[SDL_SCANCODE_A])
	{
		printf("press left ");
	}
	if (keystatus[SDL_SCANCODE_D])
	{
		printf("press right ");
	}
}

void	init_config(t_data* game_data)
{
	game_data->config.h_fov = 40;
	game_data->config.v_fov = 0.6f;
	game_data->config.rotate = 1.5f;
	game_data->config.texture = 1;
	game_data->config.cross_dot = 1;
	game_data->config.head_bob = 1;

	printf("FOV\t\t:: %.0f\n", (double)game_data->config.h_fov * 2.0f);
	printf("회전 속도\t:: %.1f\n", (double)game_data->config.rotate);
	printf("중앙점\t\t:: on\n");
	printf("화면 흔들림\t:: on\n");
}

void	game(t_data* game_data)
{
	init_config(game_data);
	SDL_Rect sRect = { 0, 0, 1920, 1080 };
	SDL_Rect dRect = { 0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT };
	int loop = 1;

	game_data->title = 0;
	// Mix_PlayMusic(game_data->sound->bgm, -1);	// -1 :: infinite
	if (Mix_FadeInMusic(game_data->sound->title, -1, 3000) == -1) {
		printf("Mix_PlayMusic: %s\n", Mix_GetError());
		// well, there's no music, but most games don't break without music...
	}
	Mix_VolumeMusic(50);
	while (loop)
	{
		if (game_data->title == 0)
		{
			if (game_data->round == 1)
			{
				init_player(game_data->player);
				zeromem_sprite(game_data);
				init_sprite(game_data);
			}
			else if (game_data->round == 2)
			{
				init_level2_player(game_data);
				zeromem_sprite(game_data);
				init_level2_sprite(game_data);
			}
			/* 게임이 끝난 후 리셋 */
			if (game_data->round == 1)
			{
				game_data->clear_req = 0;
				copy_main_map(game_data, map1);
			}
			SDL_Event event;
			Uint8* keystatus = SDL_GetKeyboardState(NULL);
			while (SDL_PollEvent(&event))
			{
				if (keystatus[SDL_SCANCODE_RETURN])
				{
					printf("press return key \n");
					game_data->title = 1;
					Mix_FadeOutMusic(2000);
					Mix_FadeInMusic(game_data->sound->bgm, -1, 2000);
					Mix_VolumeMusic(20);
					// Mix_PauseMusic();
				}
				else if (keystatus[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT)
					loop = 0;
			}
			SDL_RenderClear(game_data->renderer);
			SDL_RenderCopy(game_data->renderer, game_data->title_texture, &sRect, &dRect);
			SDL_RenderPresent(game_data->renderer);
		}
		else if (game_data->title == 1)
		{
			// reset sprite map
			reset_visible_sprite_map(game_data);

			// 플레이어 이동
			game_data->title = move_player(game_data);
			if (game_data->title == 0)
			{
				Mix_FadeInMusic(game_data->sound->title, -1, 2000);
				continue;
				// game_data->title = 1;
				// Mix_ResumeMusic();
			}
			else if (game_data->title == 2 || game_data->round == 4)
			{
				game_data->title = 2;
				Mix_VolumeMusic(100);
				Mix_FadeInMusic(game_data->sound->ending, -1, 2000);
				continue;
			}

			// 렌더링
			Rendering(game_data);
			check_level(game_data);
		}
		else if (game_data->title == 2)
		{
			SDL_Event event;
			SDL_RenderClear(game_data->renderer);
			SDL_RenderCopy(game_data->renderer, game_data->end_texture, &sRect, &dRect);
			SDL_RenderPresent(game_data->renderer);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					Mix_FadeOutMusic(2000);
					Mix_FadeInMusic(game_data->sound->title, -1, 2000);
					Mix_VolumeMusic(50);
					game_data->title = 0;
					game_data->clear_req = 0;
					game_data->round = 1;
				}
			}
		}
		SDL_Delay(1000 / 144);
	}
}

int main(int argc, char* args[])
{
	// 게임 종합 정보 구조체 && init
	t_data* game_data = NULL;
	game_data = (t_data*)malloc(sizeof(t_data));
	if (game_data == NULL)
	{
		printf("Failed to allocation\n");
		return (1);
	}
	game_data->clear_req = 0;
	if (!init_main_map(game_data));
		copy_main_map(game_data, map1);
	game_data->round = 1;
	game_data->dist_dept = (float*)calloc(sizeof(float), SCREEN_WIDTH);
	if (game_data->dist_dept == NULL)
	{
		printf("Failed to allocation\n");
		free(game_data);
		return (1);
	}
	init_sprite(game_data);

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

	game_data->sound = (t_sound*)malloc(sizeof(t_sound));
	if (game_data->sound == NULL)
	{
		printf("sound init error\n");
		return (1);
	}

	// Initialize SDL
	// SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (1);
	}
	else
	{
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
		test_init_sound(game_data);

		// Create window
		// 윈도우 생성
		window = SDL_CreateWindow("minos labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, SDL_WINDOW_SHOWN);
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
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				printf("Failed to create renderer %s\n", SDL_GetError());
				return (1);
			}
			// 타이틀 화면
			game_data->title_texture = title_screen(renderer, "texture/minos_labyrinth_title2.bmp");
			game_data->end_texture = title_screen(renderer, "texture/thx.bmp");
			game_data->pick_item = title_screen(renderer, "texture/item_thread.bmp");
			game_data->key_map_texture = title_screen(renderer, "texture/key_map.bmp");
			game_data->fg_texture = title_screen(renderer, "texture/foreground2.bmp");

			// Fill the surface white
			// 화면을 흰색으로 채우기 NULL or SDL_RECT* << 크기지정 가능
			// SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			// 격자 화면 생성
			tile_grid(screenSurface, game_data);

			// surface to texture
			// 하나의 텍스쳐로 만드는 작업 하드웨어 렌더링(gpu)을 사용함
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, screenSurface);
			SDL_FreeSurface(screenSurface);
			
			// 뒷 배경 생성
			SDL_Surface* bg_surface = init_background(window);
			SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);
			SDL_FreeSurface(bg_surface);
			// game_data->wall_texture1 = load_texture(renderer, "texture/wall1.bmp");
			// printf("벽 이미지 정보 출력 %d %d\n", game_data->wall_texture1->w, game_data->wall_texture1->h);
			// 이미지 열기 함수
			// ft_load_texture(game_data);

			// Update the surface
			// 화면 업데이트
			// SDL_UpdateWindowSurface(window);

			// 데이터 저장
			game_data->window = window;
			game_data->texture = texture;
			game_data->bg_texture = bg_texture;
			game_data->renderer = renderer;
			game_data->player = player;

			// 게임 시작
			game(game_data);

			// Wait two seconds
			// SDL_Delay(2000);
		}
	}

	// 배경 텍스쳐 해제
	SDL_DestroyTexture(game_data->bg_texture);
	// 스프라이트 텍스쳐 해제
	// SDL_DestroyTexture(game_data->sp1_texture);
	SDL_DestroyTexture(game_data->title_texture);
	SDL_DestroyTexture(game_data->end_texture);
	SDL_DestroyTexture(game_data->fg_texture);

	// Destroy window
	// 윈도우 해제
	SDL_DestroyWindow(window);

	// SDL_Mixer bgm 해제
	Mix_FreeMusic(game_data->sound->bgm);
	// Quit SDL subsystems
	// SDL 끝내기
	SDL_Quit();

	// 데이터 해제
	free(player);
	free(game_data->dist_dept);
	free(game_data);
	return 0;
}