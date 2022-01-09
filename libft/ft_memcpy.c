
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (pointdest);
}
