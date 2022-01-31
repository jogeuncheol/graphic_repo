#include "SDL_Project.h"

void	init_level2_player(t_data* game_data)
{
	t_player* player = game_data->player;

	player->p_rect.x =  9.5f * (float)TILE_SIZE;
	player->p_rect.y = 17.5f * (float)TILE_SIZE;
	player->p_rect.w = 10;
	player->p_rect.h = 10;
	//player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	//player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;
	player->angle = -90.0f;

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

void	init_level2_sprite(t_data* game_data)
{
	game_data->sprite[0].type = env_light; // 1 == light2
	game_data->sprite[0].visible = 1;
	game_data->sprite[0].x =  8.0f * (float)TILE_SIZE;
	game_data->sprite[0].y = 12.5f * (float)TILE_SIZE;
	game_data->sprite[1].type = env_light;
	game_data->sprite[1].visible = 1;
	game_data->sprite[1].x =  9.0f * (float)TILE_SIZE;
	game_data->sprite[1].y = 12.5f * (float)TILE_SIZE;
	game_data->sprite[2].type = env_light;
	game_data->sprite[2].visible = 1;
	game_data->sprite[2].x = 4.5f * (float)TILE_SIZE;
	game_data->sprite[2].y = 8.0f * (float)TILE_SIZE;
	game_data->sprite[3].type = env_light;
	game_data->sprite[3].visible = 1;
	game_data->sprite[3].x = 4.5f * (float)TILE_SIZE;
	game_data->sprite[3].y = 9.0f * (float)TILE_SIZE;
	game_data->sprite[4].type = env_light;
	game_data->sprite[4].visible = 1;
	game_data->sprite[4].x = 14.5f * (float)TILE_SIZE;
	game_data->sprite[4].y =  8.0f * (float)TILE_SIZE;
	game_data->sprite[5].type = env_light;
	game_data->sprite[5].visible = 1;
	game_data->sprite[5].x = 14.5f * (float)TILE_SIZE;
	game_data->sprite[5].y =  9.0f * (float)TILE_SIZE;
	game_data->sprite[6].type = env_light;
	game_data->sprite[6].visible = 1;
	game_data->sprite[6].x = 8.0f * (float)TILE_SIZE;
	game_data->sprite[6].y = 4.5f * (float)TILE_SIZE;
	game_data->sprite[7].type = env_light;
	game_data->sprite[7].visible = 1;
	game_data->sprite[7].x = 9.0f * (float)TILE_SIZE;
	game_data->sprite[7].y = 4.5f * (float)TILE_SIZE;

	game_data->sprite[8].type = env_object; // 0 == sprite_dbd
	game_data->sprite[8].visible = 1;
	game_data->sprite[8].x = 17.5f * (float)TILE_SIZE;
	game_data->sprite[8].y = 17.5f * (float)TILE_SIZE;

	game_data->sprite[9].type = env_object2; // 2 == skull
	game_data->sprite[9].visible = 1;
	game_data->sprite[9].x =  9.8f * (float)TILE_SIZE;
	game_data->sprite[9].y = 14.5f * (float)TILE_SIZE;
	game_data->sprite[10].type = env_object2;
	game_data->sprite[10].visible = 1;
	game_data->sprite[10].x = 10.5f * (float)TILE_SIZE;
	game_data->sprite[10].y =  6.2f * (float)TILE_SIZE;

	game_data->sprite[11].type = item_obj_thread;
	game_data->sprite[11].visible = 1;
	game_data->sprite[11].item_idx = 1;
	game_data->sprite[11].is_item = 1;
	game_data->sprite[11].interaction = 1;
	// game_data->sprite[11].name = strdup("item_thread");
	game_data->sprite[11].x = 8.5f * (float)TILE_SIZE;
	game_data->sprite[11].y = 8.5f * (float)TILE_SIZE;

	game_data->sprite[12].type = env_obj_table;
	game_data->sprite[12].visible = 1;
	game_data->sprite[12].item_idx = 1;
	game_data->sprite[12].interaction = 1;
	game_data->sprite[12].x = 16.5f * (float)TILE_SIZE;
	game_data->sprite[12].y = 13.5f * (float)TILE_SIZE;

	game_data->sprite[13].type = env_obj_horn;
	game_data->sprite[13].visible = 1;
	game_data->sprite[13].item_idx = 2;
	game_data->sprite[13].interaction = 1;
	game_data->sprite[13].x = 1.2f * (float)TILE_SIZE;
	game_data->sprite[13].y = 1.2f * (float)TILE_SIZE;

	game_data->sprite[14].type = item_obj_horn;
	game_data->sprite[14].visible = 1;
	game_data->sprite[14].item_idx = 2;
	game_data->sprite[14].is_item = 1;
	game_data->sprite[14].interaction = 1;
	// game_data->sprite[14].name = strdup("item_horn");
	game_data->sprite[14].x = 15.5f * (float)TILE_SIZE;
	game_data->sprite[14].y =  8.5f * (float)TILE_SIZE;
}

void	init_level3_player(t_data* game_data)
{
	t_player* player = game_data->player;

	if (game_data->sprite[player->inventory].item_idx == 1)
	{
		player->p_rect.x = 10.5f * (float)TILE_SIZE;
		player->p_rect.y =  8.5f * (float)TILE_SIZE;
		player->angle = 90.0f;
	}
	else
	{
		player->p_rect.x =  8.5f * (float)TILE_SIZE;
		player->p_rect.y = 18.5f * (float)TILE_SIZE;
		player->angle = -90.0f;
	}
	player->p_rect.w = 10;
	player->p_rect.h = 10;
	//player->arrow.x = player->p_rect.x + player->p_rect.w / 2;
	//player->arrow.y = player->p_rect.y + player->p_rect.h / 2;
	player->arrow.w = 1;
	player->arrow.h = 10;

	/* 플레이어 패딩 초기화 */
	player->p_padding_n = player->p_rect.y - 5;
	player->p_padding_s = player->p_rect.y + 5;
	player->p_padding_e = player->p_rect.x + 5;
	player->p_padding_w = player->p_rect.x - 5;

	player->velocity = 1.0f;
	player->is_map_visible = 0;
	player->is_key_map_visible = 0;

	/* 마지막에는 인벤토리를 초기화 하지 않음 */
	// player->inventory = 0;
}

void	init_level3_sprite(t_data* game_data)
{
	game_data->sprite[0].type = env_light; // 1 == light2
	game_data->sprite[0].visible = 1;
	game_data->sprite[0].x = 8.0f * (float)TILE_SIZE;
	game_data->sprite[0].y = 18.5f * (float)TILE_SIZE;
	game_data->sprite[1].type = env_light;
	game_data->sprite[1].visible = 1;
	game_data->sprite[1].x = 9.0f * (float)TILE_SIZE;
	game_data->sprite[1].y = 18.5f * (float)TILE_SIZE;
	game_data->sprite[2].type = env_light;
	game_data->sprite[2].visible = 0;
	game_data->sprite[2].x = 4.5f * (float)TILE_SIZE;
	game_data->sprite[2].y = 8.0f * (float)TILE_SIZE;
	game_data->sprite[3].type = env_light;
	game_data->sprite[3].visible = 0;
	game_data->sprite[3].x = 4.5f * (float)TILE_SIZE;
	game_data->sprite[3].y = 9.0f * (float)TILE_SIZE;
	game_data->sprite[4].type = env_light;
	game_data->sprite[4].visible = 0;
	game_data->sprite[4].x = 14.5f * (float)TILE_SIZE;
	game_data->sprite[4].y = 8.0f * (float)TILE_SIZE;
	game_data->sprite[5].type = env_light;
	game_data->sprite[5].visible = 0;
	game_data->sprite[5].x = 14.5f * (float)TILE_SIZE;
	game_data->sprite[5].y = 9.0f * (float)TILE_SIZE;
	game_data->sprite[6].type = env_light;
	game_data->sprite[6].visible = 0;
	game_data->sprite[6].x = 8.0f * (float)TILE_SIZE;
	game_data->sprite[6].y = 4.5f * (float)TILE_SIZE;
	game_data->sprite[7].type = env_light;
	game_data->sprite[7].visible = 0;
	game_data->sprite[7].x = 9.0f * (float)TILE_SIZE;
	game_data->sprite[7].y = 4.5f * (float)TILE_SIZE;

	game_data->sprite[8].type = env_object; // 0 == sprite_dbd
	game_data->sprite[8].visible = 1;
	game_data->sprite[8].x = 8.5f * (float)TILE_SIZE;
	game_data->sprite[8].y = 2.5f * (float)TILE_SIZE;

	game_data->sprite[9].type = env_object2; // 2 == skull
	game_data->sprite[9].visible = 1;
	game_data->sprite[9].x = 6.8f * (float)TILE_SIZE;
	game_data->sprite[9].y = 15.2f * (float)TILE_SIZE;
	game_data->sprite[10].type = env_object2;
	game_data->sprite[10].visible = 1;
	game_data->sprite[10].x = 12.5f * (float)TILE_SIZE;
	game_data->sprite[10].y = 8.2f * (float)TILE_SIZE;

	game_data->sprite[11].type = item_obj_thread;
	game_data->sprite[11].visible = 0;
	game_data->sprite[11].item_idx = 1;
	game_data->sprite[11].is_item = 1;
	game_data->sprite[11].interaction = 1;
	// game_data->sprite[11].name = strdup("item_thread");
	game_data->sprite[11].x = 8.5f * (float)TILE_SIZE;
	game_data->sprite[11].y = 8.5f * (float)TILE_SIZE;

	game_data->sprite[12].type = env_obj_table;
	if (game_data->sprite[game_data->player->inventory].item_idx == 1)
	{
		game_data->sprite[12].visible = 1;
	}
	else
		game_data->sprite[12].visible = 0;
	game_data->sprite[12].item_idx = 1;
	game_data->sprite[12].interaction = 1;
	game_data->sprite[12].x =  8.5f * (float)TILE_SIZE;
	game_data->sprite[12].y = 18.5f * (float)TILE_SIZE;

	game_data->sprite[13].type = env_obj_horn;
	if (game_data->sprite[game_data->player->inventory].item_idx == 2)
	{
		game_data->sprite[13].visible = 1;
	}
	else
		game_data->sprite[13].visible = 0;
	game_data->sprite[13].item_idx = 2;
	game_data->sprite[13].interaction = 1;
	game_data->sprite[13].x = 10.5f * (float)TILE_SIZE;
	game_data->sprite[13].y =  8.5f * (float)TILE_SIZE;

	game_data->sprite[14].type = item_obj_horn;
	game_data->sprite[14].visible = 0;
	game_data->sprite[14].item_idx = 2;
	game_data->sprite[14].is_item = 1;
	game_data->sprite[14].interaction = 1;
	// game_data->sprite[14].name = strdup("item_horn");
	game_data->sprite[14].x = 15.5f * (float)TILE_SIZE;
	game_data->sprite[14].y = 8.5f * (float)TILE_SIZE;
}