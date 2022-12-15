#include "SDL_Project.h"
#include "sprite.h"

void	zeromem_sprite(t_data* game_data)
{
	const int count = sizeof(game_data->sprite) / sizeof(t_sprite);

	for (int i = 0; i < count; i++)
	{
		game_data->sprite[i].interaction = 0;
		game_data->sprite[i].is_item = 0;
		game_data->sprite[i].item_idx = 0;
		game_data->sprite[i].name = NULL;
		game_data->sprite[i].texture = NULL;
		game_data->sprite[i].type = -1;
		game_data->sprite[i].visible = 0;
		game_data->sprite[i].x = -1;
		game_data->sprite[i].y = -1;
	}
}

void	init_sprite_light(t_data* game_data);
void	init_sprite(t_data* game_data)
{
	game_data->sprite[0].type = env_object; // 0 == sprite_dbd
	game_data->sprite[0].visible = 1;
	game_data->sprite[0].x = 11.5f * (float)TILE_SIZE;
	game_data->sprite[0].y = 11.5f * (float)TILE_SIZE;

	game_data->sprite[3].type = env_object2; // 2 == skull
	game_data->sprite[3].visible = 1;
	game_data->sprite[3].x = 1.2f * (float)TILE_SIZE;
	game_data->sprite[3].y = 6.8f * (float)TILE_SIZE;

	game_data->sprite[4].type = item_obj_thread;
	game_data->sprite[4].visible = 1;
	game_data->sprite[4].item_idx = 1;
	game_data->sprite[4].is_item = 1;
	game_data->sprite[4].interaction = 1;
	// game_data->sprite[4].name = strdup("item_thread");
	game_data->sprite[4].x = 8.5f * (float)TILE_SIZE;
	game_data->sprite[4].y = 8.5f * (float)TILE_SIZE;

	game_data->sprite[7].type = env_obj_column;
	game_data->sprite[7].visible = 1;
	game_data->sprite[7].x = 18.5f * (float)TILE_SIZE;
	game_data->sprite[7].y = 18.5f * (float)TILE_SIZE;

	game_data->sprite[9].type = env_obj_table;
	game_data->sprite[9].visible = 1;
	game_data->sprite[9].item_idx = 1;
	game_data->sprite[9].interaction = 1;
	game_data->sprite[9].x = 2.5f * (float)TILE_SIZE;
	game_data->sprite[9].y = 13.5f * (float)TILE_SIZE;

	game_data->sprite[10].type = env_obj_horn;
	game_data->sprite[10].visible = 1;
	game_data->sprite[10].item_idx = 2;
	game_data->sprite[10].interaction = 1;
	game_data->sprite[10].x = 1.5f * (float)TILE_SIZE;
	game_data->sprite[10].y = 14.5f * (float)TILE_SIZE;

	game_data->sprite[11].type = item_obj_horn;
	game_data->sprite[11].visible = 1;
	game_data->sprite[11].item_idx = 2;
	game_data->sprite[11].is_item = 1;
	game_data->sprite[11].interaction = 1;
	// game_data->sprite[11].name = strdup("item_horn");
	game_data->sprite[11].x = 13.5f * (float)TILE_SIZE;
	game_data->sprite[11].y = 10.5f * (float)TILE_SIZE;
	init_sprite_light(game_data);
}

void	init_sprite_light(t_data *game_data)
{
	game_data->sprite[1].type = env_light; // 1 == light2
	game_data->sprite[1].visible = 1;
	game_data->sprite[1].x = 1.0f * (float)TILE_SIZE;
	game_data->sprite[1].y = 4.5f * (float)TILE_SIZE;
	game_data->sprite[2].type = env_light;
	game_data->sprite[2].visible = 1;
	game_data->sprite[2].x = 2.0f * (float)TILE_SIZE;
	game_data->sprite[2].y = 5.5f * (float)TILE_SIZE;
	game_data->sprite[5].type = env_light;
	game_data->sprite[5].visible = 1;
	game_data->sprite[5].x = 4.0f * (float)TILE_SIZE;
	game_data->sprite[5].y = 11.5f * (float)TILE_SIZE;
	game_data->sprite[6].type = env_light;
	game_data->sprite[6].visible = 1;
	game_data->sprite[6].x = 3.0f * (float)TILE_SIZE;
	game_data->sprite[6].y = 11.5f * (float)TILE_SIZE;
	game_data->sprite[8].type = env_light;
	game_data->sprite[8].visible = 1;
	game_data->sprite[8].x = 3.0f * (float)TILE_SIZE;
	game_data->sprite[8].y = 9.5f * (float)TILE_SIZE;
}

void	select_texture(t_data* game_data, int **texture, int count)
{
	if (game_data->sprite_array[count * 3 + 2] == env_object)
		*texture = sprite_dbd;
	else if (game_data->sprite_array[count * 3 + 2] == env_light)
		*texture = light2;
	else if (game_data->sprite_array[count * 3 + 2] == env_object2)
		*texture = sprite_skull_1;
	else if (game_data->sprite_array[count * 3 + 2] == item_obj_thread)
		*texture = item_thread;
	else if (game_data->sprite_array[count * 3 + 2] == env_obj_column)
		*texture = env_column;
	else if (game_data->sprite_array[count * 3 + 2] == env_obj_table)
		*texture = env_table;
	else if (game_data->sprite_array[count * 3 + 2] == env_obj_horn)
		*texture = env_horn1;
	else if (game_data->sprite_array[count * 3 + 2] == item_obj_horn)
		*texture = item_horn1;
}

void init_visible_map(t_data *game_data)
{
	int x;
	int y;

	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			game_data->visible_hit_v[y][x] = 0;
			game_data->visible_hit_h[y][x] = 0;
			game_data->visible_map[y][x] = 0;
			game_data->visible_sprite[y][x] = 0;
			x++;
		}
		y++;
	}
}

void check_visible_map(t_data* game_data)
{
	int x;
	int y;
	/*
		printf("==============hit_m==========\n");
		y = 0;
		while (y < MAP_ROWS)
		{
			x = 0;
			while (x < MAP_COLS)
			{
				printf("%d ", param->visible_map[y][x]);
				x++;
			}
			printf("\n");
			y++;
		}
		printf("=============================\n");
	*/
	//	printf("=============sprite==========\n"); //05_05 save
	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			game_data->visible_sprite[y][x] = game_data->visible_map[y][x] && game_data->map[y][x];
			//			printf("%d ", param->visible_sprite[y][x]);
			//			printf("%d ", param->map[y][x]);
			x++;
		}
		//		printf("\n");
		y++;
	}
	//	printf("=============================\n");

}

void ft_sprite_swap(t_data* game_data, int i, int max)
{
	float tmp_dst;
	float tmp_angle;
	float type;

	tmp_dst = game_data->sprite_array[i * 3];
	tmp_angle = game_data->sprite_array[i * 3 + 1];
	type = game_data->sprite_array[i * 3 + 2];
	game_data->sprite_array[i * 3] = game_data->sprite_array[max];
	game_data->sprite_array[i * 3 + 1] = game_data->sprite_array[max + 1];
	game_data->sprite_array[i * 3 + 2] = game_data->sprite_array[max + 2];
	game_data->sprite_array[max] = tmp_dst;
	game_data->sprite_array[max + 1] = tmp_angle;
	game_data->sprite_array[max + 2] = type;
}

void ft_sprite_sort(t_data* game_data)
{
	int max;
	int i;
	int j;

	i = 0;
	while (i < game_data->sprite_count - 1)
	{
		j = i + 1;
		max = i * 3;
		while (j < game_data->sprite_count)
		{
			if (game_data->sprite_array[max] < game_data->sprite_array[j * 3])
			{
				max = j * 3;
			}
			j++;
		}
		ft_sprite_swap(game_data, i, max);
		i++;
	}
}

void test_sprite_array(t_data* game_data)
{
	int x;
	int y;
	float dx;
	float dy;
	int i, idx;
	float rad = game_data->player->angle * M_PI / 180.0f;

	i = 0;
	while (i < game_data->sprite_count)
	{
		idx = game_data->s_idx_arr[i];
		dx = game_data->sprite[idx].x - game_data->player->p_rect.x;
		dy = game_data->sprite[idx].y - game_data->player->p_rect.y;
		game_data->sprite_array[i * 3] = dx * cos(rad) + dy * sin(rad);
		game_data->sprite_array[i * 3 + 1] = atan2(dy, dx) - rad;
		game_data->sprite_array[i * 3 + 2] = game_data->sprite[idx].type;
		i++;
	}
}

void ft_sprite_array(t_data* game_data)
{
	int x;
	int y;
	float dx;
	float dy;
	int i, j;
	float rad = game_data->player->angle * M_PI / 180.0f;

	i = 0;
	j = 0;
	while (i < game_data->sprite_count)
	{
		x = (int)floor(game_data->sprite[j].x / TILE_SIZE);
		y = (int)floor(game_data->sprite[j].y / TILE_SIZE);
		if (game_data->visible_sprite[y][x] == 1)
		{
			dx = game_data->sprite[j].x - game_data->player->p_rect.x;
			dy = game_data->sprite[j].y - game_data->player->p_rect.y;
			game_data->sprite_array[i * 3] = dx * cos(rad) + dy * sin(rad);
			game_data->sprite_array[i * 3 + 1] = atan2(dy, dx) - rad;
			game_data->sprite_array[i * 3 + 2] = game_data->sprite[j].type;
			i++;
		}
		j++;
	}

	//y = 0;
	//while (y < map_h)
	//{
	//	x = 0;
	//	while (x < map_w)
	//	{
	//		if (game_data->visible_sprite[y][x] == 1)
	//		{
	//			dx = (x * TILE_SIZE) - game_data->player->p_rect.x;
	//			dy = (y * TILE_SIZE + (TILE_SIZE / 2)) - game_data->player->p_rect.y;
	//			game_data->sprite_array[i] = dx * cos(rad) + dy * sin(rad);
	//			game_data->sprite_array[i + 1] = atan2(dy, dx) - rad;
	//			game_data->sprite_array[i + 2] = 0;
	//			i = i + 3;
	//		}
	//		x++;
	//	}
	//	y++;
	//}
}

void ft_check_sprite(t_data* game_data)
{
	int x;
	int y;

	game_data->sprite_count = 0;
	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			if (game_data->visible_sprite[y][x] == 1)
				game_data->sprite_count++;
			x++;
		}
		y++;
	}
	game_data->sprite_array = (float*)malloc(sizeof(float) * game_data->sprite_count * 3);
}

void ft_sprite_calculate(t_data* game_data)
{
	//ft_check_sprite(game_data);
	//if (game_data->sprite_count)
	//{
	//	ft_sprite_array(game_data);
	//	ft_sprite_sort(game_data);
	//}
	if (game_data->sprite_count)
	{
		test_sprite_array(game_data);
		ft_sprite_sort(game_data);
	}
}

void ft_sprite(t_data* game_data)
{
	float p_s_dst;
	float s_angle;
	float sprite_x;
	float sprite_y;
	float dx;
	float dy;
	int x;
	int y;

	ft_sprite_calculate(game_data);
	int count = 0;
	while (count < game_data->sprite_count)
	{
		p_s_dst = game_data->sprite_array[count * 2];
		s_angle = game_data->sprite_array[count * 2 + 1];
		int l = ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180)) * tan(s_angle);

		/*draw sprite*/
		if (p_s_dst > 0)
		{
			//			printf("l : %d\n", l);
			int h;
			int w;
			int i = -1;
			h = TILE_SIZE * 400 / p_s_dst;
			w = h;
			h = h / 2;
			l = SCREEN_WIDTH / 2 + l - (w / 2);
			//			printf("l : %d\n", l);

			int left_i = 0;
			int right_i = 0;
			int y;
			while (i < w)
			{
				int z = 0;
				i++;
				y = i * (float)TILE_SIZE / w;
				if (l + i > SCREEN_WIDTH || l + i < 0) continue;
				if (p_s_dst > game_data->dist_dept[l + i]) continue;
				h = w / 2;
				//				printf("l + i : %d\n", l + i);
				while (h > 0)
				{
					h--;
					int x = (z++) * ((float)TILE_SIZE / w);
					if (h >SCREEN_HEIGHT / 2 - 1) continue;
					int color = 0xFFFF00;
					if (color != 0x000000)
					{
						
						// mlx_pixel_put(param->mlx_ptr, param->win_ptr, WINDOW_WIDTH + l + i, WINDOW_HEIGHT / 2 - h, color);
						// param->half.data[l + i + (int)(floor(SCREEN_HEIGHT / 2) - h) * SCREEN_WIDTH] = color;
					}
					if (color != 0x000000)
					{
						// SDL_RenderDrawRect();
						SDL_Rect s_rect;
						s_rect.x = -10;
						s_rect.y = -20;
						s_rect.w = 20;
						s_rect.h = 30;
						SDL_FillRect(game_data->wall_surface, &s_rect, color);
						// mlx_pixel_put(param->mlx_ptr, param->win_ptr, WINDOW_WIDTH + l + i, WINDOW_HEIGHT / 2 + h, color);
						// param->half.data[l + i + (int)(floor(SCREEN_HEIGHT / 2) + h) * SCREEN_WIDTH] = color;
					}
				}
			}
			//			printf("i : %d\n", i);
		}
		count++;
	}
	free(game_data->sprite_array);
}

void	reset_visible_sprite_map(t_data *game_data)
{
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			game_data->visible_sprite[i][j] = 0;
			game_data->visible_hit_h[i][j] = 0;
			game_data->visible_hit_v[i][j] = 0;
		}
	}
}

void	set_sprite_map(t_data *game_data)
{
	for (int i = 0; i < map_h; i++)
	{
		for (int j = 0; j < map_w; j++)
		{
			if (game_data->visible_hit_h[i][j] && game_data->visible_hit_v[i][j])
				game_data->visible_sprite[i][j] = 1;
		}
	}
}

void	inner_product(t_data* game_data)
{
	const int count = sizeof(game_data->sprite) / sizeof(t_sprite);
	float px, py, sx, sy, dx, dy;
	float rad = game_data->player->angle * M_PI / 180.0f;
	float inner_product;
	// int* s_idx;
	
	// s_idx = (int*)calloc(count, sizeof(int));
	game_data->sprite_count = 0;
	px = game_data->player->p_rect.x;
	py = game_data->player->p_rect.y;
	for (int i = 0; i < count; i++)
	{
		if (game_data->sprite[i].visible == 0) // <-- 위치 맘에 안듬
			continue;
		sx = game_data->sprite[i].x;
		sy = game_data->sprite[i].y;
		dx = sx - px;
		dy = sy - py;
		inner_product = dx * cos(rad) + dy * sin(rad);
		if (inner_product >= 0)
		{
			game_data->s_idx_arr[game_data->sprite_count] = i;
			game_data->sprite_count++;
		}
	}
	// free(s_idx);
	if (game_data->sprite_count)
		game_data->sprite_array = (float*)malloc(sizeof(float) * game_data->sprite_count * 3);
}

void	test_sprite_checker(t_data *game_data, int x, int y, char c)
{
	int count = sizeof(game_data->sprite) / sizeof(t_sprite);
	for (int i = 0; i < count; i++)
	{
		if (x == (int)floor(game_data->sprite[i].x / TILE_SIZE) && y == (int)floor(game_data->sprite[i].y / TILE_SIZE))
		{
			game_data->visible_sprite[y][x] = 1;
		}
	}
}

void	test_sprite_(t_data* game_data)
{
	t_player* p = game_data->player;
	float p_s_dist;
	float sprite_h;
	float rad;
	int s_width_idx;
	SDL_FRect s_rect;
	SDL_Point point[2];

	for (int count = 0; count < game_data->sprite_count; count++)
	{
		int* texture = light2;
		p_s_dist = game_data->sprite_array[count * 2];
		rad = game_data->sprite_array[count * 2 + 1];
		s_width_idx = ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180.0f)) * tan(rad);
		sprite_h = TILE_SIZE * ((SCREEN_WIDTH * 0.85f) / p_s_dist);
		s_width_idx = SCREEN_WIDTH / 2 + s_width_idx - (sprite_h / 2);

		s_rect.x = s_width_idx;
		s_rect.y = (SCREEN_HEIGHT - sprite_h) / 2;
		s_rect.w = 2;
		s_rect.h = 1; // sprite_h;
		float shader = set_color_shader(sprite_h);
		for (int i = 0; i < sprite_h; i += 1)
		{
			s_rect.x = s_width_idx + i;
			if (s_rect.x < 0 || s_rect.x > SCREEN_WIDTH) continue;
			if (p_s_dist > game_data->dist_dept[s_width_idx + i]) continue;
			/* 테스트 코드 : 텍스쳐 */
			int x = 0;
			int y = 0;
			int z = 0;
			// int pixel = (i * 512 + j) * 3;
			int r = 0; //texture1[pixel + 0];
			int g = 0; //texture1[pixel + 1];
			int b = 0; //texture1[pixel + 2];

			int h = sprite_h / 2;
			y = i * (float)TILE_SIZE / sprite_h;
			while (h > 0)
			{
				h--;
				x = (z++) * ((float)TILE_SIZE / sprite_h);
				if (h > SCREEN_HEIGHT / 2 - 1) continue;

				point[0].x = s_width_idx + i;
				point[0].y = (int)(floor(SCREEN_HEIGHT / 2) - h);
				point[1].x = s_width_idx + i + 1;
				point[1].y = (int)(floor(SCREEN_HEIGHT / 2) - h);
				Uint32 color = set_color_from_texture(&s_rect, game_data, x, y, h, shader, texture);
				if (color != 0)
					SDL_RenderDrawPoints(game_data->renderer, point, 2);
				
//				if (color != 0)
//					SDL_FillRect(game_data->wall_surface, &s_rect, SDL_MapRGB(game_data->wall_surface->format, 0xFF, 0xFF, 0x00));
				color = set_color_from_texture(&s_rect, game_data, ((TILE_SIZE - 1) - x), y, -h, shader, texture);
				point[0].y = (int)(floor(SCREEN_HEIGHT / 2) + h);
				point[1].y = (int)(floor(SCREEN_HEIGHT / 2) + h);
				if (color != 0)
					SDL_RenderDrawPoints(game_data->renderer, point, 2);
//				if (color != 0)
//					SDL_FillRect(game_data->wall_surface, &s_rect, SDL_MapRGB(game_data->wall_surface->format, 0xFF, 0xFF, 0x00));
			}
		}
	}
}

void	test_draw_sprite_(t_data *game_data)
{
	float p_s_dist;
	int sprite_h;
	float rad;
	int s_width_idx;
	SDL_Rect s_rect = {0, 0, 2, 2};
	int x = 0;
	int y = 0;
	int z = 0;
	int h = 0;
	float shader;
	Uint32 color;

	for (int count = 0; count < game_data->sprite_count; count++)
	{
		int* texture = NULL;
		select_texture(game_data, &texture, count);

		p_s_dist = game_data->sprite_array[count * 3];
		rad = game_data->sprite_array[count * 3 + 1];
		s_width_idx = ((SCREEN_WIDTH / 2) / tan(game_data->config.h_fov * M_PI / 180.0f)) * tan(rad);
		sprite_h = TILE_SIZE * ((SCREEN_WIDTH * game_data->config.v_fov) / p_s_dist);
		s_width_idx = SCREEN_WIDTH / 2 + s_width_idx - (sprite_h / 2);

		if (s_width_idx > SCREEN_WIDTH || s_width_idx + sprite_h < 0)
			continue;
		if (sprite_h > 100000000) continue;

		shader = set_color_shader(sprite_h);
		z = 0;
		for (h = (sprite_h / 2) - 1; h > 0; h -= 1)
		{
			x = (z) * ((float)TILE_SIZE / sprite_h);
			z += 1;
			if (h > SCREEN_HEIGHT / 2 - 1) continue;

			for (int i = 0; i < sprite_h; i += 2)
			{
				s_rect.x = s_width_idx + i;
				if (s_rect.x < 0 || s_rect.x > SCREEN_WIDTH) continue;
				if (p_s_dist > game_data->dist_dept[s_width_idx + i]) continue;
				y = i * (float)TILE_SIZE / sprite_h;
				color = set_color_from_texture(&s_rect, game_data, x, y, h, shader, texture);
				if (color != 0)
					SDL_FillRect(game_data->sp1_surface, &s_rect, color);
				color = set_color_from_texture(&s_rect, game_data, ((TILE_SIZE - 1) - x), y, -h, shader, texture);
				if (color != 0)
					SDL_FillRect(game_data->sp1_surface, &s_rect, color);
			}
		}
	}
	free(game_data->sprite_array);
	game_data->sprite_array = NULL;
}


void	test_draw_sprite_2(t_data* game_data)
{
	float p_s_dist;
	int sprite_h;
	float rad;
	int s_width_idx;
	SDL_Rect s_rect = { 0, 0, 2, 2 };
	int x = 0;
	int y = 0;
	int z = 0;
	int h = 0;
	float shader;
	Uint32 color;

	for (int count = 0; count < game_data->sprite_count; count++)
	{
		int* texture = light2;

		p_s_dist = game_data->sprite_array[count * 2];
		rad = game_data->sprite_array[count * 2 + 1];
		s_width_idx = ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180.0f)) * tan(rad);
		sprite_h = TILE_SIZE * ((SCREEN_WIDTH * 0.85f) / p_s_dist);
		s_width_idx = SCREEN_WIDTH / 2 + s_width_idx - (sprite_h / 2);

		//if (s_width_idx > SCREEN_WIDTH || s_width_idx + sprite_h < 0)
		//	continue;

		shader = set_color_shader(sprite_h);
		h = (sprite_h / 2) - 1;
		for (int i = 0; i < sprite_h; i += 2)
		{
			s_rect.x = s_width_idx + i;
			if (s_rect.x < 0 || s_rect.x > SCREEN_WIDTH) continue;
			if (p_s_dist > game_data->dist_dept[s_rect.x]) continue;
			z = 0;
			y = i * (float)TILE_SIZE / sprite_h;
			for (h = (sprite_h / 2) - 1; h > 0; h -= 2)
			{
				x = (z) * ((float)TILE_SIZE / sprite_h);
				z += 2;
				if (h > SCREEN_HEIGHT / 2 - 1) continue;
				color = set_color_from_texture(&s_rect, game_data, x, y, h, shader, texture);
				if (color != 0)
					SDL_FillRect(game_data->sp1_surface, &s_rect, color);
				color = set_color_from_texture(&s_rect, game_data, ((TILE_SIZE - 1) - x), y, -h, shader, texture);
				if (color != 0)
					SDL_FillRect(game_data->sp1_surface, &s_rect, color);
			}
		}
	}
}