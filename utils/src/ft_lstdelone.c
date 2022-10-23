/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:11:16 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:11:37 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/inc/libft.h"
/*

Function name 
ft_lstdelone

Prototype 
void ft_lstdelone(t_list *lst, void (*del)(void*));

Turn in files 
-

Parameters 
lst: The node to free.
del: The address of the function used to deletethe content.

Return value 
None

External functs. 
free

Description 
Takes as a parameter a node and frees the memory 
of the node’s content using the function ’del’ given as a 
parameter and free the node. The memory of ’next’ must not be freed.

*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
