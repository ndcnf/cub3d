
#include "../../utils/inc/libft.h"

/*

Function name 
ft_lstlast

Prototype 
t_list *ft_lstlast(t_list *lst);

Turn in files 
-

Parameters 
lst: The beginning of the list.

Return value 
Last node of the list

External functs. 
None

Description 
Returns the last node of the list.

*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
