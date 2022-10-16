/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:32:02 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int    main(int ac, char **av)
{
	t_data	data;

	printf("Init game\n");
	ft_bzero(&data, sizeof(t_data));
	if (args_error(ac) == ERROR)
		return (SUCCESS);
	if (load_map(&data, av[1]) == ERROR)
		return (SUCCESS);
}
