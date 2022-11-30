/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:59:39 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/29 14:31:19 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

float	dtorad(int deg)
{
	return (M_PI * (float)deg / 180);
}

void	player_angle(t_data *d)
{
	d->x->dir = 0;
	d->y->dir = 0;
	if (d->pos == 'N')
		init_move(d, 0, 90, -1);
	else if (d->pos == 'S')
		init_move(d, M_PI, 270, 1);
	else if (d->pos == 'W')
	{
		d->x->dir = -1;
		init_move(d, -(M_PI / 2), 180, 0);
	}
	else if (d->pos == 'E')
	{
		d->x->dir = 1;
		init_move(d, (M_PI / 2), 0, 0);
	}
}
