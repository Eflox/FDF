
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	c2;
	size_t			i;

	i = 0;
	c2 = (unsigned char)c;
	res = (unsigned char *)s;
	while (n--)
	{
		if (res[i] == c2)
			return (res + i);
		i++;
	}
	return (0);
}
