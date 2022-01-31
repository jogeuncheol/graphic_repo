#include "SDL_Project.h"

#define MUS_PATH "sound/bgm.wav"

int test_play_sound1()
{
	initAudio();

	// playSound(MUS_PATH, SDL_MIX_MAXVOLUME);

	Audio* audio = createAudio(MUS_PATH, 1, SDL_MIX_MAXVOLUME);
	playSoundFromMemory(audio, SDL_MIX_MAXVOLUME);

	SDL_Delay(1000);

}

int test_init_sound(t_data *game_data)
{
	game_data->sound->title = Mix_LoadMUS("sound/TitleScreen.wav");
	if (game_data->sound->title == NULL)
		printf("Mix_LoadMUS: %s\n", Mix_GetError());
	printf("bgm :: %p\n", game_data->sound->title);
	game_data->sound->bgm = Mix_LoadMUS("sound/horror-background.wav");
	if (game_data->sound->bgm == NULL)
		printf("Mix_LoadMUS: %s\n", Mix_GetError());
	printf("bgm :: %p\n", game_data->sound->bgm);
	game_data->sound->ending = Mix_LoadMUS("sound/Happy Sunset.wav");
	if (game_data->sound->ending == NULL)
		printf("Mix_LoadMUS: %s\n", Mix_GetError());
	printf("bgm :: %p\n", game_data->sound->ending);
	game_data->sound->walk = Mix_LoadWAV("sound/walk1.wav");
	if (game_data->sound->walk == NULL)
		printf("Mix_LoadMUS: %s\n", Mix_GetError());
	printf("bgm :: %p\n", game_data->sound->walk);
}