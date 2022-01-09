
#include "libft.h"

int		got_endline(char **line2, char **line)
{
	char *tmp;

	if (*line2[0] == END)
		return (0);
	if (ft_strchri(*line2, ENDLINE))
	{
		*ft_strchr(*line2, ENDLINE) = END;
		if (!(*line = ft_strdup(*line2)))
			return (-1);
		if (!(tmp = ft_strdup(ft_strchr(*line2, END) + 1)))
			return (-1);
		free(*line2);
		if (!(*line2 = ft_strdup(tmp)))
			return (-1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*line2);
		ft_strdel(line2);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		buffer[BUFF_SIZE + 1];
	static char	*line2[OPEN_MAX];
	char		*tmp;

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (!(line2[fd]))
		if (!(line2[fd] = ft_strnew(0)))
			return (-1);
	while (!ft_strchri(line2[fd], ENDLINE))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = END;
		if (ret == 0)
			break ;
		if (!(tmp = ft_strjoin(line2[fd], buffer)))
			return (-1);
		free(line2[fd]);
		if (!(line2[fd] = ft_strdup(tmp)))
			return (-1);
		free(tmp);
	}
	return (got_endline(&line2[fd], line));
}
