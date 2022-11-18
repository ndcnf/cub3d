/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/18 10:57:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw(t_ray *r, int x, t_data *data)
{
	int y;
	(void)r;
	y = 0;
	while (y < r->drawstart)
	{
		my_mlx_pixel_put(data, x, y, data->f);
		y++;
	}
	y = r->drawstart;
//	printf("start %d end %d\n", r->drawstart, r->drawend);
	while(y < r->drawend)
	{
//		printf("in\n");
		my_mlx_pixel_put(data, x, y, RED);
		y++;
	}
	y = r->drawend;
	while (y < WIN_H - 1)
	{
		my_mlx_pixel_put(data, x, y, data->c);
		y++;
	}
}

int raycasting(t_data *data)
{
	init_map(data);
	f_and_c(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_key_hook(data->win, key_on, &data);
	mlx_loop(data->mlx);
	return (1);
}

void	distance(t_data *d)
{
	if (WIN_H >= WIN_W)
		d->ray->dist_max = WIN_H * ZOOM;
	else
		d->ray->dist_max = WIN_W * ZOOM;
	d->ray->dist = 0;
	printf("distance max : [%f]", d->ray->dist_max);
}

////////////////////////////////////////////////////////////////////
// WIP et tests d'apres video sur le DDA
// Probablement a remplacer / supprimer, une fois le raycasting OK
////////////////////////////////////////////////////////////////////

// int	raycasting(t_data *d)
// {
// 	distance(d);
// 	d->x->map_sz = WIN_W * ZOOM;
// 	d->y->map_sz = WIN_H * ZOOM;

// 	d->ray->tile_found = 0;

// 	d->x->ray_start = d->pposx;
// 	d->y->ray_start = d->pposy;
// 	d->x->map_check = d->x->ray_start;
// 	d->y->map_check = d->y->ray_start;

// 	// raydirx; // valeur ?
// 	// raydiry; // valeur ?

// 	d->x->step_sz = sqrt(1 + pow(d->y->ray_dir / d->x->ray_dir, 2));
// 	d->y->step_sz = sqrt(1 + pow(d->x->ray_dir / d->y->ray_dir, 2));

// 	if (d->x->ray_dir < 0)
// 	{
// 		d->x->step = -1;
// 		d->x->ray_len = (d->x->ray_start - d->x->map_check) * d->x->step_sz;
// 	}
// 	else
// 	{
// 		d->x->step = 1;
// 		d->x->ray_len = ((d->x->map_check + 1) - d->x->ray_start) * d->x->step_sz;
// 	}

// 	if (d->y->ray_dir < 0)
// 	{
// 		d->y->step = -1;
// 		d->y->ray_len = (d->y->ray_start - d->y->map_check) * d->y->step_sz;
// 	}
// 	else
// 	{
// 		d->y->step = 1;
// 		d->y->ray_len = ((d->y->map_check + 1) - d->y->ray_start) * d->y->step_sz;
// 	}

// 	while (!d->ray->tile_found && d->ray->dist < d->ray->dist_max)
// 	{
// 		if (d->x->ray_len < d->y->ray_len)
// 		{
// 			d->x->map_check += d->x->step;
// 			d->ray->dist = d->x->ray_len;
// 			d->x->ray_len += d->x->step_sz;
// 		}
// 		else
// 		{
// 			d->y->map_check += d->y->step;
// 			d->ray->dist = d->y->ray_len;
// 			d->y->ray_len += d->y->step_sz;
// 		}

// 		// if (d->x->map_check >= 0 && d->x->map_check < d->x->map_sz && d->y->map_check >= 0 && d->y->map_check < d->y->map_sz)
// 		// {
// 		// 	if (d->map[d->y->map_check * d->x->map_sz + d->x->map_check]) // == 1
// 		// 	{
// 		// 		d->ray->tile_found = 1;
// 		// 	}
// 		// }
// 	}

// 	// if (d->ray->tile_found)
// 	// {
// 	// 	intersection = raystart + raydir * dist;
// 	// 	//attention, il n'y a pas de x et y ici. Bien comprendre et adapter !
// 	// }
// 	return (0);
// }
