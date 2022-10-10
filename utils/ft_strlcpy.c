/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:27:43 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 23:59:02 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings
     with the same input parameters and output result as snprintf(3).  They
     are designed to be safer, more consistent, and less error prone
     replacements for the easily misused functions strncpy(3) and
     strncat(3).

     strlcpy() and strlcat() take the full size of the destination buffer
     and guarantee NUL-termination if there is room.  Note that room for
     the NUL should be included in dstsize.

     strlcpy() copies up to dstsize - 1 characters from the string src to
     dst, NUL-terminating the result if dstsize is not 0.

     strlcat() appends string src to the end of dst.  It will append at
     most dstsize - strlen(dst) - 1 characters.  It will then NUL-termi-
     nate, unless dstsize is 0 or the original dst string was longer than
     dstsize (in practice this should not happen as it means that either
     dstsize is incorrect or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.

RETURN VALUES
     Besides quibbles over the return type (size_t versus int) and signal
     handler safety (snprintf(3) is not entirely safe on some systems), the
     following two are equivalent:

           n = strlcpy(dst, src, len);
           n = snprintf(dst, len, "%s", src);

     Like snprintf(3), the strlcpy() and strlcat() functions return the
     total length of the string they tried to create.  For strlcpy() that
     means the length of src.  For strlcat() that means the initial length
     of dst plus the length of src.

     If the return value is >= dstsize, the output string has been trun-
     cated.  It is the caller's responsibility to handle this.
	 */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
