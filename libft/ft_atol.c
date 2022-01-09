
#include "libft.h"

long		ft_atol(const char *str)
{
	size_t	i;
	size_t	sign;
	long	num;

	i = 0;
	sign = 0;
	num = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-num);
	else
		return (num);
}
