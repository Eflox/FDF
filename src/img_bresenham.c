
#include "../include/fdf.h"

void	put_pixel_to_img(int x, int y, int color, t_param *param)
{
	int		i;

	i = (y * WINDOW_W) + x;
	if (((x >= 90 && x <= WINDOW_W - 90 && y >= 90 && y <= WINDOW_H - 90) ||\
		(x >= 1720 && x <= 1790 && y >= 90 && y <= 500)) && i >= 0 &&\
			i < (WINDOW_W * WINDOW_H - 1))
		param->data_addr[i] = color;
}

void	img_bresenham(int color, t_param *param)
{
	int		w_h[2];
	int		delta_x_y[4];

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
	img_bresenham_2(w_h, delta_x_y, color, param);
}

void	img_bresenham_2(int w_h[2], int delta_x_y[4], int color, t_param *param)
{
	int		long_short[2];

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
	img_bresenham_3(delta_x_y, long_short, color, param);
}

void	img_bresenham_3(int delta_x_y[4], int long_short[2],\
		int color, t_param *param)
{
	int numerator;
	int i;

	numerator = long_short[0] / 2;
	i = 0;
	while (i <= long_short[0])
	{
		put_pixel_to_img(param->x, param->y, color, param);
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
