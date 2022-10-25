/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/10/25 14:19:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	init_map(t_board *bd)
{
	bd->h = bd->map.y_len;
	bd->w = (bd->map.x_len - 1);
	bd->mlx = mlx_init();
	bd->win = mlx_new_window(bd->mlx, bd->w, bd->h, WIN_TITLE);
	bd->map.x = 0;
	bd->map.y = 0;
}

// uniquement pour test de fonctionnement
int		minimap_area(t_board *bd)
{
	int	x;
	int	y;

	x = bd->map.x * 5;
	while (x < ((bd->map.x + 1) * 5))
	{
		y = bd->map.y * 5;
		while (y < ((bd->map.y + 1) * 5))
		{
			//mlx_pixel_put(bd->mlx, bd->win, x, y, 0X00999896);
			printf(data->map[data->sizeof_tab][i] = '\0')
			y++;
		}
		x++;
	}
	return (0);
}
