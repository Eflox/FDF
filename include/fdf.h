
#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_param
{
	char	*name;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data_addr;
	int		background_color;
	int		*heights;
	int		**map;
	int		max_x;
	int		max_y;
	int		x;
	int		x2;
	int		y;
	int		y2;
	int		horizontal;
	int		vertical;
	int		zoom;
	double	x_angle;
	double	y_angle;
	double	change_z;
	int		flip;
	int		dots_or_lines;
}				t_param;

# define ANGLE 0.1
# define WHITE 0xFFFFFF
# define SILVER	0xC0C0C0
# define ORANGE 0xF78130
# define SILVER	0xC0C0C0
# define ORANGE 0xF78130
# define FLUO_YELLOW 0xF9F641
# define FLUO_GREEN 0x31FA3E
# define BLUE_GREEN 0xF9F641
# define LIGHT_BLUE 0x41F9E6
# define DARK_BLUE	0x0913E9
# define PINK 0xE909D1
# define FLUO_PINK 0xff1493
# define BLACK 0x000000
# define DARK_GRAY 0x151F25

# define WINDOW_H 600
# define WINDOW_W 900

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define A_KEY 0
# define B_KEY 11
# define C_KEY 8
# define D_KEY 2
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 1
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 13
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6
# define SP_KEY 49
# define MN_KEY 27
# define PL_KEY 24
# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define ESC_KEY 53
# define TAB_KEY 48

void			main_stuff(t_param *param);
int				random_color(void);
int				random_int(int min, int max);
int				deal_key(int key, t_param *param);
int				mouse_hook(int button, int x, int y, t_param *param);
void			ft_menu(t_param *param);
void			read_file(t_param *param);
int				coord_x(int x, int y, t_param *param);
int				coord_y(int x, int y, int z, t_param *param);
void			initialize(t_param *param);
void			strings(t_param *param);
void			put_pixel_to_img(int x, int y, int color, t_param *param);
void			open_other_map(int y, t_param *param);
void			draw_map(t_param *param);
int				grad_color(t_param *param, int i, int j);
void			change_background(t_param *param);
void			erase_put_back(t_param *param);
void			rotate(int key, t_param *param);
void			change_background_key(int x, t_param *param);
void			bresenham(int color, t_param *param);
void			bresenham_2(int w_h[2], int delta_x_y[4], int color,\
	t_param *param);
void			bresenham_3(int delta_x_y[4], int long_short[2], int color,\
	t_param *param);
void			img_bresenham(int color, t_param *param);
void			img_bresenham_2(int w_h[2], int delta_x_y[4], int color, \
	t_param *param);
void			img_bresenham_3(int delta_x_y[4], int long_short[2], int color,\
	t_param *param);
int				loop(t_param *param);
void			ft_menu_2(t_param *param);
void			ft_menu_3(t_param *param);
void			ft_menu_4(t_param *param);
void			ft_menu_5(t_param *param);
void			box(t_param *param);
void			box_2(t_param *param);
void			box_3(t_param *param);
void			line_map(int i, int j, t_param *param);
void			dot_map(int i, int j, t_param *param);
void			main_stuff2(t_param *param);
void			zoom_move(int key, t_param *param);
void			change_background_key2(int x, t_param *param);
void			mouse_line(int x, int y, t_param *param);
void			map_zoom(t_param *param);
void			save_map(char *line2, t_param *param);
void			exit_fdf(t_param *param, char *str);
void			square(int x_pos, int size, int color, \
	t_param *param);

#endif
