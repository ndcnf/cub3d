/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/28 18:05:36 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raydir_n_delta(t_data *d, int x)
{
	d->x->camera = 2 * x / (float)(WIN_H * ZOOM) - 1;
	d->x->ray_dir = d->x->dir + d->x->plane * d->x->camera;
	d->y->ray_dir = d->y->dir + d->y->plane * d->x->camera;
	if (d->x->ray_dir == 0)
		d->x->deltadist = INFINITY;
	else
		d->x->deltadist = fabs(1 / d->x->ray_dir);
	if (d->y->ray_dir == 0)
		d->y->deltadist = INFINITY;
	else
		d->y->deltadist = fabs(1 / d->y->ray_dir);
}

void	step_n_sidedist(t_data *d)
{
	d->ray->hit = 0;
	if (d->x->ray_dir < 0)
	{
		d->x->step = -1;
		d->x->sidedist = (d->pposx - d->x->map) * d->x->deltadist;
	}
	else
	{
		d->x->step = 1;
		d->x->sidedist = (d->x->map + 1.0 - d->pposx) * d->x->deltadist;
	}
	if (d->y->ray_dir < 0)
	{
		d->y->step = -1;
		d->y->sidedist = (d->pposy - d->y->map) * d->y->deltadist;
	}
	else
	{
		d->y->step = 1;
		d->y->sidedist = (d->y->map + 1.0 - d->pposy) * d->y->deltadist;
	}
}

void	hit(t_data *d)
{
	while (d->ray->hit == 0)
	{
		if (d->x->sidedist < d->y->sidedist)
		{
			d->x->sidedist += d->x->deltadist;
			d->x->map += d->x->step;
			d->ray->side = 0;
		}
		else
		{
			d->y->sidedist += d->y->deltadist;
			d->y->map += d->y->step;
			d->ray->side = 1;
		}
		if (d->map[d->y->map][d->x->map] != '0')
			d->ray->hit = 1;
	}
}

void	side(t_data *d)
{
	if (d->ray->side == 0)
		d->ray->perpwalldist = (d->x->sidedist - d->x->deltadist);
	else
		d->ray->perpwalldist = (d->y->sidedist - d->y->deltadist);
}

int	main_raycasting(t_data *d)
{
	int	x;

	x = 0;
	while (x < (WIN_W * ZOOM))
	{
		d->x->map = (int)d->pposx;
		d->y->map = (int)d->pposy;
		raydir_n_delta(d, x);
		step_n_sidedist(d);
		hit(d);
		side(d);
		draw_set(d);
		draw(d, x);
		x++;
	}
	return (SUCCESS);
}
