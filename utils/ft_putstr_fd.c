/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:53:02 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 22:53:41 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
		ft_putstr_fd
Prototype 
		void ft_putstr_fd(char *s, int fd);
Turn in files 
		-
Parameters 
		#1. The string to output.
		#2. The file descriptor on which to write.
Return value 
		None
External functs. 
		write
Description 
		Outputs the string ’s’ to the given file
descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
