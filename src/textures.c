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

int		color_side(t_data *d, int pix)
{
	if (d->ray->side == 0 && d->x->ray_dir < 0)
		return (d->img_we->pxs[pix]); // WE
	else if (d->ray->side == 0 && d->x->ray_dir >= 0)
		return (d->img_ea->pxs[pix]); // EA
	else if (d->ray->side == 1 && d->y->ray_dir < 0)
		return (d->img_no->pxs[pix]); // NO
	else
		return (d->img_so->pxs[pix]); //SO
}

void init_asset(t_data *d)
{
	load_img(d, d->img_no, d->no);
	load_img(d, d->img_we, d->we);
	load_img(d, d->img_so, d->so);
	load_img(d, d->img_ea, d->ea);
}

//int rendering(t_data *d)
//{
//	d->ray->texwidth = d->img_no->w;
//	d->ray->texheight =d->img_no->h;
//	if (d->ray->side == 0)
//		d->ray->wall = d->pposy + (d->ray->perpwalldist * d->y->ray_dir);
//	else
//
//}

int tex_pix(t_data *d, int pix)
{
	(void)d;
	return(pix);
}