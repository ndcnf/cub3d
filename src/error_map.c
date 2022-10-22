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
		return (ERROR);
	if (zero_is_surrended(d) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int check_borders(t_data *d)
{
	if (check_x(d) != SUCCESS)
		return (ERROR);
	if (check_y(d) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	check_y(t_data *d)
{
	int y;

	y = 0;
	while (y < d->nb_line_map)
	{
		if (d->map[y][0] == '0')
			return (p_error("PARSING ERROR: 0 found on first "));
		y++;
	}

	y = 0;
	while (y < (int)d->len_line_map)
	{
		if (d->map[y][d->len_line_map] == '0')
			return (ERROR);
		y++;
	}
	return (SUCCESS);
}

int check_x(t_data *d)
{
	int	x;

	x = 0;
	while (x < d->nb_line_map)
	{
		if (d->map[0][x] == '0')
			return (ERROR);
		x++;
	}
	x = 0;
	while (x < (int)d->len_line_map)
	{
		if (d->map[d->sizeof_tab][x] == '0')
			return (ERROR);
		x++;
	}
	return (SUCCESS);
}
