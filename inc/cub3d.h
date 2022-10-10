/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ******************* by lzima             #+#    #+#             */
/*   Updated: ******************* by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <limits.h>
# include <stdint.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include <stddef.h>
# include <sys/time.h>
//
//# include "../utils/libft.h"
//# include "../utils/get_next_line.h"
# include "./key_macos.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define SUCCESS 0
# define ERROR 1

typedef struct s_data
{
	void	*mlx;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int 	fd_line;
	int 	nb_line_map;
	size_t 	len_line_map;
	char	**map;
	int 	sizeof_tab;
	float 	pposx;
	float 	pposy;
}			t_data;


int    main(int ac, char **av);

	int		args_error(int ac);

	int	load_map(t_data *data, char *map_name);

		int read_map(t_data *data, const char *mn);

			int		safe_open_mn(const char *mn);

			int		asset(t_data *data, int fd);

				int		pars_asset(t_data *data, char *tmp);

				int		pars_f_n_c(t_data *data, char *tmp);

			int		pars_map(t_data *data, int fd);

				int		line_map_ok(const char *tmp);

				void	len_line(t_data *data, char *tmp);

			int		stock_map(t_data *data, int fd);

				int		malloc_map(t_data *d);

					void	*ft_calloc_nine(size_t count, size_t size);

				int		print_map(t_data *data, int fd);

					void	get_to_line_map_in_fd(t_data *data, int fd);

					int	print_full_map(t_data *data, int fd);

						int init_pos(t_data *data, const char *tmp, int i);

					int error_map(t_data *d);

						int check_borders(t_data *d);

							int	check_y(t_data *d);

							int check_x(t_data *d);

						int zero_is_surrended(t_data *d);

							int check_around(char **map, int y, int x);


#endif