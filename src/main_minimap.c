/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:42:04 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 17:41:56 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main_minimap(t_data *d)
{
	init_map(d);
	map2d(d);
	mlx_hook(d->win, 2, (1L << 0), key_on, d);
	mlx_loop_hook(d->mlx, update_img, d);
	mlx_hook(d->win, X_BTN, 0, close_win, &d);
	mlx_loop(d->mlx);
	return (SUCCESS);
}

void	map2d(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->w)
	{
		j = 0;
		while (j < d->h)
		{
			on_minimap(d, i, j, d->map[j][i]);
			j++;
		}
		i++;
	}
	player_is_here(d, RED, BLU);
}

void	minimap_size(t_data *d)
{
	if (d->h <= 30 || d->w <= 30)
		d->mm_size = MM_L;
	else if ((d->h > 30 && d->h <= 60) || (d->w > 30 && d->w <= 60))
		d->mm_size = MM_M;
	else
		d->mm_size = MM_S;
}
