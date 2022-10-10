/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 01:54:58 by lzima             #+#    #+#             */
/*   Updated: 2021/11/15 23:35:47 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strnstr() function locates the first occurrence of the null-terminated 
	string needle in the
     string haystack, where not more than len characters are searched.  
	 Characters that appear after
     a `\0' character are not searched.  Since the strnstr() function is a 
	 FreeBSD specific API, it
     should only be used when portability is not a concern.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs 
	 nowhere in haystack, NULL
     is returned; otherwise a pointer to the first character of the first 
	 occurrence of needle is
     returned.

	while 0 > i < len
	 if needle[i] == NULL
	 	return (haystack);
	if needle++ != haystack
		return (NULL)
	else
		return(char * needle == haystack)


Occurence d une string dans une autre string et non du premier character ?
*/
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && needle[j] && j + i < len)
			j++;
		if (j == ft_strlen(needle))
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
