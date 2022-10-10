/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:07:02 by lzima             #+#    #+#             */
/*   Updated: 2021/11/03 02:28:18 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	bzero -- write zeroes to a byte string 
	The bzero() function writes n zeroed bytes to the string s.  
	If n is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
