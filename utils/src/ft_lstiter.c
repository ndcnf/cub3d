
#include "../../utils/inc/libft.h"

/*

Function name 
ft_lstiter

Prototype 
void ft_lstiter(t_list *lst, void (*f)(void *));

Turn in files 
-

Parameters 
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.

Return value 
None

External functs. 
None

Description 
Iterates the list ’lst’ and applies the function ’f’ on the content 
of each node.

*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (lst != NULL)
	{
		next = lst;
		while (1)
		{
			(*f)(next->content);
			next = next->next;
			if (next == NULL)
				return ;
		}
	}
}
