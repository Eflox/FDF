
#include "../include/fdf.h"

void	ft_menu(t_param *param)
{
	param->x = 90;
	param->y = 90;
	param->x2 = 90;
	param->y2 = WINDOW_H - 110;
	img_bresenham(0000125125, param);
	param->x = 90;
	param->y = 90;
	param->x2 = WINDOW_W - 110;
	param->y2 = 90;
	img_bresenham(0000125125, param);
	param->x = WINDOW_W - 110;
	param->y = 90;
	param->x2 = WINDOW_W - 110;
	param->y2 = WINDOW_H - 110;
	img_bresenham(0000125125, param);
	param->x = 90;
	param->y = WINDOW_H - 110;
	param->x2 = WINDOW_W - 110;
	param->y2 = WINDOW_H - 110;
	img_bresenham(0000125125, param);
    /*
	ft_menu_2(param);
	ft_menu_3(param);
	ft_menu_4(param);
	ft_menu_5(param);
	box(param);
    */
}

void	ft_menu_2(t_param *param)
{
	param->x = 100;
	param->y = 100;
	param->x2 = 100;
	param->y2 = WINDOW_H - 100;
	img_bresenham(0000125125, param);
	param->x = 100;
	param->y = 100;
	param->x2 = WINDOW_W - 100;
	param->y2 = 100;
	img_bresenham(0000125125, param);
	param->x = WINDOW_W - 100;
	param->y = 100;
	param->x2 = WINDOW_W - 100;
	param->y2 = WINDOW_H - 100;
	img_bresenham(0000125125, param);
	param->x = 100;
	param->y = WINDOW_H - 100;
	param->x2 = WINDOW_W - 100;
	param->y2 = WINDOW_H - 100;
	img_bresenham(0000125125, param);
}

void	ft_menu_3(t_param *param)
{
	param->x = 90;
	param->y = 30;
	param->x2 = 90;
	param->y2 = 70;
	img_bresenham(0000125125, param);
	param->x = 90;
	param->y = 30;
	param->x2 = 400;
	param->y2 = 30;
	img_bresenham(0000125125, param);
	param->x = 400;
	param->y = 30;
	param->x2 = 400;
	param->y2 = 70;
	img_bresenham(0000125125, param);
	param->x = 90;
	param->y = 70;
	param->x2 = 400;
	param->y2 = 70;
	img_bresenham(0000125125, param);
}

void	ft_menu_4(t_param *param)
{
	param->x = 1720;
	param->y = 120;
	param->x2 = 1790;
	param->y2 = 120;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 140;
	param->x2 = 1790;
	param->y2 = 140;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 160;
	param->x2 = 1790;
	param->y2 = 160;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 180;
	param->x2 = 1790;
	param->y2 = 180;
	img_bresenham(0000125125, param);
	param->x = 1720;
	param->y = 202;
	param->x2 = 1790;
	param->y2 = 202;
	img_bresenham(0000125125, param);
}

void	ft_menu_5(t_param *param)
{
	param->x = 1720;
	param->y = 430;
	param->x2 = 1790;
	param->y2 = 430;
	img_bresenham(0000125125, param);
	square(WINDOW_W - 390, 20, BLACK, param);
	square(WINDOW_W - 370, 20, WHITE, param);
	square(WINDOW_W - 350, 20, 02440066, param);
	square(WINDOW_W - 330, 20, 0244104066, param);
	square(WINDOW_W - 310, 20, 0244217065, param);
	square(WINDOW_W - 290, 20, 0174244065, param);
	square(WINDOW_W - 270, 20, 0065244154, param);
	square(WINDOW_W - 250, 20, 0065244211, param);
	square(WINDOW_W - 230, 20, 0075065244, param);
	square(WINDOW_W - 210, 20, 0124065244, param);
	square(WINDOW_W - 190, 20, 0000000120, param);
	square(WINDOW_W - 170, 20, 0244065244, param);
	square(WINDOW_W - 150, 20, 0255255255, param);
	square(WINDOW_W - 130, 20, DARK_GRAY, param);
}
