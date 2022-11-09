/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/09 11:02:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (main_parsing(ac, av, &data) != SUCCESS)
		return (0);
	main_minimap(&data);
//	raycasting(&data);
	free_map(&data);
	return (0);
}
