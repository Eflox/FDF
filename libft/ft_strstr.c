
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*haystack1;
	char	*needle1;
	int		i;
	int		j;

	i = 0;
	haystack1 = (char *)haystack;
	needle1 = (char *)needle;
	if (needle1[0] == '\0')
		return (haystack1);
	while (haystack1[i] != '\0')
	{
		j = 0;
		while (needle1[j] == haystack1[i + j])
		{
			if (needle1[j + 1] == '\0')
				return (haystack1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
