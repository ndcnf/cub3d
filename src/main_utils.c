/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:30:14 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:30:14 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	safe_free(void **x)
{
	if ((*x) != NULL)
	{
		free(*x);
		(*x) = NULL;
	}
}

int	args_error(int ac)
{
	if (ac == 1)
	{
		printf("Error: Cud3d needs a *.cub in map folder as an argument\n");
		return (ERROR);
	}
	if (ac > 2)
	{
		printf("Error: Only one argument needed\n");
		return(ERROR);
	}
	return (SUCCESS);
}

void free_map(t_data *data)
{
	safe_free((void *)&data->no);
	safe_free((void *)&data->so);
	safe_free((void *)&data->we);
	safe_free((void *)&data->ea);
}
