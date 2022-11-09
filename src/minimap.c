/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/09 11:11:47 by nchennaf         ###   ########.fr       */
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
	mlx_clear_window(d->mlx, d->win);
	map2d(d);
	mlx_put_image_to_window(d->mlx, d->win, d->m2d->img, 0, 0);
	return (EXIT_SUCCESS);
}

int	key_on(int key, t_data *d)
{
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

void	move(t_data *d, int key)
{
	printf("joueur etait ici :\nx[%f]\ny[%f]\n[%d°]\n", d->pposx, d->pposy, d->angle);
	if (key == K_W)
		go_forth(d);
	else if (key == K_S)
		go_back(d);
	else if (key == K_A)
		go_left(d);
	else if (key == K_D)
		go_right(d);
	printf("joueur est ici maintenant :\nx[%f]\ny[%f]\n[%d°]\n\n", d->pposx, d->pposy, d->angle);
}

void	init_map(t_data *d)
{
//	d->y_len = d->nb_line_map; // d->nb_line_map fix
//	d->x_len = d->len_line_map;
	d->h = d->nb_line_map;
	d->w = (d->len_line_map - 1);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, WIN_TITLE);
	d->m2d = malloc(sizeof(t_minimap));
	d->m2d->img = mlx_new_image(d->mlx, WIN_W, WIN_H);
	d->m2d->addr = mlx_get_data_addr(d->m2d->img, &d->m2d->bits_per_pixel, &d->m2d->line_length, &d->m2d->endian);
	player_angle(d);
	// d->map.x = 0;
	// d->map.y = 0;
}

void	new_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->m2d->addr + (y * d->m2d->line_length + x * (d->m2d->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	minimap_area(t_data *d, int i, int j, int color)
{
	int	x;
	int	y;

	x = i * IMG_PXL;
	while (x < ((i + 1) * IMG_PXL))
	{
		y = j * IMG_PXL;
		while (y < ((j + 1) * IMG_PXL))
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
//	printf("pos : %d\n", d->pos);
	if (d->pos == 'N')
		d->angle = 90;
	else if (d->pos == 'S')
		d->angle = 270;
	else if (d->pos == 'W')
		d->angle = 180;
	else if (d->pos == 'E')
		d->angle = 0;
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
