/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/18 11:00:58 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int init_struct(t_data *d)
{
	d = ft_calloc(1, sizeof(t_data));
	if (alloc_check(d) != SUCCESS)
		return (ERROR);
	d->ray = ft_calloc(1, sizeof(t_rayunits));
	if (alloc_check(d) != SUCCESS)
		return (ERROR);
	d->x = ft_calloc(1, sizeof(t_raycasting));
	if (alloc_check(d) != SUCCESS)
		return (ERROR);
	d->y = ft_calloc(1, sizeof(t_raycasting));
	if (alloc_check(d) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}


int main(int ac, char **av)
{
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (init_struct(&data) != SUCCESS)
		return (0);
	if (main_parsing(ac, av, &data) != SUCCESS)
		return (0);
	main_minimap(&data);
	// raycasting(&data);
	free_map(&data);
	return (0);
}
