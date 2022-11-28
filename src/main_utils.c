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

void	safe_free(void *x)
{
	if (x)
	{
		free(x);
		x = NULL;
	}
}

int	p_error(char *error)
{
	ft_putstr_fd(error, 2);
	return (ERROR);
}

int	args_error(int ac)
{
	if (ac == 1)
	{
		printf("❌ Cud3d needs a *.cub in map folder as an argument\n");
		return (ERROR);
	}
	if (ac > 2)
	{
		printf("❌ Only one argument needed\n");
		return (ERROR);
	}
	return (SUCCESS);
}

void	free_map(t_data *data)
{
	safe_free(data->no);
	safe_free(data->ea);
	safe_free(data->we);
	safe_free(data->so);
	safe_free(data->mlx);
	safe_free(data->img_no);
	safe_free(data->img_so);
	safe_free(data->img_ea);
	safe_free(data->img_we);
	safe_free(data->img);
	free_tab((void *)data->map);
}

int	safe_open_map_name_cub(const char *mn)
{
	int	len;

	len = (int)ft_strlen(mn);
	if (mn == NULL || len < 4 || (ft_strncmp(&mn[len - 4], ".cub", 5) != 0))
		return (-1);
	else
		return (open(mn, O_RDONLY));
}
