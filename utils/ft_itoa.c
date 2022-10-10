/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:53:20 by lzima             #+#    #+#             */
/*   Updated: 2021/11/16 18:16:13 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

static int	intlen(int n)
//for the memory allocation for itoa.
{
	int	size;

	size = 0;
	if (n <= 0)
	//if n of ft_itoa(n) is negative, it will skip the '-'. 
		size++;
	while (n != 0)
	//to go through n, every /10 will count in size as 1.
	//1234 /10 = 123 /10 = 12 /10 = 1/10 = 0 ---size = 4
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*getnumber(char *str, unsigned int n, int size)
// to convert int n in char *str with n %10
// n = 123 %10 = 123/10 = 12 and 3 remains, so n = 3.
// 3 + '0' will give us 3 as a char in ascii decimal set.
{
	
	while (n > 0)
	{
		str[size--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	number;

	size = intlen(n);
	str = (char *)malloc(size * sizeof(char) + 1);
	//size have been calculated with intlen.
	if (!str)
	//to protect malloc.
		return (0);
	str[size--] = '\0';
	//str[size] + 1 give us the end of str, then set up the '\0'.
	if (n == 0)
	//otherwise, 0 won't be convert.
		str[0] = '0';
	if (n < 0)
	//handle if n is neg, then set n as positif, and write -.
	{
		number = n * -1;
		str[0] = '-';
	}
	else
	//get n value, and use it in number for getnumber.
		number = n;
	str = getnumber(str, number, size);
	//this will do the trick.
	return (str);
}
*/

#include "libft.h"

static int	intlen(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*getnumber(char *str, unsigned int n, int size)
{
	while (n > 0)
	{
		str[size--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*str;
	unsigned int	number;

	size = intlen(n);
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	str[size--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	str = getnumber(str, number, size);
	return (str);
}
