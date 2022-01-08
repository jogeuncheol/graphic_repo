#pragma once
#ifndef SDL_Project_H
#define SDL_Project_H

#include <SDL.h>
#include <stdio.h>
#include <math.h>

// Ÿ�� ũ��
#define TILE_SIZE	64

// ȭ�� ũ�� ����
#define SCREEN_WIDTH	TILE_SIZE * 15
#define SCREEN_HEIGHT	TILE_SIZE * 10

static int map_h = 10;
static int map_w = 15;
static int map[10][15] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

typedef struct s_player
{
	SDL_FRect	p_rect;				// �÷��̾� �Ǽ� ��ǥ
	SDL_Rect	player_cord;		// �簢�� �׸���� ���� ��ǥ
	SDL_Rect	arrow;
	float		angle;

	int			move_forword_back;
	int			move_left_right;
	int			cardinal_point;

	float		next_hx; // ��������� ù ��ǥ
	float		next_hy;
	float		next_vx; // ���������� ù ��ǥ
	float		next_vy;
	float		ray_hx;
	float		ray_hy;
	float		ray_vx;
	float		ray_vy;

	/* �÷��̾ �е��� �־ �� �浹 ���� + �̲������� */
	float		p_padding_n;
	float		p_padding_s;
	float		p_padding_e;
	float		p_padding_w;

	float		velocity;
}	t_player;

typedef struct s_data
{
	SDL_Window*		window;
	SDL_Surface*	surface;
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	t_player*		player;

	float			ray_x;
	float			ray_y;
}	t_data;

int		move_player(t_player* game_data);
void	key_up(t_player* p);
void	key_down(t_player* p);

void	draw_line(t_data* game_data);

void	horizon_ray(t_data* g_data, float ray_angle);
void	vertical_ray(t_data* g_data, float ray_angle);

void	Rendering(t_data* game_data);
void	draw_short_ray(t_data* g_data);

#endif