
#include "../include/fdf.h"

void	strings(t_param *param)
{
	mlx_string_put(param->mlx_ptr, param->win_ptr,\
		WINDOW_W / 2 - 120, 38, FLUO_GREEN, "FDF CDE-MAR");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 100, 1128, FLUO_GREEN, \
		"Movement: UP / DOWN / LEFT / RIGHT | Rotation on x-axis: X / C | \
		Rotation on y-axis: Y / U | Rotation on z-axis: O / P | Change height: \
		Q / W  ");
    /*
	mlx_string_put(param->mlx_ptr, param->win_ptr,\
	100, 1152, FLUO_GREEN, "SPACE: Stops / Starts auto-rotation | R: Reset to \
		iso | T: Reset to top-view | TAB -> Erases \
		drawings | ESC -> QUIT");
	mlx_string_put(param->mlx_ptr, param->win_ptr,\
		100, 38, FLUO_GREEN, param->name);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1737, 100, FLUO_GREEN, "19");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1737, 120, FLUO_GREEN, "42");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1737, 140, FLUO_GREEN, "feli\
			x");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1737, 160, FLUO_GREEN, "10-2\
			");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1737, 180, FLUO_GREEN, "pyra\
			");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 1750, 440, FLUO_GREEN, "X");
    */
}

void	box(t_param *param)
{
	param->x = 1720;
	param->y = 90;
	param->x2 = 1790;
	param->y2 = 90;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 90;
	param->x2 = 1720;
	param->y2 = 470;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 470;
	param->x2 = 1790;
	param->y2 = 470;
	img_bresenham(0000125125, param);
	param->x = 1790;
	param->y = 470;
	param->x2 = 1790;
	param->y2 = 90;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 100;
	param->x2 = 1790;
	param->y2 = 100;
	img_bresenham(0000125125, param);
}

void	box_2(t_param *param)
{
	param->x = 1720;
	param->y = 122;
	param->x2 = 1790;
	param->y2 = 122;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 142;
	param->x2 = 1790;
	param->y2 = 142;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 162;
	param->x2 = 1790;
	param->y2 = 162;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 182;
	param->x2 = 1790;
	param->y2 = 182;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 202;
	param->x2 = 1790;
	param->y2 = 202;
	img_bresenham(0000125125, param);
}

void	box_3(t_param *param)
{
	param->x = 1720;
	param->y = 222;
	param->x2 = 1790;
	param->y2 = 222;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 480;
	param->x2 = 1790;
	param->y2 = 480;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 480;
	param->x2 = 1720;
	param->y2 = 500;
	img_bresenham(0000125125, param);
	param->x = 1790;
	param->y = 480;
	param->x2 = 1790;
	param->y2 = 500;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 500;
	param->x2 = 1790;
	param->y2 = 500;
	img_bresenham(0000125125, param);
}
