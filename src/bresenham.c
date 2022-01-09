
#include "../include/fdf.h"

void	bresenham(int color, t_param *param)
{
	int w_h[2];
	int delta_x_y[4];

	w_h[0] = param->x2 - param->x;
	w_h[1] = param->y2 - param->y;
	delta_x_y[0] = 0;
	delta_x_y[1] = 0;
	delta_x_y[2] = 0;
	delta_x_y[3] = 0;
	if (w_h[0] < 0)
		delta_x_y[0] = -1;
	else if (w_h[0] > 0)
		delta_x_y[0] = 1;
	if (w_h[1] < 0)
		delta_x_y[1] = -1;
	else if (w_h[1] > 0)
		delta_x_y[1] = 1;
	if (w_h[0] < 0)
		delta_x_y[2] = -1;
	else if (w_h[0] > 0)
		delta_x_y[2] = 1;
	bresenham_2(w_h, delta_x_y, color, param);
}

void	bresenham_2(int w_h[2], int delta_x_y[4], int color, t_param *param)
{
	int long_short[2];

	long_short[0] = abs(w_h[0]);
	long_short[1] = abs(w_h[1]);
	if (!(long_short[0] > long_short[1]))
	{
		long_short[0] = abs(w_h[1]);
		long_short[1] = abs(w_h[0]);
		if (w_h[1] < 0)
			delta_x_y[3] = -1;
		else if (w_h[1] > 0)
			delta_x_y[3] = 1;
		delta_x_y[2] = 0;
	}
	bresenham_3(delta_x_y, long_short, color, param);
}

void	bresenham_3(int delta_x_y[4], int long_short[2],\
	int color, t_param *param)
{
	int numerator;
	int i;

	numerator = long_short[0] / 2;
	i = 0;
	while (i <= long_short[0])
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr,\
			param->x, param->y, color);
		numerator += long_short[1];
		if (!(numerator < long_short[0]))
		{
			numerator -= long_short[0];
			param->x += delta_x_y[0];
			param->y += delta_x_y[1];
		}
		else
		{
			param->x += delta_x_y[2];
			param->y += delta_x_y[3];
		}
		i++;
	}
}
