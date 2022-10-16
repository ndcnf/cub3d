/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 02:34:21 by lzima             #+#    #+#             */
/*   Updated: 2022/01/10 22:49:53 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The strdup() function allocates sufficient memory for a copy of the string s1, 
 does the copy, and returns a pointer to it.  The pointer may subsequently be 
 used as an argument to the function free(3).

COMMENTED
#include "utils.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	// malloc(size_t of strlen(s1) will be multiplicated with sizeof(char))
	// to allocate as much as char spaces from s1
	// because strlen doesn't count the final '/0' of s1, we need to add +1
	// so s1 '/0' will be duplicated to the s2.
	if (!s2)
		return (NULL);
		// security : if RAM is not eof allocated mem for s2,
		// it will return 0
	ft_memcpy(s2, s1, (ft_strlen(s1) + 1));
	// memcpy will take src as s1, dst as s2, then, copy src to dst
	// + 1 for the ft_strlen to count '/0'.
	return (s2);
}
*/

#include "../../utils/inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, (ft_strlen(s1) + 1));
	return (s2);
}
