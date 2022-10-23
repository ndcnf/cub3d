/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:10:12 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:10:40 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/inc/libft.h"

/*

Function name 
ft_lstadd_front

Prototype 
void ft_lstadd_front(t_list **lst, t_list *new);

Turn in files -

Parameters 
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.

Return value 
None

External functs. 
None

Description 
Adds the node ’new’ at the beginning of the list.

*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (! alst || ! new)
		return ;
	new->next = *alst;
	*alst = new;
}
