
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointsrc;
	unsigned char	*pointdest;

	pointsrc = (unsigned char *)src;
	pointdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		pointdest[i] = pointsrc[i];
		if (pointdest[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
