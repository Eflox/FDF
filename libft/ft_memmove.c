
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src1;
	char	*dst1;
	size_t	i;

	i = -1;
	src1 = (char *)src;
	dst1 = (char *)dest;
	if (src1 < dst1)
		while ((int)(--n) >= 0)
			*(dst1 + n) = *(src1 + n);
	else
		while (++i < n)
			*(dst1 + i) = *(src1 + i);
	return (dest);
}
