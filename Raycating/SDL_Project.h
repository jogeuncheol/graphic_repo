#pragma once
#ifndef SDL_Project_H
#define SDL_Project_H

#include <SDL.h>
#include <math.h>

// 타일 크기
const static int TILE_SIZE = 64;

// 화면 크기 지정
const static int SCREEN_WIDTH = TILE_SIZE * 15;
const static int SCREEN_HEIGHT = TILE_SIZE * 10;

typedef struct s_player
{
	SDL_Rect	p_rect;
	SDL_Rect	arrow;
	float		angle;

	int			move_forword_back;
	int			move_left_right;
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

#endif