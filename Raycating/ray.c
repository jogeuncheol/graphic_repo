#include "SDL_Project.h"

void	horizon_ray(t_data *g_data)
{
	float rad = M_PI / 180 * g_data->player->angle;
	float angle = g_data->player->angle;
	float x1 = g_data->player->p_rect.x;
	float y1 = g_data->player->p_rect.y;
	float px;
	float py;

	// 3, 4 분면 :: 아래 바라봄
	if ((rad < M_PI && rad > 0) || (rad > M_PI * -2 && rad < M_PI * -1))
	{
		px = ceil(x1 / TILE_SIZE) * TILE_SIZE;
		py = ceil(y1 / TILE_SIZE) * TILE_SIZE;
		g_data->player->next_hx = (py - y1) / (float)tan(rad) + x1;
		g_data->player->next_hy = py;
	}
	// 1, 2 분면 :: 위 바라봄
	if ((rad < M_PI * 2 && rad > M_PI) || (rad > M_PI * -1 && rad < 0))
	{
		px = floor(x1 / TILE_SIZE) * TILE_SIZE;
		py = floor(y1 / TILE_SIZE) * TILE_SIZE;
		g_data->player->next_hx = (py - y1) / (float)tan(rad) + x1;
		g_data->player->next_hy = py;
	}
	if (abs(angle) == 0 || abs(angle) == 180)
	{
		g_data->player->next_hx = x1;
		g_data->player->next_hy = y1;
	}
}

void	vertical_ray(t_data* g_data)
{
	float rad = M_PI / 180 * g_data->player->angle;
	float angle = g_data->player->angle;
	float x1 = g_data->player->p_rect.x;
	float y1 = g_data->player->p_rect.y;
	float px;
	float py;

	// 1, 4 분면 :: 오른쪽 바라봄
	if ((rad < (M_PI / 2) && rad > -(M_PI / 2)) || (rad > (M_PI * 3) / 2 || rad < (M_PI * -3) / 2))
	{
		px = ceil(x1 / TILE_SIZE) * TILE_SIZE;
		py = ceil(y1 / TILE_SIZE) * TILE_SIZE;
		g_data->player->next_vx = px;
		g_data->player->next_vy = (float)tan(rad) * (px - x1) + y1;
	}
	// 2, 3 분면 :: 왼쪽 바라봄
	if ((rad > M_PI / 2 && rad < (M_PI * 3) / 2) || (rad < -(M_PI / 2) && rad > (M_PI * -3) / 2))
	{
		px = floor(x1 / TILE_SIZE) * TILE_SIZE;
		py = floor(y1 / TILE_SIZE) * TILE_SIZE;
		g_data->player->next_vx = px;
		g_data->player->next_vy = (float)tan(rad) * (px - x1) + y1;
	}
	if (abs(angle) == 90 || abs(angle) == 270)
	{
		g_data->player->next_vx = x1;
		g_data->player->next_vy = y1;
	}
}

/*
void	next_hit_coord(t_param* param, float* next_h_x, float* next_h_y, float f_tan, float FOV) // next_hit_y 04-17
{
	while (floor(*next_h_x) >= 0 && floor(*next_h_x) < SCREEN_WIDTH && floor(*next_h_y) >= 0 && *next_h_y < SCREEN_HEIGHT) // == 1
	{
		if (map[(int)floor(*next_h_y) / TILE_SIZE][(int)floor(*next_h_x - TILE_SIZE) / TILE_SIZE] == 1)
			break;
		else
			param->visible_hit_v[(int)floor(*next_h_y) / TILE_SIZE][(int)floor(*next_h_x - TILE_SIZE) / TILE_SIZE] = 1;
		if (map[(int)floor(*next_h_y) / TILE_SIZE][(int)floor(*next_h_x) / TILE_SIZE] == 1)
			break;
		else
			param->visible_hit_v[(int)floor(*next_h_y) / TILE_SIZE][(int)floor(*next_h_x) / TILE_SIZE] = 1;
		if ((fabs(FOV) > 90 && fabs(FOV) < 270)) // abs(param->degree) -> FOV 04_23
			*next_h_x = floor(*next_h_x - TILE_SIZE);
		else
			*next_h_x = floor(*next_h_x + TILE_SIZE);
		*next_h_y = *next_h_y + f_tan * TILE_SIZE;
	}
	param->xy.x1 = *next_h_x;
	param->xy.y1 = *next_h_y;
}

void	next_hit_coord_x(t_param* param, float* nh_x, float* nh_y, float f_tan, float FOV)
{ // next_hit_x 04-18
	while (floor(*nh_x) >= 0 && *nh_x < SCREEN_WIDTH && floor(*nh_y) >= 0 && *nh_y < SCREEN_HEIGHT)
	{
		//		printf("x y : %f %f\n", *nh_x, *nh_y);
		//		printf("f_tan * 32 : %f\n", f_tan * TILE_SIZE);
		if (map[(int)floor(*nh_y - TILE_SIZE) / TILE_SIZE][(int)floor(*nh_x) / TILE_SIZE] == 1)
			break;
		else
			param->visible_hit_h[(int)floor(*nh_y - TILE_SIZE) / TILE_SIZE][(int)floor(*nh_x) / TILE_SIZE] = 1;

		if (map[(int)floor(*nh_y) / TILE_SIZE][(int)floor(*nh_x) / TILE_SIZE] == 1)
			break;
		else
			param->visible_hit_h[(int)floor(*nh_y) / TILE_SIZE][(int)floor(*nh_x) / TILE_SIZE] = 1;
		if ((FOV > 0 && FOV < 180) || (FOV < -180 && FOV > -360))
		{
			*nh_y = floor(*nh_y) + TILE_SIZE;
			*nh_x = *nh_x + TILE_SIZE * f_tan;
		}
		else
		{
			*nh_y = floor(*nh_y) - TILE_SIZE;
			*nh_x = *nh_x - TILE_SIZE * f_tan;
		}
	}
	param->xy.x1 = *nh_x;
	param->xy.y1 = *nh_y;
	//	printf("next_hit_coord_x : x y : %f %f\n", param->xy.x1, param->xy.y1);
}

void grid_find_x(t_param* param, float FOV);

void grid_find_y(t_param* param, float FOV)
{
	int g_x;
	int g_y;
	float hit_x;
	float hit_y;
	float fov;
	float tan;

	tan = 0;
	fov = FOV;
	g_x = floor(param->x) / TILE_SIZE;
	g_y = floor(param->y) / TILE_SIZE;

	if (fabs(fov) < 90 || fabs(fov) > 270)
	{
		hit_x = (g_x + 1) * TILE_SIZE;
		if (fabs(cos(fov * M_PI / 180)) < 0.000001)
			tan = 0;
		else
			tan = sin(fov * M_PI / 180) / cos(fov * M_PI / 180);
		hit_y = (hit_x - param->x) * tan + param->y;
		next_hit_coord(param, &hit_x, &hit_y, tan, FOV);
	}
	else if (fabs(fov) > 90 && fabs(fov) < 270)
	{
		hit_x = g_x * TILE_SIZE;
		if (fabs(cos(fov * M_PI / 180)) < 0.000001)
			tan = 0;
		else
			tan = sin(M_PI - (fov * M_PI / 180)) / cos(M_PI - (fov * M_PI / 180));
		hit_y = (param->x - hit_x) * tan + param->y;
		next_hit_coord(param, &hit_x, &hit_y, tan, FOV);
	}
	else
	{
		grid_find_x(param, FOV);
	}
}

void grid_find_x(t_param* param, float FOV)
{
	int g_x;
	int g_y;
	float hit_x;
	float hit_y;
	float fov;
	float tan;

	tan = 0;
	fov = FOV;
	g_x = floor(param->x) / TILE_SIZE;
	g_y = floor(param->y) / TILE_SIZE;

	//	printf("fov : %f\n", fov);
	if (fabs(fov) > 360) // 04_23 save
	{
		if (fov > 360) fov = fov - 360;
		else fov = fov + 360;
	}
	if ((fov > 0 && fov < 180) || (fov < -180 && fov > -360))
	{
		hit_y = (g_y + 1) * TILE_SIZE;
		if (fabs(cos(fov * M_PI / 180)) < 0.000001)
			tan = 0;
		else
			tan = sin(M_PI / 2 - (fov * M_PI / 180)) / cos(M_PI / 2 - (fov * M_PI / 180));
		hit_x = (hit_y - param->y) * tan + param->x;
		next_hit_coord_x(param, &hit_x, &hit_y, tan, fov);
	}
	else if ((fov < 0 && fov > -180) || (fov > 180 && fov < 360))
	{
		hit_y = g_y * TILE_SIZE;
		if (fabs(cos(fov * M_PI / 180)) < 0.000001)
			tan = 0;
		else
			tan = sin(M_PI / 2 - (fov * M_PI / 180)) / cos(M_PI / 2 - (fov * M_PI / 180));
		hit_x = (hit_y - param->y) * tan + param->x;
		next_hit_coord_x(param, &hit_x, &hit_y, tan, fov);
	}
	else
	{
		grid_find_y(param, fov);
	}
}

void grid_find_coord(t_param* param, float FOV)
{
	float find_xx;
	float find_xy;
	float find_yx;
	float find_yy;
	float dst_x;
	float dst_y;

	grid_find_x(param, FOV); // find hit_x line
	find_xx = param->xy.x1;
	find_xy = param->xy.y1;
	dst_x = sqrt(pow(find_xx - param->x, 2) + pow(find_xy - param->y, 2));
	//	printf("FOV : %f\n", FOV);
	//	printf("grid_find_x x y : %f %f\n", param->xy.x1, param->xy.y1);
	grid_find_y(param, FOV); // find hit_y line
	find_yx = param->xy.x1;
	find_yy = param->xy.y1;
	dst_y = sqrt(pow(find_yx - param->x, 2) + pow(find_yy - param->y, 2));
	//	printf("FOV : %f\n", FOV);
	//	printf("grid_find_y x y : %f %f\n", param->xy.x1, param->xy.y1);

	if (dst_x > dst_y) // V hit
	{
		param->xy.x1 = find_yx;
		param->xy.y1 = find_yy;
		param->color = 0x0000ff;
		param->grid_x = 0;
		param->grid_y = 1;
	}
	if (dst_y > dst_x) // H hit
	{
		param->xy.x1 = find_xx;
		param->xy.y1 = find_xy;
		param->color = 0xff0000;
		param->grid_x = 1;
		param->grid_y = 0;
	}
	if (param->map[(int)floor(param->xy.y1) / TILE_SIZE][(int)floor(param->xy.x1) / TILE_SIZE] != 1)
		param->visible_map[(int)floor(param->xy.y1) / TILE_SIZE][(int)floor(param->xy.x1) / TILE_SIZE] = 1;
	//	mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->xy.x1, param->xy.y1, 0xff0000);
	//	printf("find_x : %f find_y : %f\n", param->xy.x1, param->xy.y1);
}

void DDA_grid_find_coord(t_param* param)
{
	float dx;
	float dy;
	float step;
	float x;
	float y;
	int i;

	i = 0;
	dx = param->xy.x1 - param->x;
	dy = param->xy.y1 - param->y;
	x = param->x;
	y = param->y;
	if (fabs(dx) > fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	while (i < step)
	{
		if (x < 0.01 || y < 0.01 || x > 480 || y > 320)
			break;
		//		mlx_pixel_put(param->mlx_ptr, param->win_ptr, floor(x), floor(y), 0xff0000);

		// visible_map : 스프라이트 적용하기위해서
		// param->visible_map[(int)floor(y) / TILE_SIZE][(int)floor(x) / TILE_SIZE] = 1;
		x = x + dx;
		y = y + dy;
		i++;
	}
	//	printf("x1 y1 : %f  %f\n", x, y);
}

void DDA_FOV_grid(t_param* param)
{
	int i;
	int count;
	float FOV;

	i = 0;
	count = 0;
	FOV = param->degree - 30;
	floor_ceiling_init(param);

	while (i < SCREEN_WIDTH) // 05_02 save
	{
		float seta; // = atan((SCREEN_WIDTH / 2 - i) / ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180)));
		seta = atan2((SCREEN_WIDTH / 2 - i), ((SCREEN_WIDTH / 2) / tan(30 * M_PI / 180)));

		float degree = param->degree - (seta * 180 / M_PI);

		if (i % (TILE_SIZE / 16) == 0)
		{
			grid_find_coord(param, degree);
			// DDA_grid_find_coord(param);
		}
		i++;
	}
}
*/