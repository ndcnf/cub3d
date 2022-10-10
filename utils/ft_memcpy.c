/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:27:38 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 18:31:24 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	memcpy -- copy memory area from src to dst as much as n

DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.
	 */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dtab;
	unsigned const char	*stab;

	if (dst == src)
		return (dst);
	dtab = (unsigned char *)dst;
	stab = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		dtab[i] = stab[i];
		i++;
	}
	return (dtab);
}
