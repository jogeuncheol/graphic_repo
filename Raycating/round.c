#include "SDL_Project.h"

void	next_level(t_data* game_data)
{
	if (game_data->clear_req == 1)
	{
		copy_main_map(game_data, map2);
		zeromem_sprite(game_data);
		init_level2_player(game_data);
		init_level2_sprite(game_data);
	}
	else if (game_data->clear_req == 2)
	{
		copy_main_map(game_data, final_map20);
		init_level3_player(game_data);
		// zeromem_sprite(game_data);
		init_level3_sprite(game_data);
	}
}

void	is_clear_round(t_data* game_data)
{
	if (game_data->clear_req)
		next_level(game_data);
}

int	check_level(t_data* game_data)
{
	if (game_data->clear_req == game_data->round)
	{
		game_data->round++;
		is_clear_round(game_data);
		// copy_main_map(game_data, map2);
		// init_player(game_data->player);
		// init_sprite(game_data);
		game_data->clear_req = 0;
	}
	if (game_data->round == 4)
	{
		return (2);
	}
	return (1);
}