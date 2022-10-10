/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:54:37 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 23:56:32 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
		ft_striteri
Prototype 
		void ft_striteri(char *s, void (*f)(unsigned int, char*));
Turn in files 
		-
Parameters 
		#1. The string on which to iterate.
		#2. The function to apply to each character.
Return value 
		None.
External functs. 
		None
Description 
		Applies the function f to each character of the
		string passed as argument, and passing its index
		as first argument. Each character is passed by
		address to f to be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
