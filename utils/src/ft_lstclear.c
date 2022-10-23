/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:10:53 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:11:04 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
