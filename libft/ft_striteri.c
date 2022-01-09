
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s != NULL && f)
	{
		while (*s && f)
		{
			f(i, s);
			s++;
			i++;
		}
	}
	else
		return ;
}
