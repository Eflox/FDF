
#include "../include/fdf.h"

int		deal_key(int key, t_param *param)
{
	if (key == ESC_KEY)
		exit_fdf(param, "");
	else if (key == R_KEY)
	{
		initialize(param);
		erase_put_back(param);
	}
	else if (key == TAB_KEY)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,\
			param->img_ptr, 0, 0);
		strings(param);
	}
	else if (key == D_KEY)
		param->dots_or_lines = !param->dots_or_lines;
	else if (key == T_KEY)
	{
		param->x_angle = 1.579931;
		param->y_angle = 4.700224;
	}
	rotate(key, param);
	return (0);
}

void	erase_put_back(t_param *param)
{
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WINDOW_W, WINDOW_H);
	change_background(param);
	draw_map(param);
	ft_menu(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,\
		param->img_ptr, 0, 0);
	strings(param);
}

void	exit_fdf(t_param *param, char *str)
{
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	free(param);
	if (str)
		ft_putendl(str);
	exit(0);
}

void	rotate(int key, t_param *param)
{
	if (key == X_KEY)
		param->x_angle += ANGLE;
	else if (key == C_KEY)
		param->x_angle -= ANGLE;
	else if (key == Y_KEY)
		param->y_angle += ANGLE;
	else if (key == U_KEY)
		param->y_angle -= ANGLE;
	else if (key == Q_KEY)
		param->change_z += ANGLE;
	else if (key == W_KEY)
		param->change_z -= ANGLE;
	else if (key == O_KEY)
	{
		param->y_angle -= ANGLE;
		param->x_angle -= ANGLE;
	}
	else if (key == P_KEY)
	{
		param->y_angle += ANGLE;
		param->x_angle += ANGLE;
	}
	zoom_move(key, param);
	erase_put_back(param);
}

void	zoom_move(int key, t_param *param)
{
	if (key == RIGHT_KEY)
		param->horizontal += 10;
	else if (key == LEFT_KEY)
		param->horizontal -= 10;
	else if (key == UP_KEY)
		param->vertical -= 10;
	else if (key == DOWN_KEY)
		param->vertical += 10;
	else if (key == PL_KEY)
		param->zoom += 1;
	else if (key == MN_KEY)
		param->zoom -= 1;
	else if (key == SP_KEY)
		param->flip = !param->flip;
}
