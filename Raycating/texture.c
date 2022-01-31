#include "SDL_Project.h"

SDL_Surface*	load_texture(SDL_Renderer* renderer, char *file)
{
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;
	
	if (surface = SDL_LoadBMP(file))
	{
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}
	else
		printf("texture load Fail : %s\n", file);
	return (surface);
}

int	set_texture(t_data* game_data)
{
	int map_texture = game_data->map[(int)floor(game_data->ray_y / TILE_SIZE)][(int)floor(game_data->ray_x / TILE_SIZE)];
	if (map_texture == 1)
		return (1);
	else if (map_texture == 2)
		return (2);
	else
		return (3);
}

float	set_color_shader(int wall_h)
{
	float shader = 0.0f;
	shader = (float)wall_h / SCREEN_HEIGHT - 0.125f;
	if (shader > 1.0f)
	{
		shader = 1.0f;
	}
	else if (shader < 0.0f)
		shader = 0.0f;
	return (shader);
}

Uint32	set_color_from_texture(SDL_Rect *rect, t_data* game_data, int x, int y, int h, float shader, int* texture1)
{
	rect->y = (int)(floor(SCREEN_HEIGHT / 2) - h);

	Uint32 color;
	int r = 0;
	int g = 0;
	int b = 0;
	int texel = (x * 64 + y) * 3;

	r = texture1[texel + 0];
	g = texture1[texel + 1];
	b = texture1[texel + 2];
	if (r < 0xFa || g < 0xF1 || b < 0xbf)
	{
		r = r * shader;
		g = g * shader;
		b = b * shader;
	}
	SDL_SetRenderDrawColor(game_data->renderer, r, g, b, 0xFF);
	color = SDL_MapRGB(game_data->wall_surface->format, r, g, b);
	return (color);
}

SDL_Texture*	test_sprite_texture(t_data* game_data, char *file)
{
	SDL_Surface* surface = NULL;
	SDL_Texture* texture = NULL;

	if (surface = SDL_LoadBMP(file))
	{
		texture = SDL_CreateTextureFromSurface(game_data->renderer, surface);
		SDL_FreeSurface(surface);
	}
	else
	{
		printf("texture load Fail : %s\n", file);
		return (NULL);
	}
	return (texture);
}

//#include "texture/wall1.ppm"
void	ft_test_pmm(t_data* game_data)
{
	//int y = 0;
	//for (int i = 0; i < 512; i += 8)
	//{
	//	int x = 0;
	//	for (int j = 0; j < 512; j += 8)
	//	{
	//		int pixel = (i * 512 + j) * 3;
	//		int r = texture1[pixel + 0];
	//		int g = texture1[pixel + 1];
	//		int b = texture1[pixel + 2];
	//		SDL_SetRenderDrawColor(game_data->renderer, r, g, b, 0xFF);
	//		SDL_RenderDrawPoint(game_data->renderer, x, y);
	//		x++;
	//	}
	//	y++;
	//}
}

void	ft_load_texture(t_data *game_data)
{
	FILE* fd = NULL;
	unsigned char* src_image = NULL;
	unsigned char* p_src_image = NULL;
	unsigned char* dst_image = NULL;
	unsigned char* p_dst_image = NULL;
	unsigned char* texture_image = NULL;
	unsigned char* p_texture_image = NULL;

	if (fopen_s(&fd, "texture/wall1.bmp", "rb") == 0)
	{
		src_image = (unsigned char*)malloc(sizeof(char) * 512 * 512);
		dst_image = (unsigned char*)malloc(sizeof(char) * 512 * 512);
		texture_image = (unsigned char*)malloc(sizeof(char) * 64 * 64 * 4);
		if (src_image != NULL && dst_image != NULL && texture_image != NULL)
		{
			p_src_image = src_image;
			p_dst_image = dst_image;
			p_texture_image = texture_image;
			fread(src_image, 512 * 512, 1, fd);
			
			// 512 x 512 이미지를 64 x 64 이미지로 단순 축소하여 메모리에 저장
			int x64_idx = 0;
			//for (int i = 0; i < 512 * 4; i += 1)
			//{
			//	int x64_jdx = 0;
			//	for (int j = 0; j < 512 * 4; j += 1)
			//	{
			//		p_dst_image[(x64_idx * 512) + x64_jdx++] = p_src_image[(i * 512) + j];
			//	}
			//	x64_idx++;
			//}

			// 64 x 64 이미지를 rgba 값을 가지는 영상으로 최종 저장
			//for (int i = 0; i < 64 * 64; i++)
			//{
			//	*p_texture_image++ = *p_dst_image;
			//	*p_texture_image++ = *p_dst_image;
			//	*p_texture_image++ = *p_dst_image++;
			//	*p_texture_image++ = 0xFF;
			//}
			
		}
		game_data->image1 = texture_image;
		free(src_image);
		free(dst_image);
		fclose(fd);
	}
	else
		printf("fopen fail\n");
}