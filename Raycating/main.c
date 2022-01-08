// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "SDL_Project.h"

/*
// Ÿ�� ũ��
const static int TILE_SIZE = 64;

// ȭ�� ũ�� ����
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
			if (map[(i - 1) / TILE_SIZE][j / TILE_SIZE] == 1) // ������ ��
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xa0, 0xa0, 0xa0));
			else // ������ �ٴ�
				SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
		}
	}
}

void	draw_line(t_data *game_data)
{
	// x1, y1 �÷��̾� ��ġ
	// x2, y2 �÷��̾ �ٶ󺸴� ������ ����
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

// �÷��̾� �ʱ� ��ġ�� ũ��
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

	/* �÷��̾� �е� �ʱ�ȭ */
	player->p_padding_n = player->p_rect.y - 5;
	player->p_padding_s = player->p_rect.y + 5;
	player->p_padding_e = player->p_rect.x + 5;
	player->p_padding_w = player->p_rect.x - 5;

	player->velocity = 0.8f;
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

void	game(t_data* game_data)
{
	int loop = 1;
	while (loop)
	{
		// �÷��̾� �̵�
		loop = move_player(game_data->player);
		// key_down(game_data->player);
		// key_up(game_data->player);

		// �÷��̾� ��ġ ǥ�ÿ� �簢��
		set_player_rect(game_data->player);
		// ������
		Rendering(game_data);
		SDL_Delay(1000 / 144);
	}
}

int main(int argc, char* args[])
{
	// ���� ���� ���� ����ü
	t_data* game_data = NULL;
	game_data = (t_data*)malloc(sizeof(t_data));
	if (game_data == NULL)
	{
		printf("Failed to allocation\n");
		return (1);
	}

	// The window we'll be rendering to
	// ������ ������
	SDL_Window* window = NULL;

	// The surface contained by the window
	// ������ ���� ȭ�� ������
	SDL_Surface* screenSurface = NULL;

	// ������ ������
	SDL_Renderer* renderer = NULL;

	// �÷��̾� ��ǥ ����ü SDL_Rect
	t_player* player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
	{
		printf("player init error\n");
		return (1);
	}
	init_player(player);

	// Initialize SDL
	// SDL �ʱ�ȭ
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		// Create window
		// ������ ����
		window = SDL_CreateWindow("SDL INIT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			// Get window surface
			// ȭ�� ����
			screenSurface = SDL_GetWindowSurface(window);
			
			// ������ ����
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer == NULL)
			{
				printf("Failed to create renderer %s\n", SDL_GetError());
				return (1);
			}

			// Fill the surface white
			// ȭ���� ������� ä��� NULL or SDL_RECT* << ũ������ ����
			// SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			// ���� ȭ�� ����
			tile_grid(screenSurface);

			// surface to texture
			// �ϳ��� �ؽ��ķ� ����� �۾� �ϵ���� ������(gpu)�� �����
			SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, screenSurface);
			SDL_FreeSurface(screenSurface);

			// Update the surface
			// ȭ�� ������Ʈ
			// SDL_UpdateWindowSurface(window);

			// ������ ����
			game_data->window = window;
			game_data->texture = texture;
			game_data->renderer = renderer;
			game_data->player = player;

			// ���� ����
			game(game_data);

			// Wait two seconds
			// SDL_Delay(2000);
		}
	}

	// �÷��̾� ������ ����
	free(player);

	// Destroy window
	// ������ ����
	SDL_DestroyWindow(window);

	// Quit SDL subsystems
	// SDL ������
	SDL_Quit();

	free(game_data);
	return 0;
}