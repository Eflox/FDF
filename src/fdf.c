
#include "../include/fdf.h"

void	initialize(t_param *param)
{
	param->background_color = DARK_GRAY;
	param->zoom = 10;
	param->vertical = 620;
	param->horizontal = 890;
	param->x_angle = 0.959931;
	param->y_angle = 4.340224;
	param->change_z = 0.100000;
	param->dots_or_lines = 0;
}

int		loop(t_param *param)
{
	if (param->flip == 1)
	{
		param->y_angle += 0.034533;
		param->x_angle += 0.034533;
		erase_put_back(param);
	}
	return (0);
}

void	main_stuff(t_param *param)
{
	int bpp;
	int line_size;
	int endian;

	param->flip = 1;
	param->fd = open(param->name, O_RDONLY);
	if (param->fd <= 0)
	{
		free(param);
		ft_putendl("Error: File does not exist");
		exit(0);
	}
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WINDOW_W, WINDOW_H, "FDF");
	initialize(param);
	read_file(param);
	close(param->fd);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WINDOW_W, WINDOW_H);
	param->data_addr = (int *)mlx_get_data_addr(param->img_ptr,\
		&bpp, &line_size, &endian);
	main_stuff2(param);
}

void	main_stuff2(t_param *param)
{
	change_background(param);
	draw_map(param);
	ft_menu(param);
	mlx_put_image_to_window(param->mlx_ptr,\
		param->win_ptr, param->img_ptr, 0, 0);
	strings(param);
	mlx_key_hook(param->win_ptr, deal_key, param);
	mlx_mouse_hook(param->win_ptr, mouse_hook, param);
	mlx_loop_hook(param->mlx_ptr, loop, param);
	mlx_loop(param->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_param *param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (-1);
	if (ac == 2)
	{
		param->name = av[1];
		main_stuff(param);
	}
	else
	{
		ft_putendl("usage: ./fdf file");
		free(param);
	}
	return (0);
}
