/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/10/25 15:42:45 by nchennaf         ###   ########.fr       */
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

// uniquement pour test de fonctionnement. NE PAS UTILISER APRES LE PARSING OK
void	process_map(t_board *bd, int fd)
{
	char	*tempura;
	char	*gnl;

	bd->map.y_len = 0;
	bd->map.x_len = 0;
	gnl = get_next_line(fd);
	bd->map.content = ft_strdup("");
	while (gnl != NULL)
	{
		bd->map.x_len = (int)ft_strlen(gnl);
		tempura = bd->map.content;
		bd->map.content = ft_strjoin(bd->map.content, gnl);
		free(tempura);
		free(gnl);
		gnl = get_next_line(fd);
		bd->map.y_len++;
	}
}

// uniquement pour test de fonctionnement. NE PAS UTILISER APRES LE PARSING OK
void	get_file_tmp(t_board *bd, char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	process_map(bd, fd);
	close(fd);
}

// uniquement pour test de fonctionnement, adapter ensuite car idem Eduardo & Jerome
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
			mlx_pixel_put(bd->mlx, bd->win, x, y, 0X00999896);
			printf("x[%d] et y[%d]\n", x, y);
			y++;
		}
		x++;
	}
	return (0);
}
