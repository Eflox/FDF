
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content)
	{
		if ((newlist->content = malloc(sizeof(content) * content_size)) == NULL)
			return (NULL);
		newlist->content_size = content_size;
		ft_memcpy((newlist->content), content, sizeof(content) * content_size);
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	newlist->next = NULL;
	return (newlist);
}
