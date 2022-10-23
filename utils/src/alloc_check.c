/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:44:46 by lzima             #+#    #+#             */
/*   Updated: 2022/10/23 18:22:04 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../utils/inc/libft.h"

int	alloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("An error as occurred during a dynamic allocation\n", 2);
		return (1);
	}
	return (0);
}
