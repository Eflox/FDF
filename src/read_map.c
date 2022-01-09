
#include "../include/fdf.h"

char	*get_num2(char *line2, t_param *param)
{
	char	*temp;
	char	*temp2;

	if (!(temp = ft_strsplituntil(line2, ' ', 0)))
		exit_fdf(param, "Malloc error");
	ft_strdel(&line2);
	while (temp[0] == ' ')
	{
		temp2 = temp;
		if (!(temp = ft_strsplituntil(temp2, ' ', 0)))
			exit_fdf(param, "Malloc error");
		ft_strdel(&temp2);
	}
	if (!(line2 = ft_strdup(temp)))
		exit_fdf(param, "Malloc error");
	ft_strdel(&temp);
	return (line2);
}

int		get_num(char **line, t_param *param)
{
	int		i;
	char	*line2;
	char	*str;
	int		num;

	if (*line == NULL || *line[0] == '\0')
		return (0);
	if (!(line2 = ft_strdup(*line)))
		exit_fdf(param, "Malloc error");
	ft_strdel(line);
	i = -1;
	while (ft_isdigit(line2[++i]))
		;
	if (!(str = ft_strnew(i)))
		exit_fdf(param, "Malloc error");
	i = -1;
	while (ft_isdigit(line2[++i]))
		str[i] = line2[i];
	*line = get_num2(line2, param);
	num = ft_atoi(str);
	ft_strdel(&str);
	return (num);
}

void	read_file(t_param *param)
{
	char		*line;
	char		*line2;
	char		*temp;

	param->max_x = 0;
	if (!(line2 = ft_strnew(0)))
		exit_fdf(param, "Malloc error");
	while (get_next_line(param->fd, &line) == 1)
	{
		param->max_y = ft_countwords(line, ' ');
		if (!(temp = ft_strjoin(line2, "  ")))
			exit_fdf(param, "Malloc error");
		ft_strdel(&line2);
		if (!(line2 = ft_strjoin(temp, line)))
			exit_fdf(param, "Malloc error");
		ft_strdel(&line);
		ft_strdel(&temp);
		param->max_x++;
	}
	if (get_next_line(param->fd, &line) < 0)
		exit_fdf(param, "Error: File is not valid");
	save_map(line2, param);
	ft_strdel(&line2);
	ft_strdel(&temp);
	ft_strdel(&line);
}

void	save_map(char *line2, t_param *param)
{
	int			i;
	int			j;
	char		*temp;

	temp = ft_strdup(line2);
	if (!temp || !(line2 = ft_strjoin(temp, "  ")))
		exit_fdf(param, "Malloc error");
	ft_strdel(&temp);
	if (!(param->map = (int**)malloc(sizeof(int*) * param->max_x + 1)))
		exit_fdf(param, "Malloc error");
	i = -1;
	while (++i < param->max_x)
		if (!(param->map[i] = (int*)malloc(sizeof(int) * param->max_y + 1)))
			exit_fdf(param, "Malloc error");
	get_num(&line2, param);
	i = -1;
	while (++i < param->max_x)
	{
		j = -1;
		while (++j < param->max_y)
			param->map[i][j] = get_num(&line2, param);
	}
	ft_strdel(&line2);
	ft_strdel(&temp);
	map_zoom(param);
}

void	map_zoom(t_param *param)
{
	int angle;

	angle = param->x_angle;
	if (param->x_angle < param->y_angle)
		angle = param->y_angle;
	if (param->max_x > param->max_y)
		param->zoom = 2000 / param->max_x / angle;
	else
		param->zoom = 2000 / param->max_y / angle;
}
