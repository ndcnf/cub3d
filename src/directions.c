/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:30:21 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/08 14:42:09 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	look_around(t_data *d, int key)
{
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
}

void	go_forth(t_data *d)
{
	d->pposx = d->pposx + PXL * cos((M_PI * d->angle) / 180);
	d->pposy = d->pposy - PXL * sin((M_PI * d->angle) / 180);
}

void	go_back(t_data *d)
{
	d->pposx = d->pposx - PXL * cos((M_PI * d->angle) / 180);
	d->pposy = d->pposy + PXL * sin((M_PI * d->angle) / 180);
}

void	go_left(t_data *d)
{
	d->pposx = d->pposx - PXL * sin((M_PI * d->angle) / 180);
	d->pposy = d->pposy - PXL * cos((M_PI * d->angle) / 180);
}

void	go_right(t_data *d)
{
	d->pposx = d->pposx + PXL * sin((M_PI * d->angle) / 180);
	d->pposy = d->pposy + PXL * cos((M_PI * d->angle) / 180);
}
