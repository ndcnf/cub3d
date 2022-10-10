/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:45 by lzima             #+#    #+#             */
/*   Updated: 2022/01/10 22:35:04 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int	ft_gstrlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gstrjoin(char *s1, char const	*s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	len = ft_gstrlen(s1) + ft_gstrlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_gstrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (&((char *)str)[i]);
	if (str[i] == '\0' && (char)c == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}

char	*ft_gstrdup(char *s1)
{
	int		slen;
	int		i;
	char	*str;

	slen = ft_gstrlen((char *)s1);
	i = -1;
	str = (char *)malloc(slen + 1);
	if (!str)
		return (NULL);
	while (++i < slen)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_gsubstr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && start < (unsigned int)ft_gstrlen(s))
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
