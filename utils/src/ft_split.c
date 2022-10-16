/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:23:12 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 23:27:21 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name 
					ft_split
Prototype 
					char **ft_split(char const *s, char c);
Fichiers de rendu 
					-
Paramètres 
					#1. La chaine de caractères à découper.
					#2. Le caractère délimitant.
Valeur de retour
					Le tableau de nouvelles chaines de caractères,
					résultant du découpage. NULL si l’allocation
					échoue.
Fonctions externes autorisées
					malloc, free
Description 
					Alloue (avec malloc(3)) et retourne un tableau
					de chaines de caracteres obtenu en séparant ’s’ à
					l’aide du caractère ’c’, utilisé comme délimiteur.
					Le tableau doit être terminé par NULL.


//#include "utils.h"

//static : a static function in C is a function that has a scope that is 
//limited to its object file. This means that the static function is 
//only visible in its object file. A function can be declared as static 
//function by placing the static keyword before the function name.

//count_words is used in our **ft_split to open the first *tab, and add
//memory allocation for each words counted, between separator.
//cf in ft_split :

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

//trigger will work as a switch :
//Why should we use a trigger.
//It's necessary for memory allocation.
//With the split test :

//"STR: "UN_DEUX_TROIS"
//SEP: '\0'
//Your ft_split returned a tab of the following strings:
//0: "UN_DEUX_TROIS"
//1: (null)
//Memory bytes allocated and used by your str_tab: 128
//Memory bytes allocated and used by my str_tab: 32"

//Without the trigger, it's x4 time for the same result. 
//Our condition trigger == 0, will just passed all the word,
//because when it found one, we set the trigger at 1, so 
//the condition trigger == 0 isn't good until the next word.


	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		//The same c than in ft_split will be use, it's the separator.
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
		// If *str is c, then trigger switch off.
		//The if/else if statement allows you to create a chain of if 
		//statements. The if statements are evaluated in order until 
		//one of the if expressions is true or the end of the if/else if 
		//chain is reached.  If the end of the if/else if chain is 
		//reached without a true expression, no code blocks are executed.
			trigger = 0;
		str++;
	}
	return (i);
}

// subword is to get a word from :start to :finish and copy it.

static char	*oneword(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	// subtract start a finish, to get the size of the word (+ 1 for the \0)
	// then, all the magic will happen in ft_split, with argv of subword.
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)

// SO ! The beast !

//How does it works ?

//For a simple example with the string = "_SPLIT_MY_ASS_"

//it will search in the str "_SPLIT_MY_ASS_" how many words are in the string,
//with '_' as a separateur (c).

//Result will be :
//   01234
// 0 SPLIT
// 1 MY
// 2 ASS
// 3 null

{
	size_t	i;
	size_t	j;
	int		start;
	char	**splitwords;
	// **split will be our first tab, 1 pointeur string for 1 word.
	if (!s)
		return (0);
	splitwords = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitwords)
		return (0);
	i = -1;
	// for ++i incrementation.
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	// i = 0 then +1 with incrementation to go through one string word.
	// for example : str = "_SPLITT_MY_ASS_" and c = '_';
	{
		if (s[i] != c && start < 0)
		// if s[i] ≠ '_' and start is still -1.
		// => it's not the separateur but it didn't start the word of the s string. 
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)

		// 2 within 1 conditions :

		// 		s[i] == c means that *s has come to a separateur
		// or 	i == ft_strlen(s) means that *s has come to an end.

		// those 2 conditions within :

		//		start >= 0, meaning that we are at least
		//					at the first word's beginning.
		{
			splitwords[j++] = oneword(s, start, i);
			// then, one tab of splitwords = one word
			// s = our string from ft_split
			// start = start of one word
			// i = last character of one word

			start = -1;
			//then, reset start to get back to start = i
		}
	}
	splitwords[j] = 0;
	// return null when no words is find within conditions above.
	return (splitwords);
}
*/
//-----------------------------------------------------------------------------
// without comments
//-----------------------------------------------------------------------------

#include "../../utils/inc/libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*oneword(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**splitwords;

	if (!s)
		return (0);
	splitwords = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!splitwords)
		return (0);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			splitwords[j++] = oneword(s, start, i);
			start = -1;
		}
	}
	splitwords[j] = 0;
	return (splitwords);
}
