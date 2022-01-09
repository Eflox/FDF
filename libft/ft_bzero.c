
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*point;

	point = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		point[i] = 0;
		i++;
	}
}
