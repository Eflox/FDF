
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (c1[i] && c2[i] && (c1[i] == c2[i]) && (i < n - 1))
		i++;
	return (c1[i] - c2[i]);
}
