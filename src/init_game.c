/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:01 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:40:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	end_of_file(int fd, char *tmp)
{
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		if (tmp)
			free(tmp);
	}
	tmp = NULL;
}

int	read_map(t_data *data, int fd, const char *map_cub)
{
	char	*tmp;

	fd = open(map_cub, O_RDONLY);
	tmp = get_next_line(fd);
	if (asset(data, fd, tmp) != SUCCESS)
		return (close(fd));
	end_of_file(fd, tmp);
	close(fd);
	printf("✅ asset(data, fd) \n");
	fd = open(map_cub, O_RDONLY);
	if (pars_map(data, fd) != SUCCESS)
		return (close(fd));
	close(fd);
	fd = open(map_cub, O_RDONLY);
	if (stock_map(data, fd) != SUCCESS)
		return (close(fd));
	return (1);
}

int	load_map(t_data *data, int fd, char *map_cub)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = -1;
	data->c = -1;
	data->pposx = -1;
	data->pposy = -1;
	if (read_map(data, fd, map_cub) != 1)
	{
		free_map(data);
		p_error(" ↪ read_map(data, fd, map_cub)\n");
		return (ERROR);
	}
	printf("✅ read_map(data, fd, map_cub) \n");
	return (SUCCESS);
}
