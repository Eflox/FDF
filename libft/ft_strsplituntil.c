
#include "libft.h"

char	*ft_strsplituntil(char *str, char c, int after)
{
	char	*leftovers;
	int		i;
	int		u;

	u = -1;
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (after)
		i++;
	leftovers = (char*)malloc(sizeof(*leftovers) * ft_strlen(str) - i + 1);
	if (str[i])
		while (str[i++])
			leftovers[++u] = str[i];
	leftovers[u] = '\0';
	return (leftovers);
}
