/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:54:23 by nchennaf          #+#    #+#             */
/*   Updated: 2022/10/26 16:52:24 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../inc/key_macos.h"

void	init_map(t_board *bd)
{
	bd->h = bd->map.y_len;
	bd->w = (bd->map.x_len - 1);
	//bd->mlx = mlx_init();
	//bd->win = mlx_new_window(bd->mlx, bd->w, bd->h, WIN_TITLE);
	bd->map.x = 0;
	bd->map.y = 0;
}


// uniquement pour test de fonctionnement. NE PAS UTILISER APRES LE PARSING OK
// void	process_map(t_board *bd, int fd)
// {
// 	char	*tempura;
// 	char	*gnl;

// 	bd->map.y_len = 0;
// 	bd->map.x_len = 0;
// 	gnl = get_next_line(fd);
// 	bd->map.content = ft_strdup("");
// 	while (gnl != NULL)
// 	{
// 		bd->map.x_len = (int)ft_strlen(gnl);
// 		tempura = bd->map.content;
// 		bd->map.content = ft_strjoin(bd->map.content, gnl);
// 		free(tempura);
// 		free(gnl);
// 		gnl = get_next_line(fd);
// 		bd->map.y_len++;
// 	}
// }

// // uniquement pour test de fonctionnement. NE PAS UTILISER APRES LE PARSING OK
// void	get_file_tmp(t_board *bd, char *argv[])
// {
// 	int		fd;

// 	fd = open(argv[1], O_RDONLY);
// 	process_map(bd, fd);
// 	close(fd);
// }

char	**map_test(void)
{
	char **tm;

	tm = malloc(sizeof(char *) * 5 * 6);
	tm[0] = "11111";
	tm[1] = "10001";
	tm[2] = "11N01";
	tm[3] = "10011";
	tm[4] = "11111";
	tm[5] = NULL;
	return(tm);
}

void	my_mlx_pixel_put(t_minimap *m, int x, int y, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_length + x * (m->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// uniquement pour test de fonctionnement, adapter ensuite car idem Eduardo & Jerome
int		minimap_area(t_board *bd, t_minimap *m)
{
	int	x;
	int	y;
	int	i = 0; //temporaire
	char	**tm;

	tm = map_test();
	while (tm[i] != NULL)
		printf("tm[i] : [%s]\n", tm[i++]);
	x = bd->map.x * 5;
	while (x < ((bd->map.x + 1) * 5))
	{
		y = bd->map.y * 5;
		while (y < ((bd->map.y + 1) * 5))
		{
			my_mlx_pixel_put(m->img, x, y, 0X00999896);
			printf("x[%d] et y[%d]\n", x, y);
			y++;
		}
		x++;
	}
	return (0);
}
