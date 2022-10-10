/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:48:19 by lzima             #+#    #+#             */
/*   Updated: 2021/11/17 00:00:14 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function applies the given function f to each character of the given
 * string in order to create a new string that is the result of have function
 * f run on string s. It will return a 'fresh' copy of the modified string
 * 
Function name
  		ft_strmapi
Prototype 
		char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Turn in files 
		-
Parameters 
		#1. The string on which to iterate.
		#2. The function to apply to each character.
Return value 
		The string created from the successive applications
		of ’f’. Returns NULL if the allocation fails.
External functs. 
		malloc
Description 
		Applies the function ’f’ to each character of
		the string ’s’ , and passing its index as first
		argument to create a new string (with malloc(3))
		resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	if (!str)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
