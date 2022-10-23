/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:16:13 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:16:36 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/inc/libft.h"

/*Function name 
ft_lstsize

Prototype 
int ft_lstsize(t_list *lst);

Turn in files 
-

Parameters 
lst: The beginning of the list.

Return value 
The length of the list

External functs. 
None

Description 
Counts the number of nodes in a list.
*/

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
