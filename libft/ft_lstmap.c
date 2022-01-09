
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	tmp1 = f(lst);
	if ((tmp2 = ft_lstnew(tmp1->content, tmp1->content_size)) == NULL)
		return (NULL);
	lst = lst->next;
	new = tmp2;
	while (lst)
	{
		tmp1 = f(lst);
		if ((tmp2->next = ft_lstnew(tmp1->content, tmp1->content_size)) == NULL)
			return (NULL);
		tmp2 = tmp2->next;
		lst = lst->next;
	}
	return (new);
}
