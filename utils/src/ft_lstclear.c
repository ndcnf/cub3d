#include "../../utils/inc/libft.h"

/*

Function name 
ft_lstclear

Prototype 
void ft_lstclear(t_list **lst, void (*del)(void*));


Turn in files 
-

Parameters
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.

Return value 
None

External 
functs. free

Description 
Deletes and frees the given node and every successor of that node, 
using the function ’del’ and free(3). Finally, the pointer to the list 
must be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
	}
}
