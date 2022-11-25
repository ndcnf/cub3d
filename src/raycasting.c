/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/25 11:05:07 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


////////////////////////////////////////////////////////////////////////////////
// Fonction rendue caduque car l''orientation en radian est donnee avant
////////////////////////////////////////////////////////////////////////////////
// void	start_orientation(t_data *d, double rad)
void	start_orientation(t_data *d)
{
	// double	o_dir_x;
	// double	o_plane_x;

	// o_dir_x = d->x->dir;
	// o_plane_x = d->x->plane;

	d->x->o_plane = d->x->plane;
	d->x->o_dir = d->x->dir;
	// // d->x->dir = d->x->dir * cos(rad) - d->y->dir * sin(rad);
	// // d->y->dir = o_dir_x * sin(rad) + d->y->dir * cos(rad);
	// d->x->plane = d->x->plane * cos(rad) - d->y->plane * sin(rad);
	// d->y->plane = o_plane_x * sin(rad) + d->y->plane * cos(rad);

	// d->x->dir = d->x->dir * sin(dtorad(d)) - d->y->dir * cos(dtorad(d));
	// d->y->dir = d->x->o_dir * cos(dtorad(d)) + d->y->dir * sin(dtorad(d));
	// d->x->dir = d->x->dir * cos(dtorad(d)) - d->y->dir * sin(dtorad(d));
	// d->y->dir = d->x->o_dir * sin(dtorad(d)) + d->y->dir * cos(dtorad(d));
	// d->x->plane = d->x->plane * cos(dtorad(d)) - d->y->plane * sin(dtorad(d));
	// d->y->plane = d->x->o_plane * sin(dtorad(d)) + d->y->plane * cos(dtorad(d));
}
//todo
/*
* How to calculated a new dirX and new dirY by pressing down a cap ➡️ or ⬅️
*/
/*
int keymove(t_data *d, int key)
{
	double o_dir_x;
	double o_plane_x;

   if (key == K_AR_L)
   {
	   o_dir_x = d->x->dir;
	   d->x->dir = d->x->dir * cos(-PI) - d->y->dir * sin(-PI);
	   d->y->dir = o_dir_x * sin(-PI) + d->y->dir * cos(-PI);
	   o_plane_x = d->x->plane;
	   d->x->plane = d->x->plane * cos(-PI) - d->y->plane * sin(-PI);
	   d->y->plane = o_plane_x * sin(-PI) + d->y->plane * cos(-PI);
   }
   if (key == K_AR_R)
   {
	   o_dir_x = d->x->dir;
	   d->x->dir = d->x->dir * cos(PI) - d->y->dir * sin(PI);
	   d->y->dir = o_dir_x * sin(PI) + d->y->dir * cos(PI);
	   o_plane_x = d->x->plane;
	   d->x->plane = d->x->plane * cos(PI) - d->y->plane * sin(PI);
	   d->y->plane = o_plane_x * sin(PI) + d->y->plane * cos(PI);
   }
   return (0);
}
*/

/*
 * If you like you can try to add strafe keys (to strafe to the left and right).
 * These have to be made the same way as the up and down keys, but use planeX and planeY instead of dirX and dirY.
 *
 *  //move forward if no wall in front of you
    if (keyDown(SDLK_UP === W === ))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false)
      	posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false)
      	posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN === S ===️))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
      	posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
      	posY -= dirY * moveSpeed;
    }

     //strafe left
    if (keyDown(SDLK_LEFT === A ===))
    {
      if(worldMap[int(posX + planeX * moveSpeed)][int(posY)] == false)
      	posX += planeX * moveSpeed;
      if(worldMap[int(posX)][int(posY + planeY * moveSpeed)] == false)
      	posY += planeY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_RIGHT === D ===))
    {
      if(worldMap[int(posX - planeX * moveSpeed)][int(posY)] == false)
      	posX -= planeX * moveSpeed;
      if(worldMap[int(posX)][int(posY - planeY * moveSpeed)] == false)
      	posY -= planeY * moveSpeed;
    }
 */

/*
 * How to set up the first dir_x and dir_y
 * we set d
 *
void	init_player_dir(t_data *d)
{
	d->x->dir = 0;
	d->y->dir = -1;

	if (d->pos == 'N')
		move_start(d, 0);
	if (d->pos == 'S')
		move_start(d, (M_PI));
	if (d->pos == 'W')
		move_start(d, -(M_PI / 2));
	if (d->pos == 'E')
		move_start(d, (M_PI / 2));
}
 */


void	raydir_n_delta(t_data *d, int x)
{
	//calculate ray position and direction
	d->x->camera = 2 * x / (float)WIN_H - 1;
	// d->x->camera = 2 * x / (double)WIN_W - 1;
	/*
	 * cameraX is the x-coordinate on the camera plane that the current
	 * x-coordinate of the screen represents, done this way so that the right side
	 * of the screen will get coordinate 1, the center of the screen gets
	 * coordinate 0, and the left side of the screen gets coordinate -1.
	 */

	d->x->ray_dir = d->x->dir + d->x->plane * d->x->camera;
	d->y->ray_dir = d->y->dir + d->y->plane * d->x->camera;
	/*
	 * the direction of the ray can be calculated as the sum
	 * of the direction vector, and a part of the plane vector. This has to be done both
	 * for the x and y coordinate of the vector (since adding two vectors is adding
	 * their x-coordinates, and adding their y-coordinates).
	 * Reminder :
	 * dirX and dirY represent the direction of the player
	 * first calculated by:
	 * @fn start_orientation(t_data *d, float rad)
	 *
	 * planeX and planeY the camera plane of the player, "the screen of the fpv", set at 0 and 0.66
	 * at first, then, it will be recalculated during process of @fn ray_dir, but it will keep the same ratio.
	 */

	if (d->x->ray_dir == 0)
		d->x->deltadist = INFINITY;
		/*
		 * if raydir_x is 0, it's the exact middle of the 90* angle
		 * otherwise, it's either an angle going on the left side (-) or the right side (+)
		 * in @fn step_n_sidedist
		 */
	else
		d->x->deltadist = fabs(1 / d->x->ray_dir);
	/*
	 * we should remind here that deltadist_x and deltadist_y are the distance the ray has to travel to go
	 * from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
	 * x-side and y-side are the line of our map, each time the ray cross one of those side, it's set on
	 * the next square of our map.
	 * fabs(1 / d->x->ray_dir) also could be written : deltadistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
	 * calculated with Pythagoras theorem: how long is the hypotenuse of the triangle formed
	 * by the ray crossing a square of the map.
	 */

	if (d->y->ray_dir == 0)
		d->y->deltadist = INFINITY;
	else
		d->y->deltadist = fabs(1 / d->y->ray_dir);
}

void	step_n_sidedist(t_data *d)
{
	//calculate step and initial sideDist
	d->ray->hit = 0;
	//	printf("sidedist_y %f when raydir_y - %f\n", d->y->sidedist, d->y->ray_dir);

	/*
	 * Reminder: the right side of the screen will get coordinate 1, the center of the screen gets
	 * coordinate 0, and the left side of the screen gets coordinate -1
	 */
	if (d->x->ray_dir < 0)
	{
		d->x->step = -1;
		d->x->sidedist = (d->pposx - d->x->map) * d->x->deltadist; // idem lodev
		// d->x->sidedist = (d->pposx - (float)d->x->map) * d->x->deltadist; // origine
//		printf("sidedist_x %f when raydir_x - %f\n", d->x->sidedist, d->x->ray_dir);
	}
	else
	{
		d->x->step = 1;
		d->x->sidedist = (d->x->map + 1.0 - d->pposx) * d->x->deltadist;
//		printf("sidedist_x %f when raydir_x + %f\n", d->x->sidedist, d->x->ray_dir);
	}
	if (d->y->ray_dir < 0)
	{
		d->y->step = -1;
		d->y->sidedist = (d->pposy - d->y->map) * d->y->deltadist; // idem lodev
		// d->y->sidedist = (d->pposy - (float)d->y->map) * d->y->deltadist; // origine
//		printf("sidedist_y %f when raydir_y - %f\n", d->y->sidedist, d->y->ray_dir);
	}
	else
	{
		d->y->step = 1;
		d->y->sidedist = (d->y->map + 1.0 - d->pposy) * d->y->deltadist;
//		printf("sidedist_y %f when raydir_y - %f\n", d->y->sidedist, d->y->ray_dir);
	}
}

void	hit(t_data *d)
/*
 * 	The DDA algorithm will always jump exactly one square each loop, either a square in the x-direction,
 * 	or a square in the y-direction. If it has to go in the negative or positive x-direction, and the negative
 * 	or positive y-direction will depend on the direction of the ray, and this fact will be stored
 * 	in stepX and stepY. Those variables are always either -1 or +1.
 */
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

//todo
void	side(t_data *d)
{
	//Calculate radance projected on camera direction. This is the shortest radance from the point where the wall is
	//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
	//This can be computed as (mapX - posX + (1 - stepX) / 2) / raydir_x for side == 0, or same formula with Y
	//for size == 1, but can be simplified to the code below thanks to how siderad and deltarad are computed:
	//because they were left scaled to |rayDir|. siderad is the entire length of the ray above after the multiple
	//steps, but we subtract deltarad once because one step more into the wall was taken above.

	// variable perpWallDist will be used later to calculate the length of the ray.
	if (d->ray->side == 0)
		d->ray->perpwalldist = (d->x->sidedist - d->x->deltadist);
	else
		d->ray->perpwalldist = (d->y->sidedist - d->y->deltadist);
}

//todo
void	draw_set(t_data *d)
{
	//Calculate height of line to draw on screen
	d->ray->lineheight = (int)(WIN_H / d->ray->perpwalldist);
	// d->ray->lineheight = (int)(WIN_W / d->ray->perpwalldist);
	//calculate lowest and highest pixel to fill in current stripe
	d->ray->drawstart = -(d->ray->lineheight) / 2 + (WIN_H / 2);
	// d->ray->drawstart = -(d->ray->lineheight) / 2 + WIN_W / 2;

	if (d->ray->drawstart < 0)
		d->ray->drawstart = 0;
	d->ray->drawend = d->ray->lineheight / 2 + WIN_H / 2;
	// d->ray->drawend = d->ray->lineheight / 2 + WIN_W / 2;
	if (d->ray->drawend >= WIN_H /*|| r->drawend >= 0*/)
		d->ray->drawend = WIN_H - 1;
	// if (d->ray->drawend <= WIN_W /*|| r->drawend >= 0*/)
	// 	d->ray->drawend = WIN_W - 1;
}

int		color_side(t_data *d)
{
	if (d->ray->side == 0 && d->x->ray_dir < 0)
		return (LGN);
	else if (d->ray->side == 0 && d->x->ray_dir >= 0)
		return (PNK);
	else if (d->ray->side == 1 && d->y->ray_dir < 0)
		return (RED);
	else
		return (BLU);
}

void	draw(t_data *d, int x)
{
	int y;

	y = 0;
	while (y <= d->ray->drawstart)
	{
		new_mlx_pixel_put(d, x, y, d->c);
		y++;
	}
	y = d->ray->drawstart;
	while(y <= d->ray->drawend && y < WIN_H)
	{
		new_mlx_pixel_put(d, x, y, color_side(d));
		y++;
	}
	y = d->ray->drawend;
	while (y < WIN_H)
	{
		new_mlx_pixel_put(d, x, y, d->f);
		y++;
	}
}

int main_raycasting(t_data *d)
{
	int 	x;
	// double 	set;

	// set = d->angle * (M_PI / 180);
	x = 0;
	// d->x->camera = 2 * x / WIN_H - 1; // pas de double, sinon angle n'est pas correct
	while (x <  WIN_W)
	{
		d->x->map = (int)d->pposx;
		d->y->map = (int)d->pposy;
		/*
	 	* which box of the map we're in.
	 	* Reminder : mx and my are the int for our map[my][mx]
	 	* each time step_x or step_y will be incremented,
	 	* map_x and map_x will be updated to check if the square is a wall
	 	*/
		// start_orientation(d, set);
		// start_orientation(d);
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

////////////////////////////////////////////////////////////////////

// WIP et tests d'apres video sur le DDA
// Probablement a remplacer / supprimer, une fois le raycasting OK
////////////////////////////////////////////////////////////////////

//void	distance(t_data *d)
//{
//	if (WIN_H >= WIN_W)
//		d->ray->dist_max = WIN_H * ZOOM;
//	else
//		d->ray->dist_max = WIN_W * ZOOM;
//	d->ray->dist = 0;
//	printf("distance max : [%f]", d->ray->dist_max);
//}

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
