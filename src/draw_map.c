
#include "../include/fdf.h"

void	draw_map(t_param *param)
{
	int		i;
	int		j;

	i = 0;
	while (i < param->max_x)
	{
		j = 0;
		while (j < param->max_y)
		{
			if (param->dots_or_lines == 1)
				dot_map(i, j, param);
			else
				line_map(i, j, param);
			j++;
		}
		i++;
	}
}

void	line_map(int i, int j, t_param *param)
{
	if (j > 0)
	{
		param->x = coord_x(i, j, param);
		param->y = coord_y(i, j, param->map[i][j], param);
		param->x2 = coord_x(i, j - 1, param);
		param->y2 = coord_y(i, j - 1, param->map[i][j - 1], param);
		img_bresenham(grad_color(param, i, j), param);
	}
	if (i > 0)
	{
		param->x = coord_x(i, j, param);
		param->y = coord_y(i, j, param->map[i][j], param);
		param->x2 = coord_x(i - 1, j, param);
		param->y2 = coord_y(i - 1, j, param->map[i - 1][j], param);
		img_bresenham(grad_color(param, i, j), param);
	}
}

void	dot_map(int i, int j, t_param *param)
{
	if (j > 0)
		put_pixel_to_img(coord_x(i, j, param), \
			coord_y(i, j, param->map[i][j], param), \
			grad_color(param, i, j), param);
	if (i > 0)
		put_pixel_to_img(coord_x(i, j, param), \
			coord_y(i, j, param->map[i][j], param), \
			grad_color(param, i, j), param);
}

int		coord_x(int x, int y, t_param *param)
{
	int x_centre;
	int y_centre;

	x_centre = param->max_x / 2;
	y_centre = param->max_y / 2;
	return (((x - x_centre) * cos(param->x_angle) - (y - y_centre) * \
		sin(param->y_angle)) * param->zoom + param->horizontal);
}

int		coord_y(int x, int y, int z, t_param *param)
{
	int x_centre;
	int y_centre;

	x_centre = param->max_x / 2;
	y_centre = param->max_y / 2;
	if (z > 10000)
		z = 10000;
	else if (z < -10000)
		z = -10000;
	return (((x - x_centre) * sin(param->x_angle) + (y - y_centre) * cos(param->
			y_angle) - z * param->change_z) * param->zoom + param->vertical);
}
