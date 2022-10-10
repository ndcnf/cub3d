/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:55:28 by lzima             #+#    #+#             */
/*   Updated: 2022/01/03 19:25:56 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlen, strnlen -- find length of string */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main()
{
	char	test[] = "coucou";

	printf("Salut : %zu\n", ft_strlen(test));
}*/
