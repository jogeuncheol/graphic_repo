#include "SDL_Project.h"

void	draw_pickup_item(t_data *game_data)
{
	int x = RESOLUTION_WIDTH / 3 * 2;
	int y = RESOLUTION_HEIGHT / 4 * 3;
	SDL_Rect sRect = { 0, 0, 512, 512 };
	SDL_Rect dRect = { x, y, 256 + 128, 256 + 128 };

	if (game_data->player->inventory)
	{
		dRect.x += cosf(game_data->r_radian * 4.0f) * 20;
		dRect.y += sinf(game_data->r_radian * 8.0f) * 20;
		SDL_RenderCopy(game_data->renderer, game_data->pick_item, &sRect, &dRect);
	}
}

/* f를 누르면 함수 실행 */
void	get_item(t_data *game_data)
{
	t_player* player = game_data->player;
	int idx = 0;

	/* 아이템인 경우 커서 생성 코드 사용 */
	for (int i = 0; i < game_data->sprite_count; i++)
	{
		idx = game_data->s_idx_arr[i];
		if (game_data->player->inventory == 0 && game_data->sprite[idx].is_item == 1)
		{
			if (game_data->pick_item != NULL)
				SDL_DestroyTexture(game_data->pick_item);
			if ((int)floor(player->arrow.x / TILE_SIZE) == (int)floor(game_data->sprite[idx].x / TILE_SIZE)
				&& (int)floor(player->arrow.y / TILE_SIZE) == (int)floor(game_data->sprite[idx].y / TILE_SIZE))
			{
				if (game_data->sprite[idx].item_idx == 1)
					game_data->pick_item = title_screen(game_data->renderer, "texture/item_thread.bmp");
				else if (game_data->sprite[idx].item_idx == 2)
					game_data->pick_item = title_screen(game_data->renderer, "texture/item_horn.bmp");
				game_data->player->inventory = idx;
				game_data->sprite[idx].visible = 0;
				printf("get item :: %d\n", game_data->sprite[idx].item_idx);
				printf("pick_item :: %p\n", game_data->pick_item);
			}
		}
	}
}

void	interaction_obj(t_data* game_data)
{
	t_player* player = game_data->player;
	int idx = 0;

	/* game_data->is_cursor == 1 이고 F 를 누른 경우 */
	for (int i = 0; i < game_data->sprite_count; i++)
	{
		idx = game_data->s_idx_arr[i];
		if (player->inventory && game_data->sprite[idx].interaction == 1)
		{
			/* arrow.x, y 와 cursor.x, y 생각해보기 */
			if ((int)floor(game_data->sprite[idx].x / TILE_SIZE) == game_data->cursor_x
				&& (int)floor(game_data->sprite[idx].y / TILE_SIZE) == game_data->cursor_y)
			{
				if (game_data->sprite[player->inventory].item_idx == game_data->sprite[idx].item_idx)
					game_data->clear_req = game_data->round;
			}
		}
	}
}

/* del 누르면 아이템 버리기 */
void	drop_item(t_data* game_data)
{
	int idx;
	float rad;

	if (game_data->player->inventory)
	{
		idx = game_data->player->inventory;
		rad = game_data->player->angle * M_PI / 180.0f;
		game_data->sprite[idx].x = game_data->player->p_rect.x + (cos(rad) * 5);
		game_data->sprite[idx].y = game_data->player->p_rect.y + (sin(rad) * 5);
		game_data->sprite[idx].visible = 1;
		game_data->player->inventory = 0;
	}
}

void	moving_pick_item(t_data* game_data)
{
	static int angle = 0;
	float rad = angle * M_PI / 180.0f;

	game_data->r_radian = rad;
	angle++;
	if (angle > 360 || angle < 0) angle = 0;
}

/* 아이템 :: 커서 띄우기 */
void	draw_cursor(t_data *game_data)
{
	t_player* player = game_data->player;
	SDL_Rect rect = { RESOLUTION_WIDTH / 2 - 5, RESOLUTION_HEIGHT / 2 - 5, 10, 10 };
	int idx;

	game_data->is_cursor = 0;
	game_data->cursor_x = 0;
	game_data->cursor_y = 0;
	for (int i = 0; i < game_data->sprite_count; i++)
	{
		idx = game_data->s_idx_arr[i];
		if (game_data->sprite[idx].interaction == 1)
		{
			if ((int)floor(player->arrow.x / TILE_SIZE) == (int)floor(game_data->sprite[idx].x / TILE_SIZE)
				&& (int)floor(player->arrow.y / TILE_SIZE) == (int)floor(game_data->sprite[idx].y / TILE_SIZE))
			{
				SDL_SetRenderDrawColor(game_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
				if (game_data->sprite[idx].visible == 1)
				{
					SDL_RenderFillRect(game_data->renderer, &rect);
					game_data->is_cursor = 1;
					game_data->cursor_x = (int)floor(player->arrow.x / TILE_SIZE);
					game_data->cursor_y = (int)floor(player->arrow.y / TILE_SIZE);
				}
			}
		}
	}
}