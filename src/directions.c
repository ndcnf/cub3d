/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:30:21 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 17:02:46 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	look_around(t_data *d, int key)
{
	int	pol;

	if ((d->angle + ROT_ANGL) == 360 && key == K_AR_L)
		d->angle = 0;
	else if (d->angle == 0 && key == K_AR_R)
		d->angle = 360 - ROT_ANGL;
	else if ((d->angle + ROT_ANGL) < 0)
		d->angle = 360 - ROT_ANGL;
	else if (key == K_AR_L)
		d->angle += ROT_ANGL;
	else if (key == K_AR_R)
		d->angle -= ROT_ANGL;
	if (key == K_AR_L)
		pol = -1;
	else
		pol = 1;
	d->x->dir = d->x->dir * cos(pol * dtorad(ROT_ANGL)) - \
				d->y->dir * sin(pol * dtorad(ROT_ANGL));
	d->y->dir = d->x->o_dir * sin(pol * dtorad(ROT_ANGL)) + \
				d->y->dir * cos(pol * dtorad(ROT_ANGL));
	d->x->o_plane = d->x->plane;
	d->x->plane = d->x->plane * cos(pol * dtorad(ROT_ANGL)) - \
				d->y->plane * sin(pol * dtorad(ROT_ANGL));
	d->y->plane = d->x->o_plane * sin(pol * dtorad(ROT_ANGL)) + \
				d->y->plane * cos(pol * dtorad(ROT_ANGL));
}

void	go_forth(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	d->pposx += d->x->dir * SPEED;
	d->pposy += d->y->dir * SPEED;
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}
}

void	go_back(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	d->pposx -= d->x->dir * SPEED;
	d->pposy -= d->y->dir * SPEED;
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}
}

void	go_left(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	d->x->o_dir = d->x->dir;
	d->x->o_plane = d->x->plane;
	d->pposx += d->y->dir * SPEED;
	d->pposy -= d->x->dir * SPEED;
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}
}

void	go_right(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	d->pposx -= d->y->dir * SPEED;
	d->pposy += d->x->dir * SPEED;
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}
}
