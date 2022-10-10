/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:22:13 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 22:51:27 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
		ft_putendl_fd
Prototype 
		void ft_putendl_fd(char *s, int fd);
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
		descriptor, followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
