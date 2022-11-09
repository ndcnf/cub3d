/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:42:04 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/09 13:51:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main_minimap(t_data *d)
{
	init_map(d);
	map2d(d);
	player_angle(d);
	mlx_key_hook(d->win, key_on, d);
	mlx_loop_hook(d->mlx, update_img, d);
	mlx_hook(d->win, X_BTN, 0, close_win, &d);
	mlx_loop(d->mlx);

	return (SUCCESS);
}
