/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:56:38 by lzima             #+#    #+#             */
/*   Updated: 2021/11/09 20:35:46 by lzima            ###   ########.fr       */
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

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
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
