/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:09:13 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:09:26 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/inc/libft.h"

/*
Function name 
ft_lstadd_back

Prototype 
void ft_lstadd_back(t_list **lst, t_list *new);

Turn in files 
-

Parameters 
lst: The address of a pointer to the first link ofa list.
new: The address of a pointer to the node to beadded to the list.

Return value 
None

External functs. 
None

Description 
Adds the node ’new’ at the end of the list.

*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}
