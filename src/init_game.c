/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:01 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:29:01 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int read_map(t_data *data, int fd, const char *map_cub)
{
	fd = open(map_cub, O_RDONLY);
	if (asset(data, fd) != SUCCESS)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	printf("✅ asset(data, fd) \n");
	fd = open(map_cub, O_RDONLY);
	if (pars_map(data, fd) != SUCCESS)
	{
		close(fd);
		return (ERROR);
	}
	printf("✅ pars_map(data, fd) \n");
	close(fd);
	fd = open(map_cub, O_RDONLY);
	if (stock_map(data, fd) != SUCCESS)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	printf("✅ stock_map(data, fd) \n");
	return (SUCCESS);
}

int	load_map(t_data *data, int fd, char *map_cub)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
	data->pposx = -1;
	data->pposy = -1;

	if (read_map(data, fd, map_cub) != SUCCESS)
	{
		free_map(data);
		close(fd);
		p_error("❌ read_map(data, fd, map_cub)\n");
		return (ERROR);
	}
	printf("✅ read_map(data, fd, map_cub) \n");
	return (SUCCESS);
}
