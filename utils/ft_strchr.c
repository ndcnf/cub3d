/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 03:28:18 by lzima             #+#    #+#             */
/*   Updated: 2021/11/15 21:46:54 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is
     considered to be part of the string; therefore if c is `\0', the func-
     tions locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the
     last occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located
     character, or NULL if the character does not appear in the string.


char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	// here, the loop stop at the first occurence.
	{
		if (*s++ == '\0')
		//here, if s come to an end, nothing have been found.
		//but if c == '\0', the first condition will get it.
			return (0);
	}
	return ((char *)s);
}
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s++ == '\0')
			return (0);
	}
	return ((char *)s);
}
