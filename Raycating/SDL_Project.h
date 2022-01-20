#pragma once
#ifndef SDL_Project_H
#define SDL_Project_H

#include <SDL.h>
#include <stdio.h>
#include <math.h>

// 타일 크기
#define TILE_SIZE	64

// 화면 크기 지정
#define SCREEN_WIDTH	960// TILE_SIZE * 15
#define SCREEN_HEIGHT	640// TILE_SIZE * 10

// 월드 크기
#define WORLD_WIDTH		TILE_SIZE * map_w
#define WORLD_HEIGHT	TILE_SIZE * map_h

#define map_h 10
#define map_w 15

//static int map_h = 10;
//static int map_w = 15;
static int map[10][15] =
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

typedef struct s_sprite
{
	/* collection, enemy, item ... */
	int type;
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
	SDL_Rect	arrow;
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
}	t_player;

typedef struct s_data
{
	SDL_Window*		window;
	SDL_Surface*	surface;
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	SDL_Texture*	bg_texture;
	SDL_Texture*	wall_texture1;
	SDL_Surface*	wall_surface;
	SDL_Texture*	sp1_texture;
	SDL_Surface*	sp1_surface;
	t_player*		player;

	/* test code */
	unsigned char*	image1;

	float			ray_x;
	float			ray_y;
	int				hit_v;
	int				hit_h;

	/* sprite test code */
	t_sprite		sprite[2];
	int visible_hit_v[map_h][map_w];
	int visible_hit_h[map_h][map_w];
	int visible_map[map_h][map_w];
	int visible_sprite[map_h][map_w];
	float* sprite_array; // [dst, angle] * sprite_count
	int sprite_count;
	float* dist_dept;
}	t_data;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
	float	shader;
}	t_color;

int		move_player(t_player* game_data);
void	key_up(t_player* p);
void	key_down(t_player* p);

void	draw_line(t_data* game_data);

void	horizon_ray(t_data* g_data, float ray_angle);
void	vertical_ray(t_data* g_data, float ray_angle);

void	Rendering(t_data* game_data);
void	draw_short_ray(t_data* g_data);
void	draw_map(t_data* game_data);

SDL_Surface* init_background(SDL_Window* window);
void	map_over_screen(t_data* game_data);

SDL_Surface* load_texture(SDL_Renderer* renderer, char* file);

/* sprite code */
void	test_spirte(t_data* game_data);
void	init_sprite(t_data* game_data);
// void	draw_sprite(t_data* game_data);
void	reset_visible_sprite_map(t_data* game_data);
void	test_sprite_checker(t_data* game_data, int x, int y, char c);
void	set_sprite_map(t_data* game_data);
void	test_sprite_(t_data* game_data);
void	ft_sprite_calculate(t_data* game_data);
SDL_Texture* test_sprite_texture(t_data* game_data, char* file);

/* test code */
void	test_draw_texture(t_data* game_data);
void	ft_load_texture(t_data* game_data);
void	test_wall_texel(t_data* game_data, int x, int y, int width_idx, int h, int* texture1);

Uint32	set_color_from_texture(SDL_Rect* rect, t_data* game_data, int x, int y, int h, float shader, int* texture1);
float	set_color_shader(int wall_h);
int	set_texture(t_data* game_data);

#endif