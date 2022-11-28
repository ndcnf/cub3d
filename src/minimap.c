/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 13:28:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

int	close_win(void)
{
	printf(BYE);
	exit(SUCCESS);
}

int	update_img(t_data *d)
{
	// mlx_clear_window(d->mlx, d->win);
	//floor and ceiling ici
	main_raycasting(d);
	map2d(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	return (EXIT_SUCCESS);
}

void	init_move(t_data *d, float dir)
{
	d->x->plane = 0.66;
	d->y->plane = 0;
	d->x->o_dir = d->x->dir;
	d->x->o_plane = d->x->plane;
	d->x->plane = d->x->plane * cos(dir) - d->y->plane * sin(dir);
	d->y->plane = d->x->o_plane * sin(dir) + d->y->plane * cos(dir);

	// d->x->dir = d->x->dir * cos(dir) - d->y->dir * sin(dir);
	// d->y->dir = d->x->o_dir * sin(dir) + d->y->dir * cos(dir);
	// d->x->plane = d->x->plane * cos(dir) - d->y->plane * sin(dir);
	// d->y->plane = d->x->o_plane * sin(dir) + d->y->plane * cos(dir);

	// printf("INIT x --------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
	// printf("d->x->camera ---- [%f]\n", d->x->camera);
	// printf("mapx ------------ [%d]\nmapy ------------ [%d]\n\n", d->x->map, d->y->map); // conversion OK
	// printf("xdir ------------ [%f]\nydir ------------ [%f]\n\n", d->x->dir, d->y->dir); // conversion OK
}

int	key_on(int key, t_data *d)
{
	d->x->o_dir = d->x->dir;
	d->x->o_plane = d->x->plane;
	if (key == K_ESCAPE)
		close_win();
	else if (key == K_W)
		move(d, K_W);
	else if (key == K_A)
		move(d, K_A);
	else if (key == K_AR_L)
	{
		look_around(d, K_AR_L);
		d->x->dir = d->x->dir * cos(-dtorad(ROT_ANGL)) - d->y->dir * sin(-dtorad(ROT_ANGL));
		d->y->dir = d->x->o_dir * sin(-dtorad(ROT_ANGL)) + d->y->dir * cos(-dtorad(ROT_ANGL));
		d->x->o_plane = d->x->plane;
		d->x->plane = d->x->plane * cos(-dtorad(ROT_ANGL)) - d->y->plane * sin(-dtorad(ROT_ANGL));
		d->y->plane = d->x->o_plane * sin(-dtorad(ROT_ANGL)) + d->y->plane * cos(-dtorad(ROT_ANGL));
		// d->x->dir = d->x->dir * cos(-SPEED) - d->y->dir * sin(-SPEED);
		// d->y->dir = d->x->o_dir * sin(-SPEED) + d->y->dir * cos(-SPEED);
		// d->x->o_plane = d->x->plane;
		// d->x->plane = d->x->plane * cos(-SPEED) - d->y->plane * sin(-SPEED);
		// d->y->plane = d->x->o_plane * sin(-SPEED) + d->y->plane * cos(-SPEED);
		// d->x->dir = d->x->dir * cos(dtorad(d)) - d->y->dir * sin(dtorad(d));
		// d->y->dir = d->x->o_dir * sin(dtorad(d)) + d->y->dir * cos(dtorad(d));
		// d->x->plane = d->x->plane * cos(dtorad(d)) - d->y->plane * sin(dtorad(d));
		// d->y->plane = d->x->o_plane * sin(dtorad(d)) + d->y->plane * cos(dtorad(d));
		printf("LOOK (L)x ------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
		printf("d->x->camera ---- [%f]\n", d->x->camera);
		printf("step x ---------- [%d]\n", d->x->step);
		printf("step y ---------- [%d]\n", d->y->step);
		// printf("xdir*cos -------- [%f]\n", d->x->dir * cos(-SPEED));
		// printf("ydir*sin -------- [%f]\n", d->y->dir * sin(-SPEED));
		// printf("xodir*sin ------- [%f]\n", d->x->o_dir * sin(-SPEED));
		// printf("ydir*cos -------- [%f]\n", d->y->dir * cos(-SPEED));
		printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
		printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
		printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
	}
	else if (key == K_S)
		move(d, K_S);
	else if (key == K_AR_R)
	{
		look_around(d, K_AR_R);
		d->x->dir = d->x->dir * cos(dtorad(ROT_ANGL)) - d->y->dir * sin(dtorad(ROT_ANGL));
		d->y->dir = d->x->o_dir * sin(dtorad(ROT_ANGL)) + d->y->dir * cos(dtorad(ROT_ANGL));
		d->x->o_plane = d->x->plane;
		d->x->plane = d->x->plane * cos(dtorad(ROT_ANGL)) - d->y->plane * sin(dtorad(ROT_ANGL));
		d->y->plane = d->x->o_plane * sin(dtorad(ROT_ANGL)) + d->y->plane * cos(dtorad(ROT_ANGL));

		// d->x->dir = d->x->dir * cos(-dtorad(d)) - d->y->dir * sin(-dtorad(d));
		// d->y->dir = d->x->o_dir * sin(-dtorad(d)) + d->y->dir * cos(-dtorad(d));
		// d->x->plane = d->x->plane * cos(-dtorad(d)) - d->y->plane * sin(-dtorad(d));
		// d->y->plane = d->x->o_plane * sin(-dtorad(d)) + d->y->plane * cos(-dtorad(d));
		printf("LOOK (R)x ------- [%f]\ny --------------- [%f]\nangle ----------- [%d]\n", d->pposx, d->pposy, d->angle);
		printf("d->x->camera ---- [%f]\n", d->x->camera);
		printf("step x ---------- [%d]\n", d->x->step);
		printf("step y ---------- [%d]\n", d->y->step);
		// printf("xdir*cos -------- [%f]\n", d->x->dir * cos(SPEED));
		// printf("ydir*sin -------- [%f]\n", d->y->dir * sin(SPEED));
		// printf("xodir*sin ------- [%f]\n", d->x->o_dir * sin(SPEED));
		// printf("ydir*cos -------- [%f]\n", d->y->dir * cos(SPEED));
		printf("mapx ------------ [%d]\nmapy ------------ [%d]\n", d->x->map, d->y->map);
		printf("xdir ------------ [%f]\nydir ------------ [%f]\n", d->x->dir, d->y->dir);
		printf("xplane ---------- [%f]\nyplane ---------- [%f]\n\n", d->x->plane, d->y->plane);
	}
	else if (key == K_D)
		move(d, K_D);
	return (EXIT_SUCCESS);
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

void	init_map(t_data *d)
{
	d->h = d->nb_line_map;
	d->w = (d->len_line_map - 1);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, WIN_TITLE);
	d->img = malloc(sizeof(t_img));
	d->img->img = mlx_new_image(d->mlx, WIN_W, WIN_H);
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp, \
	&d->img->line_length, &d->img->endian);
	player_angle(d);
}

void	new_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->img->addr + (y * d->img->line_length + x * (d->img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	minimap_area(t_data *d, int i, int j, int color)
{
	int	x;
	int	y;

	x = i * d->mm_size;
	while (x < ((i + 1) * d->mm_size))
	{
		y = j * d->mm_size;
		while (y < ((j + 1) * d->mm_size))
		{
			if (x % 2 && y % 2 && color == DGR)
				new_mlx_pixel_put(d, x, y, color);
			else if (color == DGR)
				new_mlx_pixel_put(d, x, y, GRN);
			else
				new_mlx_pixel_put(d, x, y, color);
			y++;
		}
		x++;
	}
}

void	on_minimap(t_data *d, int x, int y, char type)
{
	minimap_size(d);
	if (type == '0')
		minimap_area(d, x, y, WHI);
	if (type == '1')
		minimap_area(d, x, y, DGR);
}

void	define_player_head(t_data *d, int x, int y, int c_head)
{
	player_head_e(d, x, y, c_head);
	player_head_w(d, x, y, c_head);
	player_head_s(d, x, y, c_head);
	player_head_n(d, x, y, c_head);
}

void	player_angle(t_data *d)
{
	d->x->dir = 0;
	d->y->dir = 0;
	if (d->pos == 'N')
	{
		d->angle = 90;
		d->y->dir = -1;
		init_move(d, 0);
	}
	else if (d->pos == 'S')
	{
		d->angle = 270;
		d->y->dir = 1;
		init_move(d, M_PI);
	}
	else if (d->pos == 'W')
	{
		d->angle = 180;
		d->x->dir = -1;
		init_move(d, -(M_PI / 2));
	}
	else if (d->pos == 'E')
	{
		d->angle = 0;
		d->x->dir = 1;
		init_move(d, (M_PI / 2));
	}
}

void	map2d(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->w)
	{
		j = 0;
		while (j < d->h)
		{
			on_minimap(d, i, j, d->map[j][i]);
			j++;
		}
		i++;
	}
	player_is_here(d, RED, BLU);
}

void	minimap_size(t_data *d)
{
	if (d->h <= 30 || d->w <= 30)
		d->mm_size = MM_L;
	else if ((d->h > 30 && d->h <= 60) || (d->w > 30 && d->w <= 60))
		d->mm_size = MM_M;
	else
		d->mm_size = MM_S;
}
