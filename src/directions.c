/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:30:21 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/25 15:33:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	look_around(t_data *d, int key)
{
	if ((d->angle + ROT_ANGL) == 360 && key == K_AR_L)
	{
		d->angle = 0;
		// d->y->dir = sin((M_PI * d->angle) / 180);
	}
	else if (d->angle == 0 && key == K_AR_R)
	{
		d->angle = 360 - ROT_ANGL;
		// d->y->dir = sin((M_PI * d->angle) / 180);
	}
	else if ((d->angle + ROT_ANGL) < 0)
	{
		d->angle = 360 - ROT_ANGL;
		// d->y->dir = sin((M_PI * d->angle) / 180);
	}
	else if (key == K_AR_L)
	{
		d->angle += ROT_ANGL;
		// d->x->dir = cos((M_PI * d->angle) / 180); // OK pour 0 - 180, KO 180+ -> 360
	}
	else if (key == K_AR_R)
	{
		d->angle -= ROT_ANGL;
		// d->x->dir = cos((M_PI * d->angle) / 180); // OK pour 0 - 180, KO 180+ -> 360
	}
	// d->y->dir = cos((M_PI * d->angle) / 180);

	// d->x->dir = d->x->dir * cos(dtorad(d)) - d->y->dir * sin(dtorad(d));
	// d->y->dir = d->x->o_dir * sin(dtorad(d)) + d->y->dir * cos(dtorad(d));
	// d->x->plane = d->x->plane * cos(dtorad(d)) - d->y->plane * sin(dtorad(d));
	// d->y->plane = d->x->o_plane * sin(dtorad(d)) + d->y->plane * cos(dtorad(d));
	// d->x->dir = d->x->dir * cos(SPEED) - d->y->dir * sin(SPEED);
	// d->y->dir = d->x->o_dir * sin(SPEED) + d->y->dir * cos(SPEED);
	// d->x->plane = d->x->plane * cos(SPEED) - d->y->plane * sin(SPEED);
	// d->y->plane = d->x->o_plane * sin(SPEED) + d->y->plane * cos(SPEED);
}

void	go_forth(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	d->pposx += d->x->dir * SPEED;
	// d->pposx = d->pposx + SPEED * cos(dtorad(d));
	// d->pposx = d->pposx + SPEED * cos((M_PI * d->angle) / 180);
	d->pposy += d->y->dir * SPEED;
	// d->pposy = d->pposy - SPEED * sin(dtorad(d));
	// d->y->dir = sin((M_PI * d->angle) / 180);
	// d->y->dir = sin((M_PI * d->angle) / 180);
	// d->pposy = d->pposy - SPEED * sin((M_PI * d->angle) / 180);
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}


	printf("FORTH x --------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
	printf("d->x->camera ---- [%f]\n", d->x->camera);
	printf("step x ---------- [%d]\n", d->x->step);
	printf("step y ---------- [%d]\n", d->y->step);
	printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
	printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
	printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
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

	// d->pposx = d->pposx - SPEED * cos((M_PI * d->angle) / 180);
	// d->pposy = d->pposy + SPEED * sin((M_PI * d->angle) / 180);


	printf("BACK x ---------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
	printf("d->x->camera ---- [%f]\n", d->x->camera);
	printf("step x ---------- [%d]\n", d->x->step);
	printf("step y ---------- [%d]\n", d->y->step);
	printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
	printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
	printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
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
	// d->pposx = d->pposx - SPEED * sin((M_PI * d->angle) / 180);
	// d->pposy = d->pposy - SPEED * cos((M_PI * d->angle) / 180);

	// d->x->dir = d->x->dir * cos(SPEED) - d->y->dir * sin(SPEED);
	// d->y->dir = d->x->o_dir * sin(SPEED) + d->y->dir * cos(SPEED);
	// d->x->plane = d->x->plane * cos(SPEED) - d->y->plane * sin(SPEED);
	// d->y->plane = d->x->o_plane * sin(SPEED) + d->y->plane * cos(SPEED);

	printf("LEFT x ---------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
	printf("d->x->camera ---- [%f]\n", d->x->camera);
	printf("step x ---------- [%d]\n", d->x->step);
	printf("step y ---------- [%d]\n", d->y->step);
	printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
	printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
	printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
}

void	go_right(t_data *d)
{
	float	oldx;
	float	oldy;

	oldx = d->pposx;
	oldy = d->pposy;
	// d->x->o_dir = d->x->dir;
	// d->x->o_plane = d->x->plane;

	d->pposx -= d->y->dir * SPEED;
	d->pposy += d->x->dir * SPEED;
	if (d->map[(int)d->pposy][(int)d->pposx] == '1')
	{
		d->pposx = oldx;
		d->pposy = oldy;
	}
	// d->pposx = d->pposx + SPEED * sin((M_PI * d->angle) / 180);
	// d->pposy = d->pposy + SPEED * cos((M_PI * d->angle) / 180);

	// d->x->dir = d->x->dir * cos(SPEED) - d->y->dir * sin(SPEED);
	// d->y->dir = d->x->o_dir * sin(SPEED) + d->y->dir * cos(SPEED);
	// d->x->plane = d->x->plane * cos(SPEED) - d->y->plane * sin(SPEED);
	// d->y->plane = d->x->o_plane * sin(SPEED) + d->y->plane * cos(SPEED);

	// d->x->dir = d->x->dir * cos(SPEED) - d->y->dir * sin(SPEED);
	// d->y->dir = d->x->o_dir * sin(SPEED) + d->y->dir * cos(SPEED);
	// d->x->plane = d->x->plane * cos(SPEED) - d->y->plane * sin(SPEED);
	// d->y->plane = d->x->o_plane * sin(SPEED) + d->y->plane * cos(SPEED);

	printf("RIGHT x --------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
	printf("d->x->camera ---- [%f]\n", d->x->camera);
	printf("step x ---------- [%d]\n", d->x->step);
	printf("step y ---------- [%d]\n", d->y->step);
	printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
	printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
	printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
}
