/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:58:25 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 18:08:49 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		color_side(t_data *d, int pixel)
{
	if (d->ray->side == 0 && d->x->ray_dir < 0)
		return (d->img_we->pxs[pixel]); // WE
	else if (d->ray->side == 0 && d->x->ray_dir >= 0)
		return (d->img_ea->pxs[pixel]); // EA
	else if (d->ray->side == 1 && d->y->ray_dir < 0)
		return (d->img_no->pxs[pixel]); // NO
	else
		return (d->img_so->pxs[pixel]); //SO
}

void init_asset(t_data *d)
{
	load_img(d, d->img_no, d->no);
	load_img(d, d->img_we, d->we);
	load_img(d, d->img_so, d->so);
	load_img(d, d->img_ea, d->ea);
}

int rendering(t_data *d)
{
	d->ray->texwidth = d->img_no->w;
	d->ray->texheight =d->img_no->h;
	if (d->ray->side == 0)
		d->ray->wall = d->pposy + (d->ray->perpwalldist * d->y->ray_dir);
	else
		d->ray->wall = d->pposx + (d->ray->perpwalldist * d->x->ray_dir);
	d->ray->wall -= floor(d->ray->wall);
	d->x->tex = (int)(d->ray->wall * (double)d->ray->texwidth);
	if (d->ray->side == 0 && d->x->ray_dir <= 0)
		d->x->tex = d->ray->texwidth - d->x->tex - 1;
	if (d->ray->side == 1 && d->y->ray_dir >= 0)
		d->x->tex = d->ray->texwidth - d->x->tex - 1;
	return (SUCCESS);
}

int paint_tex(t_data *d, int x, int start)
{
	int pixel;
	int color;
	
	rendering(d);
	d->ray->step = 1.0 * d->ray->texheight / d->ray->lineheight;
	d->ray->tex_pos = (d->ray->drawstart - ((WIN_H * ZOOM) / 2) + d->ray->lineheight / 2) * d->ray->step;
	while (start < d->ray->drawend)
	{
		d->y->tex = (int)d->ray->tex_pos & (d->ray->texheight - 1);
		d->ray->tex_pos += d->ray->step;
		pixel = d->ray->texheight * d->y->tex + d->x->tex;
		color = color_side(d, pixel);
		new_mlx_pixel_put(d, x, start, color);
		start++;
	}
	return (SUCCESS);
}