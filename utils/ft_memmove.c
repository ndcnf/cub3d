/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:48:15 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 18:32:13 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dtab;
	unsigned const char	*stab;

	if (dst == NULL && src == NULL)
		return (NULL);
	dtab = (unsigned char *)dst;
	stab = (unsigned const char *)src;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			dtab[len] = stab[len];
	}
	return (dst);
}
