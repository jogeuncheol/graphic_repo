#include "so_long.h"

int main()
{
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 100, 100, "window");
	mlx_loop(mlx_ptr);
	return (0);
}
