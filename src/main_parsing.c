/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/28 17:41:15 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_load_map(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->nb_line_map)
		printf("%s\n", d->map[i]);
}

void	print_load_asset(t_data *d)
{
	printf("NO \"%s\"\n", d->no);
	printf("SO \"%s\"\n", d->so);
	printf("WE \"%s\"\n", d->we);
	printf("EA \"%s\"\n\n", d->ea);
	printf("F \"%d\"\n", d->f);
	printf("C \"%d\"\n\n", d->c);
	printf("Player orientation(%c) at x: \"%f\"\n", d->pos, d->pposx);
	printf("Player orientation(%c) at y: \"%f\"\n\n", d->pos, d->pposy);
}

int	main_parsing(int ac, char **av, t_data *data)
{
	int		fd;

	printf("⏳ Init game\n");
	if (args_error(ac) != SUCCESS)
		return (ERROR);
	printf("✅ args_error(ac)\n");
	fd = safe_open_map_name_cub(av[1]);
	if (fd == -1)
		return (ERROR);
	close(fd);
	if (load_map(data, fd, av[1]) != SUCCESS)
		return (ERROR);
	close(fd);
	printf("✅ load_map(&data, fd, av[1])\n\n");
	print_load_asset(data);
	print_load_map(data);
	return (SUCCESS);
}
