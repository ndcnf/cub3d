/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/10/20 15:43:01 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int    main(int ac, char **av)
{
	t_data	data;
	int		fd;

	printf("Init game\n");
	ft_bzero(&data, sizeof(t_data));
	if (args_error(ac) != SUCCESS)
	{
		return (ERROR);
	}
	fd = safe_open_map_name_cub(av[1]);
	if (fd == -1)
		return (ERROR);
	close(fd);
	if (load_map(&data, fd, av[1]) != SUCCESS)
		return (ERROR);
	close(fd);
	print_asset(&data);
	return (SUCCESS);
}
