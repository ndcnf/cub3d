/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:31:12 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:31:12 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int check_around(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == '2')
	{
		if ((map[y][x + 1] != '1' && map[y][x + 1] != '0' && map[y][x + 1] != '2') ||
			(map[y][x - 1] != '1' && map[y][x - 1] != '0' && map[y][x - 1] != '2') ||
			(map[y + 1][x] != '1' && map[y + 1][x] != '0' && map[y + 1][x] != '2') ||
			(map[y - 1][x] != '1' && map[y - 1][x] != '0' && map[y - 1][x] != '2'))
			return (ERROR);
	}
	return (SUCCESS);
}
//todo != NULL condition needs to be set when map is printed in char **d->map
int zero_is_surrended(t_data *d)
{
	int x;
	int	y;

	y = 0;
	while (y <= d->nb_line_map)
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
