/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/16 14:07:28 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int f_and_c(t_data *data)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while(x < WIN_W)
// 	{
// 		y = 0;
// 		while(y < WIN_H / 2)
// 		{
// 			new_mlx_pixel_put(data, x, y, data->f);
// 			y++;
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	while(x < WIN_W) {
// 		y /= 2;
// 		while (y < WIN_H) {
// 			new_mlx_pixel_put(data, x, y, data->c);
// 			y++;
// 		}
// 		x++;
// 	}
// 	return(1);
// }

// int raycasting(t_data *data)
// {
// 	init_map(data);
// 	f_and_c(data);
// 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
// 	mlx_key_hook(data->win, key_on, &data);
// 	mlx_loop(data->mlx);
// 	return (1);
// }

void	distance(t_data *d)
{
	if (WIN_H >= WIN_W)
		d->ray->dist_max = WIN_H * ZOOM;
	else
		d->ray->dist_max = WIN_W * ZOOM;
	d->ray->dist = 0;
	printf("distance max : [%f]", d->ray->dist_max);
}

int	raycasting(t_data *d)
{
	distance(d);
	d->x->map_sz = WIN_W * ZOOM;
	d->y->map_sz = WIN_H * ZOOM;

	d->ray->tile_found = 0;

	d->x->ray_start = d->pposx;
	d->y->ray_start = d->pposy;
	d->x->map_check = d->x->ray_start;
	d->y->map_check = d->y->ray_start;

	// raydirx; // valeur ?
	// raydiry; // valeur ?

	d->x->step_sz = sqrt(1 + pow(d->y->ray_dir / d->x->ray_dir, 2));
	d->y->step_sz = sqrt(1 + pow(d->x->ray_dir / d->y->ray_dir, 2));

	if (d->x->ray_dir < 0)
	{
		d->x->step = -1;
		d->x->ray_len = (d->x->ray_start - d->x->map_check) * d->x->step_sz;
	}
	else
	{
		d->x->step = 1;
		d->x->ray_len = ((d->x->map_check + 1) - d->x->ray_start) * d->x->step_sz;
	}

	if (d->y->ray_dir < 0)
	{
		d->y->step = -1;
		d->y->ray_len = (d->y->ray_start - d->y->map_check) * d->y->step_sz;
	}
	else
	{
		d->y->step = 1;
		d->y->ray_len = ((d->y->map_check + 1) - d->y->ray_start) * d->y->step_sz;
	}

	while (!d->ray->tile_found && d->ray->dist < d->ray->dist_max)
	{
		if (d->x->ray_len < d->y->ray_len)
		{
			d->x->map_check += d->x->step;
			d->ray->dist = d->x->ray_len;
			d->x->ray_len += d->x->step_sz;
		}
		else
		{
			d->y->map_check += d->y->step;
			d->ray->dist = d->y->ray_len;
			d->y->ray_len += d->y->step_sz;
		}

		// if (d->x->map_check >= 0 && d->x->map_check < d->x->map_sz && d->y->map_check >= 0 && d->y->map_check < d->y->map_sz)
		// {
		// 	if (d->map[d->y->map_check * d->x->map_sz + d->x->map_check]) // == 1
		// 	{
		// 		d->ray->tile_found = 1;
		// 	}
		// }
	}

	// if (d->ray->tile_found)
	// {
	// 	intersection = raystart + raydir * dist;
	// 	//attention, il n'y a pas de x et y ici. Bien comprendre et adapter !
	// }
	return (0);
}
