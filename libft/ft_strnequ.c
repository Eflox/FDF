
#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t size)
{
	if (!(s1) || !(s2))
		return (0);
	if (ft_strncmp(s1, s2, size) == 0)
		return (1);
	return (0);
}
