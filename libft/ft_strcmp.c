
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 || *c2)
		if (*c1 != *c2)
			return (*c1 - *c2);
		else
		{
			c1++;
			c2++;
		}
	return (0);
}
