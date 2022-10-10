/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 03:38:43 by lzima             #+#    #+#             */
/*   Updated: 2021/11/17 00:03:55 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
		ft_substr
Prototype 
		char *ft_substr(char const *s, unsigned int start, size_t len);
Turn in files 
		-
Parameters 
		#1. The string from which to create the substring.
		#2. The start index of the substring in the string ’s’.
		#3. The maximum length of the substring.
Return value 
		The substring. NULL if the allocation fails.
External functs. 
		malloc
Description 
		Allocates (with malloc(3)) and returns a substring from the string ’s’.
		The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	i = 0;
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	s2 = malloc(((len + 1)) * sizeof(char));
	if (!s2 || !s)
		return (NULL);
	while (i < len && start < slen)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
