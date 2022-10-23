/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:56:38 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:19:16 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strtrim
char *ft_strtrim(char const *s1, char const *set);

Paramètres 			#1. La chaine de caractères à trimmer.
					#2. Le set de reference de caractères à trimmer.
Valeur de retour 	La chaine de caractères trimmée. NULL si
					l’allocation échoue.
Fonctions externes autorisées
					malloc
Description 		Alloue (avec malloc(3)) et retourne une copie de
					la chaine ’s1’, sans les caractères spécifiés
					dans ’set’ au début et à la fin de la chaine de
					caractères.
*/

#include "../../utils/inc/libft.h"

static char	*selftrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (i < j && ft_strchr(set, s1[j]))
		j--;
	res = ft_substr(s1, i, j - i + 1);
	return (res);
}

int	leakfree_strtrim(char **s1, const char *set)
{
	char	*trim;

	trim = selftrim(*s1, set);
	free(*s1);
	if (trim == NULL)
		return (1);
	*s1 = trim;
	return (0);
}
