
#include "libft.h"

int	*ft_strnew_int(size_t size)
{
	int	*str;

	str = (int *)malloc(sizeof(int) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
