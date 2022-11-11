/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:32:02 by lzima             #+#    #+#             */
/*   Updated: 2022/11/09 14:00:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw(t_ray *r, int x, t_data *data)
{
	int y;
	(void)r;
	y = 0;
	while (y < r->drawstart)
	{
		my_mlx_pixel_put(data, x, y, data->f);
		y++;
	}
	y = r->drawstart;
//	printf("start %d end %d\n", r->drawstart, r->drawend);
	while(y < r->drawend)
	{
//		printf("in\n");
		my_mlx_pixel_put(data, x, y, RED);
		y++;
	}
	y = r->drawend;
	while (y < WIN_H - 1)
	{
		my_mlx_pixel_put(data, x, y, data->c);
		y++;
	}
}

int raycasting(t_data *data)
{
	init_map(data);
	f_and_c(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_key_hook(data->win, key_on, &data);
	mlx_loop(data->mlx);
	return (1);
}
