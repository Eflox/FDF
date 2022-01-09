
#include "../include/fdf.h"

int		mouse_hook(int button, int x, int y, t_param *param)
{
	if (button == BUT1_KEY)
	{
		if (x > 1720 && x < 1790 && y > 90 && y < 390)
			open_other_map(y, param);
		else if (x > WINDOW_W - 390 && x < WINDOW_W - 110 && y \
		> WINDOW_H - 130 && y < WINDOW_H - 110)
			change_background_key(x, param);
		else if (x > 1720 && x < 1790 && y > 430 && y < 500)
			exit_fdf(param, "");
		mouse_line(x, y, param);
	}
	else if (button == BUT2_KEY)
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, random_color());
	else if (button == SCROLLUP_KEY)
	{
		param->zoom -= 1;
		erase_put_back(param);
	}
	else if (button == SCROLLDOWN_KEY)
	{
		param->zoom += 1;
		erase_put_back(param);
	}
	return (0);
}

void	mouse_line(int x, int y, t_param *param)
{
	static int	xy1[2];
	int			xy2[2];

	if (x > 100 && x < WINDOW_W - 100 && y > 100 && y < WINDOW_H - 100)
	{
		if (xy1[0] == 0 && xy1[1] == 0)
		{
			xy1[0] = x;
			xy1[1] = y;
		}
		else
		{
			xy2[0] = x;
			xy2[1] = y;
			param->x = xy1[0];
			param->y = xy1[1];
			param->x2 = xy2[0];
			param->y2 = xy2[1];
			bresenham(FLUO_PINK, param);
			xy1[0] = 0;
			xy1[1] = 0;
		}
	}
	else
		ft_putchar('\a');
}

void	open_other_map(int y, t_param *param)
{
	if (y > 102 && y < 122)
		param->name = "test_maps/19.fdf";
	else if (y > 122 && y < 142)
		param->name = "test_maps/42.fdf";
	else if (y > 142 && y < 162)
		param->name = "test_maps/felix.fdf";
	else if (y > 162 && y < 182)
		param->name = "test_maps/10-2.fdf";
	else if (y > 182 && y < 202)
		param->name = "test_maps/pyramide.fdf";
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	main_stuff(param);
}

void	change_background_key(int x, t_param *param)
{
	if (x > WINDOW_W - 390 && x < WINDOW_W - 370)
		param->background_color = BLACK;
	else if (x > WINDOW_W - 370 && x < WINDOW_W - 350)
		param->background_color = WHITE;
	else if (x > WINDOW_W - 350 && x < WINDOW_W - 330)
		param->background_color = 02440066;
	else if (x > WINDOW_W - 330 && x < WINDOW_W - 310)
		param->background_color = 0244104066;
	else if (x > WINDOW_W - 310 && x < WINDOW_W - 290)
		param->background_color = 0244217065;
	else if (x > WINDOW_W - 290 && x < WINDOW_W - 270)
		param->background_color = 0174244065;
	else if (x > WINDOW_W - 270 && x < WINDOW_W - 250)
		param->background_color = 0065244154;
	else if (x > WINDOW_W - 250 && x < WINDOW_W - 230)
		param->background_color = 0065244211;
	else if (x > WINDOW_W - 230 && x < WINDOW_W - 210)
		param->background_color = 0075065244;
	else if (x > WINDOW_W - 210 && x < WINDOW_W - 190)
		param->background_color = 0124065244;
	change_background_key2(x, param);
}

void	change_background_key2(int x, t_param *param)
{
	if (x > WINDOW_W - 190 && x < WINDOW_W - 170)
		param->background_color = 0000000120;
	else if (x > WINDOW_W - 170 && x < WINDOW_W - 150)
		param->background_color = 0244065244;
	else if (x > WINDOW_W - 150 && x < WINDOW_W - 130)
		param->background_color = 0255255255;
	else if (x > WINDOW_W - 130 && x < WINDOW_W - 100)
		param->background_color = DARK_GRAY;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	erase_put_back(param);
}
