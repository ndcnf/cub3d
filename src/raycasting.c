/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:42:50 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->m2d->addr + (y * data->m2d->line_length + x * (data->m2d->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int f_and_c(t_data *data)
{
	int x;
	int y;

	x = 0;
	while(x < WIN_W)
	{
		y = 0;
		while(y < WIN_H / 2)
		{
			my_mlx_pixel_put(data, x, y, data->f);
			y++;
		}
		x++;
	}
	x = 0;
	while(x < WIN_W) {
		y /= 2;
		while (y < WIN_H) {
			my_mlx_pixel_put(data, x, y, data->c);
			y++;
		}
		x++;
	}
	return(1);
}

int raycasting(t_data *data)
{
	init_map(data);
	f_and_c(data);
	mlx_put_image_to_window(data->mlx, data->win, data->m2d->img, 0, 0);
	mlx_key_hook(data->win, key_on, &data);
	mlx_loop(data->mlx);
	return (1);
}
