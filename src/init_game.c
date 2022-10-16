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

void	print_asset(t_data *d)
{
	printf("NO:%s\n", d->no);
	printf("SO:%s\n", d->so);
	printf("WE:%s\n", d->we);
	printf("EA:%s\n", d->ea);
	printf("F:%s", d->f);
	printf("C:%s", d->c);
}

int read_map(t_data *data, const char *mn)
{
	int fd;

	fd = safe_open_mn(mn);
	if (fd == -1)
		return (ERROR);
	printf("safe_open_mn(mn) OK\n");
	if (asset(data, fd) != SUCCESS)
		return (ERROR);
	printf("asset(data, fd) OK\n");
	print_asset(data);
	if (pars_map(data, fd) != SUCCESS)
		return (ERROR);
	printf("pars_map(data, fd) OK\n");
	close(fd);
	fd = open(mn, O_RDONLY);
	if (stock_map(data, fd) != SUCCESS)
		return (ERROR);
	printf("read_map OK\n");
	return (SUCCESS);

}

int	load_map(t_data *data, char *map_name)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
	data->pposx = -1;
	data->pposy = -1;

	printf("%s\n", map_name);

	if (read_map(data, map_name) != SUCCESS)
	{
		free_map(data);
		printf("Error: invalid map\n");
		return (ERROR);
	}
	return (SUCCESS);
}
