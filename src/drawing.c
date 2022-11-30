/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:36:57 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 18:05:18 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw(t_data *d, int x)
{
	int	y;

	y = 0;
	while (y <= d->ray->drawstart)
	{
		new_mlx_pixel_put(d, x, y, d->c);
		y++;
	}
	y = d->ray->drawstart;
	while (y <= d->ray->drawend && y < (WIN_H * ZOOM))
	{
		new_mlx_pixel_put(d, x, y, color_side(d));
		y++;
	}
	y = d->ray->drawend;
	while (y < (WIN_H * ZOOM))
	{
		new_mlx_pixel_put(d, x, y, d->f);
		y++;
	}
}

void	draw_set(t_data *d)
{
	d->ray->lineheight = (int)((WIN_H * ZOOM) / d->ray->perpwalldist);
	d->ray->drawstart = -(d->ray->lineheight) / 2 + ((WIN_H * ZOOM) / 2);
	if (d->ray->drawstart < 0)
		d->ray->drawstart = 0;
	d->ray->drawend = d->ray->lineheight / 2 + (WIN_H * ZOOM) / 2;
	if (d->ray->drawend >= (WIN_H * ZOOM))
	// if (d->ray->drawend >= (WIN_H * ZOOM) /*|| r->drawend >= 0*/)
		d->ray->drawend = (WIN_H * ZOOM) - 1;
}

int	color_side(t_data *d)
{
	if (d->ray->side == 0 && d->x->ray_dir < 0)
		return (LGN);
	else if (d->ray->side == 0 && d->x->ray_dir >= 0)
		return (PNK);
	else if (d->ray->side == 1 && d->y->ray_dir < 0)
		return (RED);
	else
		return (BLU);
}
