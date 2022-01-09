
#include "../include/fdf.h"

int		random_color(void)
{
	int n;

	n = rand() % 14;
	if (n == 1)
		return (WHITE);
	if (n == 2)
		return (SILVER);
	if (n == 3)
		return (ORANGE);
	if (n == 4)
		return (FLUO_YELLOW);
	if (n == 5)
		return (FLUO_GREEN);
	if (n == 6)
		return (BLUE_GREEN);
	if (n == 7)
		return (LIGHT_BLUE);
	if (n == 8)
		return (DARK_BLUE);
	if (n == 9)
		return (PINK);
	else
		return (FLUO_PINK);
}

int		random_int(int min, int max)
{
	return (min + rand() % (max + 1 - min));
}

int		grad_color(t_param *param, int i, int j)
{
	if (param->map[i][j] <= -10)
		return (0000000124);
	else if (param->map[i][j] > -10 && param->map[i][j] <= 0)
		return (0107226247);
	else if (param->map[i][j] > 0 && param->map[i][j] <= 9)
		return (0000255000);
	else if (param->map[i][j] > 9 && param->map[i][j] <= 20)
		return (0140072000);
	else if (param->map[i][j] > 20 && param->map[i][j] <= 100)
		return (0x563a13);
	else
		return (0xffffff);
}

void	change_background(t_param *param)
{
	int i;

	i = -1;
	while (i++ < (WINDOW_W * WINDOW_H - 1))
		param->data_addr[i] = param->background_color;
}

void	square(int x_pos, int size, int color, t_param *param)
{
	int			cur_x;
	int			cur_y;
	int			end_x;
	int			end_y;

	cur_x = x_pos;
	cur_y = WINDOW_H - 130;
	end_x = x_pos + size;
	end_y = WINDOW_H - 130 + size;
	while (cur_x < end_x)
	{
		cur_y = WINDOW_H - 130;
		while (cur_y < end_y)
		{
			put_pixel_to_img(cur_x, cur_y, color, param);
			cur_y++;
		}
		cur_x++;
	}
}
