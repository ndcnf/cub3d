/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/10/28 16:08:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	init_map(t_data *d)
{
	/////////////
	d->y_len = 5;
	d->x_len = 5;
	/////////////

	d->h = d->y_len;
	d->w = (d->x_len - 1);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIN_W, WIN_H, WIN_TITLE);
	d->m2d = malloc(sizeof(t_minimap));
	d->m2d->img = mlx_new_image(d->mlx, WIN_W, WIN_H);
	d->m2d->addr = mlx_get_data_addr(d->m2d->img, &d->m2d->bits_per_pixel, &d->m2d->line_length, &d->m2d->endian);
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
	tm[2] = "110N1";
	tm[3] = "10011";
	tm[4] = "11111";
	tm[5] = NULL;
	return(tm);
}
////////////////////////////////////////////////////////////////////////////////

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->m2d->addr + (y * d->m2d->line_length + x * (d->m2d->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// uniquement pour test de fonctionnement, adapter ensuite car idem Eduardo & Jerome
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
				my_mlx_pixel_put(d, x, y, color);
			else if (color == DGR)
				my_mlx_pixel_put(d, x, y, GRN);
			else
				my_mlx_pixel_put(d, x, y, color);
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

void	player_is_here(t_data *d)
{
	int	x;
	int	y;

	printf("posx[%f] / posy[%f] / orient[%c]\n", d->pposx, d->pposy, d->p_orient);

	x = d->pposx * IMG_PXL + (IMG_PXL/2);
	y = d->pposy * IMG_PXL + (IMG_PXL/2);
	my_mlx_pixel_put(d, x + 1, y + 1, RED);
	my_mlx_pixel_put(d, x, y + 1, RED);
	my_mlx_pixel_put(d, x - 1, y + 1, RED);
	my_mlx_pixel_put(d, x + 1, y - 1, RED);
	my_mlx_pixel_put(d, x, y - 1, RED);
	my_mlx_pixel_put(d, x - 1, y - 1, RED);
	my_mlx_pixel_put(d, x + 1, y, RED);
	my_mlx_pixel_put(d, x, y, RED);
	my_mlx_pixel_put(d, x - 1, y, RED);
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
			// definir ailleurs la position du joueur et son orientation
			///////////////////////////////////////////////////////////////////////////////
			if (tm[y][x] == 'N' || tm[y][x] == 'W' ||tm[y][x] == 'E' ||tm[y][x] == 'S')
			{
				d->pposx = x;
				d->pposy = y;
				d->p_orient = tm[y][x];
				on_minimap(d, x, y, '0');
			}
			else
			///////////////////////////////////////////////////////////////////////////////
				on_minimap(d, x, y, tm[y][x]);
			y++;
		}
		x++;
	}
	player_is_here(d);
}
