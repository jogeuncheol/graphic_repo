#include "SDL_Project.h"

void	draw_fov_ray(t_data *game_data)
{
	int ray_angle = -30;
	
	while (ray_angle < 30)
	{
		horizon_ray(game_data, ray_angle);		// ���򼱿� ��� ray
		vertical_ray(game_data, ray_angle);	// �������� ��� ray
		draw_short_ray(game_data);	// �� ray �� ª�� ���� ���� game_data->ray_x, y

		ray_angle++;
	}
}

void	draw_short_ray(t_data *g_data)
{
	t_player* p = g_data->player;
	float ray_distance_h, ray_distance_v;

	ray_distance_h = sqrtf(powf(p->ray_hx - p->p_rect.x, 2) + powf(p->ray_hy - p->p_rect.y, 2));
	ray_distance_v = sqrtf(powf(p->ray_vx - p->p_rect.x, 2) + powf(p->ray_vy - p->p_rect.y, 2));
	if (ray_distance_h == 0)
	{
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
	else if (ray_distance_v == 0)
	{
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else if (ray_distance_h < ray_distance_v)
	{
		g_data->ray_x = p->ray_hx;
		g_data->ray_y = p->ray_hy;
		SDL_SetRenderDrawColor(g_data->renderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_hx, (int)p->ray_hy);
	}
	else
	{
		g_data->ray_x = p->ray_vx;
		g_data->ray_y = p->ray_vy;
		SDL_SetRenderDrawColor(g_data->renderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderDrawLine(g_data->renderer, (int)p->p_rect.x, (int)p->p_rect.y, (int)p->ray_vx, (int)p->ray_vy);
	}
}

void	Rendering(t_data* game_data)
{
	SDL_Renderer* renderer = game_data->renderer;
	SDL_Texture* texture = game_data->texture;
	t_player* player = game_data->player;

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	/* SDL_RenderClear :: SDL_SetRenderDrawColor �� �����Ǿ� �ִ� ������ ȭ�� ��ü�� ������ ��. */
	// SDL_RenderClear(renderer);

	// �������� �ؽ��� ���� (���� texture�� ��� ����)
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// �÷��̾� �׸���
	// �������� �׸��� ������ ���������� ����
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	// �������� �÷��̾� ��ǥ�� �簢�� ����. ������ ������ ������ �������� ��.
	SDL_RenderFillRect(renderer, &player->player_cord);

	// �÷��̾��� ����
	// draw_line(game_data);

	// �÷��̾� �þ� ǥ��
	draw_fov_ray(game_data);

	//// �������� �׸��� ������ �Ķ������� ����
	//// ���� ���� ray
	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_hx, game_data->player->ray_hy);

	//// ���� ���� ray
	//SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderDrawLine(game_data->renderer, player->p_rect.x, player->p_rect.y, game_data->player->ray_vx, game_data->player->ray_vy);
	//// �������� �÷��̾� ȭ��ǥ ��ǥ�� �簢�� ����

	// ���� ������ ���� ���� �� �� ª�� ������ �׸�.
	draw_short_ray(game_data);

	// ������ ����� �׸���. <--(?) ��� ���� ������ �������� ����� â�� �׸���.
	SDL_RenderPresent(renderer);
}