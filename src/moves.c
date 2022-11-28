/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:26:57 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 17:30:53 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_move(t_data *d, float dir, int deg, int rad)
{
	d->angle = deg;
	d->y->dir = rad;
	d->x->plane = 0.66;
	d->y->plane = 0;
	d->x->o_dir = d->x->dir;
	d->x->o_plane = d->x->plane;
	d->x->plane = d->x->plane * cos(dir) - d->y->plane * sin(dir);
	d->y->plane = d->x->o_plane * sin(dir) + d->y->plane * cos(dir);
}

void	move(t_data *d, int key)
{
	if (key == K_W)
		go_forth(d);
	else if (key == K_S)
		go_back(d);
	else if (key == K_A)
		go_left(d);
	else if (key == K_D)
		go_right(d);
}
