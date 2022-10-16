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

#include "../../utils/inc/libft.h"

char	*leaksfree_substr(char **s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	isub;

	isub = 0;
	if ((*s) == NULL)
		return (NULL);
	if (start > ft_strlen(*s))
		return (ft_strdup(""));
	if ((ft_strlen(*s) - start) < len)
		substr = malloc((ft_strlen(*s) - start + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (! substr)
		return (NULL);
	while (isub < len && (*s)[start] != '\0')
		substr[isub++] = (*s)[start++];
	substr[isub] = '\0';
	free(*s);
	return (substr);
}
