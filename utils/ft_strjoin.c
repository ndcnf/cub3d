/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:19:12 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 23:57:32 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
		ft_strjoin
Prototype 
		char *ft_strjoin(char const *s1, char const *s2);
Turn in files 
		-
Parameters 
		#1. The prefix string.

		#2. The suffix string.
Return value 
		The new string. NULL if the allocation fails.
External functs. 
		malloc
Description 
		Allocates (with malloc(3)) and returns a new
		string, which is the result of the concatenation
		of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	slen1;
	size_t	slen2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	ret = malloc ((slen1 + slen2 + 1) * sizeof(char));
	if (!ret)
		return (0);
	j = 0;
	while (s1[i])
		ret[i++] = s1[j++];
	j = 0;
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}
