
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	size_t		i;
	size_t		len;

	i = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		res = (char *)malloc(sizeof(char) * len + 1);
		if (res == NULL)
			return (NULL);
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (0);
}
