#pragma once
#ifndef SDL_Project_H
#define SDL_Project_H

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <math.h>
#include "audio.h"
#include "maps.h"

#define SDL_AUDIO_ALLOW_CHANGES SDL_AUDIO_ALLOW_FREQUENCY_CHANGE | SDL_AUDIO_ALLOW_CHANNELS_CHANGE

#define RESOLUTION_WIDTH	1280
#define RESOLUTION_HEIGHT	720

// 타일 크기
#define TILE_SIZE	64

// 화면 크기 지정
#define SCREEN_WIDTH	640// TILE_SIZE * 15
#define SCREEN_HEIGHT	360// TILE_SIZE * 10

#define map_h 20
#define map_w 20

// 월드 크기
#define WORLD_WIDTH		TILE_SIZE * map_w
#define WORLD_HEIGHT	TILE_SIZE * map_h

//static int map_h = 10;
//static int map_w = 15;
static int map_old[10][15] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 2, 2, 0 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 0, 1, 1, 2, 0, 2, 1, 0, 1, 0, 0, 2 },
	{ 2, 0, 1, 0, 0, 0, 2, 0, 2, 2, 0, 2, 0, 0, 2 },
	{ 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2, 1, 0, 2 },
	{ 1, 0, 0, 2, 2, 0, 1, 0, 1, 0, 0, 0, 0, 0, 2 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 0, 0, 0 },
	{ 2, 0, 0, 2, 1, 1, 1, 0, 1, 0, 1, 0, 2, 0, 0 },
	{ 2, 0, 2, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 2 },
	{ 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 0 }
};
static int map1[20][20] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 2, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 2, 2, 2, 2, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 2, 2, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1 },
	{ 2, 0, 1, 0, 2, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1 },
	{ 2, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1 },
	{ 2, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 },
	{ 2, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 0, 1, 2, 0, 0, 2, 1, 0, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 0, 1, 2, 2, 2, 1, 1, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};
static int map2[20][20] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

enum object_type
{
	env_object = 0,
	env_light,
	env_object2,
	item_obj_thread,
	item_obj_horn,
	enemy,
	env_obj_column,
	env_obj_table,
	env_obj_horn
};

typedef struct s_config
{
	float	h_fov;
	float	v_fov;
	int	texture;
}	t_config;

typedef struct s_sprite
{
	/* sprite name */
	char* name;
	/* collection, enemy, item ... */
	int type;
	/* item */
	int is_item;
	int item_idx;
	/* sprite visible */
	int visible;
	/* interaction */
	int interaction;
	/* position */
	float x;
	float y;
	/* texture */
	SDL_Texture* texture;
}	t_sprite;

typedef struct s_player
{
	SDL_FRect	p_rect;				// 플레이어 실수 좌표
	SDL_Rect	player_cord;		// 사각형 그리기용 정수 좌표
	SDL_FRect	arrow;
	float		angle;

	int			move_forword_back;
	int			move_left_right;
	int			cardinal_point;

	float		next_hx; // 수평격자의 첫 좌표
	float		next_hy;
	float		next_vx; // 수직격자의 첫 좌표
	float		next_vy;
	float		ray_hx;
	float		ray_hy;
	float		ray_vx;
	float		ray_vy;

	/* 플레이어에 패딩을 주어서 벽 충돌 감지 + 미끄러지기 */
	float		p_padding_n;
	float		p_padding_s;
	float		p_padding_e;
	float		p_padding_w;

	float		velocity;
	int			is_map_visible;
	int			is_key_map_visible;

	/* 얻은 아이템 */
	int			inventory;
}	t_player;

typedef struct s_sound
{
	Mix_Music* title;
	Mix_Music* bgm;
	Mix_Music* ending;
	Mix_Chunk* walk;
	Mix_Chunk* get_item;
	Mix_Chunk* use_item;
}	t_sound;

typedef struct s_data
{
	SDL_Window*		window;
	SDL_Surface*	surface;
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	SDL_Texture*	title_texture;
	SDL_Texture*	end_texture;
	SDL_Texture*	pick_item;
	SDL_Texture*	bg_texture;
	SDL_Texture*	wall_texture1;
	SDL_Surface*	wall_surface;
	SDL_Texture*	sp1_texture;
	SDL_Surface*	sp1_surface;
	SDL_Texture*	key_map_texture;
	t_player*		player;
	t_sound*		sound;
	t_config		config;

	int**			map;
	int				round;

	int				title;
	int				clear_req;

	/* test code */
	unsigned char*	image1;
	float			r_radian;
	float			cos_val;
	float			ray_x;
	float			ray_y;
	int				hit_v;
	int				hit_h;

	/* sprite test code */
	t_sprite		sprite[20];
	int visible_hit_v[map_h][map_w];
	int visible_hit_h[map_h][map_w];
	int visible_map[map_h][map_w];
	int visible_sprite[map_h][map_w];
	float* sprite_array; // [dst, angle, type] * sprite_count
	int sprite_count;
	float* dist_dept;
	int* sprite_idx;
	int s_idx_arr[20];

	/* item */
	t_sprite		item[10];
	int is_cursor;
	int	cursor_x;
	int cursor_y;

}	t_data;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
	float	shader;
}	t_color;

void			init_player(t_player* player);

int				move_player(t_player* game_data);
void			key_up(t_player* p);
void			key_down(t_player* p);

void			draw_line(t_data* game_data);

void			horizon_ray(t_data* g_data, float ray_angle);
void			vertical_ray(t_data* g_data, float ray_angle);

void			Rendering(t_data* game_data);
void			draw_short_ray(t_data* g_data);
void			draw_map(t_data* game_data);

void			draw_key_map(t_data* game_data);

SDL_Surface*	init_background(SDL_Window* window);
void			map_over_screen(t_data* game_data);

SDL_Surface*	load_texture(SDL_Renderer* renderer, char* file);
SDL_Texture*	title_screen(SDL_Renderer* renderer, const char* file);

/* test item */
void			get_item(t_data* game_data);
void			drop_item(t_data* game_data);
void			draw_pickup_item(t_data* game_data);
void			moving_pick_item(t_data* game_data);
void			draw_cursor(t_data* game_data);
void			interaction_obj(t_data* game_data);

/* test sound */
int				test_init_sound(t_data* game_data);

/* sprite code */
void			test_spirte(t_data* game_data);
void			init_sprite(t_data* game_data);
// void	draw_sprite(t_data* game_data);
void			reset_visible_sprite_map(t_data* game_data);
void			test_sprite_checker(t_data* game_data, int x, int y, char c);
void			set_sprite_map(t_data* game_data);
void			test_sprite_(t_data* game_data);
void			ft_sprite_calculate(t_data* game_data);
SDL_Texture*	test_sprite_texture(t_data* game_data, char* file);
void			test_draw_sprite_(t_data* game_data);
void			test_draw_sprite_2(t_data* game_data);
void			inner_product(t_data* game_data);
void			zeromem_sprite(t_data* game_data);

/* test code */
void			test_draw_texture(t_data* game_data);
void			ft_load_texture(t_data* game_data);
void			test_wall_texel(t_data* game_data, int x, int y, int width_idx, int h, int* texture1);
int				test_play_sound();

Uint32			set_color_from_texture(SDL_Rect* rect, t_data* game_data, int x, int y, int h, float shader, int* texture1);
float			set_color_shader(int wall_h);
int				set_texture(t_data* game_data);

/* map */
int				copy_main_map(t_data* game_data, int (*map)[map_w]);

/* level */
int				check_level(t_data* game_data);
void			init_level2_player(t_data* game_data);
void			init_level2_sprite(t_data* game_data);
void			init_level3_player(t_data* game_data);
void			init_level3_sprite(t_data* game_data);

#endif