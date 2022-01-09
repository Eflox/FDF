
#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *ne)
{
	ne->next = *alst;
	*alst = ne;
}
