/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:37:32 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 17:39:35 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	new_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img->addr + (y * d->img->line_length + x * (d->img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_win(void)
{
	printf(BYE);
	exit(SUCCESS);
}

int	update_img(t_data *d)
{
	main_raycasting(d);
	map2d(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	return (EXIT_SUCCESS);
}
