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
	{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
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

	float		next_x;
	float		next_y;
}	t_player;

typedef struct s_data
{
	SDL_Window*		window;
	SDL_Surface*	surface;
	SDL_Renderer*	renderer;
	SDL_Texture*	texture;
	t_player*		player;
}	t_data;

int	move_player(t_player* game_data);
void	horizon_ray(t_data* g_data);

#endif