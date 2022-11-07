/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/07 10:58:12 by nchennaf         ###   ########.fr       */
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
	{
		printf("UP\n");
		move(d, K_W);
	}
	else if (key == K_A)
	{
		printf("LEFT\n");
		// move(d, KEY_LFT);
	}
	else if (key == K_AR_L)
	{
		printf("CAMERA GAUCHE\n");
		look_around(d, K_AR_L);
		// player_is_here(d);
		// move(d, KEY_LFT);
	}
	else if (key == K_S)
	{
		printf("DOWN\n");
		// move(d, KEY_DWN);
	}
	else if (key == K_AR_R)
	{
		printf("CAMERA DROITE\n");
		look_around(d, K_AR_R);
		// player_is_here(d);
		// move(d, KEY_LFT);
	}
	else if (key == K_D)
	{
		printf("RIGHT\n");
		// move(d, KEY_RGT);
	}
	printf("angle [%d°]\n\n", d->angle);
	return (EXIT_SUCCESS);
}

void	move(t_data *d, int key)
{
	// pathfinder(bd, IMG_GRD2, bd->p1->x, bd->p1->y);
	printf("joueur etait ici : x[%f]\ny[%f]\n[%d°]\n", d->pposx, d->pposy, d->angle);
	//player_is_here(d, WHI, WHI); //inutile si la map se detruit chaque fois ?
	if (key == K_W)
	{
		go_forth(d);
		printf("joueur est ici maintenant : x[%f]\ny[%f]\n[%d°]\n", d->pposx, d->pposy, d->angle);
	}
	// else if (key == K_S)
	// 	go_down(d);
	// else if (key == K_A)
	// 	go_left(d);
	// else if (key == K_D)
	// 	go_right(d);

}

void	go_forth(t_data *d)
{
	// int	future_x;
	// int	future_y;

	// future_y = d->pposy - IMG_PXL;
	// future_x = d->pposx;
	// if (check_move(bd, future_x, future_y))
	// {
	if (d->angle >= 135 && d->angle < 225)
	{
		d->pposx = d->pposx - PXL;
	}
	else if (d->angle >= 45 && d->angle < 135)
	{
		d->pposy = d->pposy - PXL;

	}
	else if (d->angle >= 225 && d->angle < 315)
	{
		d->pposy = d->pposy + PXL;
	}
	else
	{
		d->pposx = d->pposx + PXL;
	}
	// d->pposy = d->pposy - IMG_PXL;
		// d->pposy = bd->map.y;
	// }
	// pathfinder(bd, IMG_P2, d->pposx, d->pposy);
	//player_is_here(d, RED, BLU); //inutile si la map se detruit chaque fois ?
}

void	look_around(t_data *d, int key)
{
	// printf("AVANT [%d] - ", d->angle); Pour verifier les angles uniquement
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

void	init_map(t_data *d)
{
	/////////////
	d->nb_line_map = 5;
	d->len_line_map = 5;
	/////////////

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

////////////////////////////////////////////////////////////////////////////////
// UNIQUEMENT POUR TESTS. SUPPRIMER ENSUITE
////////////////////////////////////////////////////////////////////////////////
char	**map_test(void)
{
	char **tm;
	int		i = 0;

	tm = malloc(sizeof(char *) * 6);
	while (i < 5)
	{
		tm[i] = malloc(sizeof(char) * 6);
		i++;
	}
	tm[0] = "11111";
	tm[1] = "10001";
	tm[2] = "11001";
	tm[3] = "10011";
	tm[4] = "11111";
	tm[5] = NULL;
	return(tm);
}
////////////////////////////////////////////////////////////////////////////////

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

	// devront etre converties en '1' a terme
	///////////////////////////////////////////
	if (type == '9')
		minimap_area(d, x, y, RED);
	///////////////////////////////////////////
}

void	player_is_here(t_data *d, int c_body, int c_head)
{
	int	x;
	int	y;

	x = d->pposx * IMG_PXL + (IMG_PXL/2);
	y = d->pposy * IMG_PXL + (IMG_PXL/2);
	new_mlx_pixel_put(d, x + 1, y + 1, c_body);
	new_mlx_pixel_put(d, x, y + 1, c_body);
	new_mlx_pixel_put(d, x - 1, y + 1, c_body);
	new_mlx_pixel_put(d, x + 1, y - 1, c_body);
	new_mlx_pixel_put(d, x, y - 1, c_body);
	new_mlx_pixel_put(d, x - 1, y - 1, c_body);
	new_mlx_pixel_put(d, x + 1, y, c_body);
	new_mlx_pixel_put(d, x, y, c_body);
	new_mlx_pixel_put(d, x - 1, y, c_body);
	define_player_head(d, x, y, c_head);
}

void	define_player_head(t_data *d, int x, int y, int c_head)
{
	if ((d->angle >= 0 && d->angle < 22)) // Est
		new_mlx_pixel_put(d, x + 2, y, c_head);
	else if (d->angle >= 22 && d->angle < 45)
		new_mlx_pixel_put(d, x + 2, y - 1, c_head);
	else if (d->angle >= 45 && d->angle < 67)
		new_mlx_pixel_put(d, x + 2, y - 2, c_head);
	else if (d->angle >= 67 && d->angle < 90)
		new_mlx_pixel_put(d, x + 1, y - 2, c_head);
	else if (d->angle >= 90 && d->angle < 112) // Nord
		new_mlx_pixel_put(d, x, y - 2, c_head);
	else if (d->angle >= 112 && d->angle < 135)
		new_mlx_pixel_put(d, x - 1, y - 2, c_head);
	else if (d->angle >= 135 && d->angle < 157)
		new_mlx_pixel_put(d, x - 2, y - 2, c_head);
	else if (d->angle >= 157 && d->angle < 180)
		new_mlx_pixel_put(d, x - 2, y - 1, c_head);
	else if (d->angle >= 180 && d->angle < 202) // Ouest
		new_mlx_pixel_put(d, x - 2, y, c_head);
	else if (d->angle >= 202 && d->angle < 225)
		new_mlx_pixel_put(d, x - 2, y + 1, c_head);
	else if (d->angle >= 225 && d->angle < 247)
		new_mlx_pixel_put(d, x - 2, y + 2, c_head);
	else if (d->angle >= 247 && d->angle < 270)
		new_mlx_pixel_put(d, x - 1, y + 2, c_head);
	else if (d->angle >= 270 && d->angle < 292) // Sud
		new_mlx_pixel_put(d, x, y + 2, c_head);
	else if (d->angle >= 292 && d->angle < 315)
		new_mlx_pixel_put(d, x + 1, y + 2, c_head);
	else if (d->angle >= 315 && d->angle < 337)
		new_mlx_pixel_put(d, x + 2, y + 2, c_head);
	else if (d->angle >= 337 && d->angle <= 360)
		new_mlx_pixel_put(d, x + 2, y + 1, c_head);
}

void	player_angle(t_data *d)
{
	printf("pos : %d\n", d->pos);
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
	int		x;
	int		y;

	// A remplacer apres parsing par **map
	///////////////////////////////////////////
	char	**tm;

	tm = map_test();
	d->h = 5;
	d->w = 5;
	///////////////////////////////////////////

	x = 0;
	while (x < d->h)
	{
		y = 0;
		while (y < d->w)
		{
			on_minimap(d, x, y, tm[y][x]);
			y++;
		}
		x++;
	}
	player_is_here(d, RED, BLU);
}
