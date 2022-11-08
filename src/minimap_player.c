/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:34:27 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/08 11:39:44 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	player_is_here(t_data *d, int c_body, int c_head)
{
	int	x;
	int	y;

	y = d->pposx * IMG_PXL + (IMG_PXL/2);
	x = d->pposy * IMG_PXL + (IMG_PXL/2);
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

void	player_head_e(t_data *d, int x, int y, int c_head)
{
	if ((d->angle >= 0 && d->angle < 22)) // Est
		new_mlx_pixel_put(d, x + 2, y, c_head);
	else if (d->angle >= 22 && d->angle < 45)
		new_mlx_pixel_put(d, x + 2, y - 1, c_head);
	else if (d->angle >= 45 && d->angle < 67)
		new_mlx_pixel_put(d, x + 2, y - 2, c_head);
	else if (d->angle >= 67 && d->angle < 90)
		new_mlx_pixel_put(d, x + 1, y - 2, c_head);
}

void	player_head_n(t_data *d, int x, int y, int c_head)
{
	if (d->angle >= 90 && d->angle < 112) // Nord
		new_mlx_pixel_put(d, x, y - 2, c_head);
	else if (d->angle >= 112 && d->angle < 135)
		new_mlx_pixel_put(d, x - 1, y - 2, c_head);
	else if (d->angle >= 135 && d->angle < 157)
		new_mlx_pixel_put(d, x - 2, y - 2, c_head);
	else if (d->angle >= 157 && d->angle < 180)
		new_mlx_pixel_put(d, x - 2, y - 1, c_head);
}

void	player_head_w(t_data *d, int x, int y, int c_head)
{
	if (d->angle >= 180 && d->angle < 202) // Ouest
		new_mlx_pixel_put(d, x - 2, y, c_head);
	else if (d->angle >= 202 && d->angle < 225)
		new_mlx_pixel_put(d, x - 2, y + 1, c_head);
	else if (d->angle >= 225 && d->angle < 247)
		new_mlx_pixel_put(d, x - 2, y + 2, c_head);
	else if (d->angle >= 247 && d->angle < 270)
		new_mlx_pixel_put(d, x - 1, y + 2, c_head);
}

void	player_head_s(t_data *d, int x, int y, int c_head)
{
	if (d->angle >= 270 && d->angle < 292) // Sud
		new_mlx_pixel_put(d, x, y + 2, c_head);
	else if (d->angle >= 292 && d->angle < 315)
		new_mlx_pixel_put(d, x + 1, y + 2, c_head);
	else if (d->angle >= 315 && d->angle < 337)
		new_mlx_pixel_put(d, x + 2, y + 2, c_head);
	else if (d->angle >= 337 && d->angle <= 360)
		new_mlx_pixel_put(d, x + 2, y + 1, c_head);
}
