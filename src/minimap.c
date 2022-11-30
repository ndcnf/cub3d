/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 18:03:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

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
		look_around(d, K_AR_L);
	else if (key == K_S)
		move(d, K_S);
	else if (key == K_AR_R)
		look_around(d, K_AR_R);
	else if (key == K_D)
		move(d, K_D);
	return (EXIT_SUCCESS);
}

void	init_map(t_data *d)
{
	d->h = d->nb_line_map;
	d->w = (d->len_line_map - 1);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, (WIN_W * ZOOM), (WIN_H * ZOOM), WIN_TITLE);
	d->img->img = mlx_new_image(d->mlx, (WIN_W * ZOOM), (WIN_H * ZOOM));
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bpp, \
	&d->img->line_length, &d->img->endian);
	player_angle(d);
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
