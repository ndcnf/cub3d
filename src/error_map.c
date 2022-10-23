/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:50 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:29:50 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int error_map(t_data *d)
{
	if (check_borders(d) != SUCCESS)
		return (p_error("❌ check border(d)\n"));
	if (zero_is_surrounded(d) != SUCCESS)
		return (p_error("❌ zero_is_surrended(d)\n"));
	return (SUCCESS);
}

int check_borders(t_data *d)
{
	if (check_x(d) != SUCCESS)
		return (p_error("❌ check_x(d)\n"));
	if (check_y(d) != SUCCESS)
		return (p_error("❌ check_y(d)\n"));
	return (SUCCESS);
}

int	check_y(t_data *d)
{
	int y;

	y = 0;
	while (y < d->nb_line_map)
	{
		if (d->map[y][0] == '0')
			return (p_error("❌ 0 isn't surrounded\n"));
		y++;
	}

	y = 0;
	while (y < (int)d->nb_line_map)
	{
		if (d->map[y][d->len_line_map] == '0')
		{
			printf("map[%d][%d] = %c\n", y, (int)d->len_line_map, d->map[y][d->len_line_map]);
			return (p_error("❌ 0 isn't surrounded\n"));
		}
		y++;
	}
	return (SUCCESS);
}

int check_x(t_data *d)
{
	int	x;

	x = 0;
	while (x < (int)d->len_line_map)
	{
		if (d->map[0][x] == '0')
			return (p_error("❌ 0 isn't surrounded\n"));
		x++;
	}
	x = 0;
	while (x < (int)d->len_line_map)
	{
		if (d->map[d->sizeof_tab][x] == '0')
			return (p_error("❌ 0 isn't surrounded\n"));
		x++;
	}
	return (SUCCESS);
}
