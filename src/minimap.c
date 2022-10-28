/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/10/28 12:15:38 by nchennaf         ###   ########.fr       */
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
	tm[2] = "11N01";
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
int		minimap_area(t_data *d, int i, int j, int color)
{
	int	x;
	int	y;

	x = i * IMG_PXL;
	while (x < ((i + 1) * IMG_PXL))
	{
		y = j * IMG_PXL;
		while (y < ((j + 1) * IMG_PXL))
		{
			my_mlx_pixel_put(d, x, y, color);
			y++;
		}
		x++;
	}
	return (0);
}

void	on_minimap(t_data *d, int i, int j, char type)
{
	if (type == '0')
		minimap_area(d, i, j, WHI);
	if (type == '1')
		minimap_area(d, i, j, BLU);

	// devront etre converties en '1' a terme
	///////////////////////////////////////////
	if (type == '9')
		minimap_area(d, i, j, RED);
	///////////////////////////////////////////
}

void	map2d(t_data *d)
{
	int		i;
	int		j;

	// A remplacer apres parsing par **map
	///////////////////////////////////////////
	char	**tm;

	tm = map_test();
	d->h = 5;
	d->w = 5;
	///////////////////////////////////////////

	i = 0;
	while (i < d->h)
	{
		j = 0;
		while (j < d->w)
		{
			on_minimap(d, i, j, tm[i][j]);
			j++;
		}
		i++;
	}
}
