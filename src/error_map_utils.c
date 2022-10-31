/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:12 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:49:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_around(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		if ((map[y][x + 1] != '1' && map[y][x + 1] != '0'
			&& map[y][x + 1] != '2')
		|| (map[y][x - 1] != '1' && map[y][x - 1] != '0'
		&& map[y][x - 1] != '2')
		|| (map[y + 1][x] != '1' && map[y + 1][x] != '0'
		&& map[y + 1][x] != '2')
		|| (map[y - 1][x] != '1' && map[y - 1][x] != '0'
		&& map[y - 1][x] != '2'))
		{
			printf("0 at y:%d | x:%d \n", y + 1, x + 1);
			return (p_error("❌ 0 isn't surrounded\n"));
		}
	}
	return (SUCCESS);
}

int	zero_is_surrounded(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y < d->nb_line_map)
	{
		x = 0;
		while (x <= (int)d->len_line_map)
		{
			if (check_around(d->map, y, x) != SUCCESS)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
