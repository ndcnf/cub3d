

/*

Function name 
ft_lstmap

Prototype 
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

Turn in files 
-

Parameters 
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if needed.

Return value 
The new list.
NULL if the allocation fails.

External functs. 
malloc, free

Description 
Iterates the list ’lst’ and applies the function ’f’ on the content of each node. 
Creates a new list resulting of the successive applications of the function ’f’. 
The ’del’ function is used to delete the content of a node if needed.  

*/


#include "../../utils/inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}
