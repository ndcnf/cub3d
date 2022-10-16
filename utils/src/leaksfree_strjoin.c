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

#include "../../utils/inc/libft.h"

char	*leaksfree_strjoin(char *dynstr, char const *s2)
{
	char	*res;
	int		i1;
	int		i2;
	int		ires;

	ires = 0;
	if (dynstr == NULL || s2 == NULL)
		return (NULL);
	res = ft_calloc((ft_strlen(dynstr) + ft_strlen(s2) + 1), sizeof(char));
	if (! res)
		return (NULL);
	i1 = 0;
	while (dynstr[i1] != '\0')
		res[ires++] = dynstr[i1++];
	i2 = 0;
	while (s2[i2] != '\0')
		res[ires++] = s2[i2++];
	res[ires] = '\0';
	free(dynstr);
	return (res);
}