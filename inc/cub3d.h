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

# include "../utils/inc/libft.h"
# include "key_macos.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# define SUCCESS 0
# define ERROR 1
# define MAP_START 10

typedef struct s_data
{
	void	*mlx;
	char	*no;
	int 	check_no;
	char	*so;
	int 	check_so;
	char	*we;
	int 	check_we;
	char	*ea;
	int 	check_ea;
	char	*f;
	int 	check_f;
	char	*c;
	int 	check_c;
	int 	fd_line;
	int 	nb_line_map;
	size_t 	len_line_map;
	char	**map;
	int 	sizeof_tab;
	float 	pposx;
	float 	pposy;
}			t_data;

/*
 * main.c
 */
int    main(int ac, char **av);
/*
 * main_utils.c FULL
 */
void	safe_free(void **x);
int		p_error(char *error);
void 	free_map(t_data *data);
int		args_error(int ac);
int		safe_open_map_name_cub(const char *mn);
/*
* init_game.c
*/
void	print_asset(t_data *d);
int		read_map(t_data *data, int fd, const char *map_cub);
int		load_map(t_data *data, int fd, char *map_cub);
/*
* asset_floor_celling.c
*/
int		pars_f_n_c(t_data *data, char *tmp);
int		get_asset(t_data *data, char *tmp);
int		asset_all_good(t_data *d);
int		asset(t_data *data, int fd);
/*
 * asset_floor_celling_utils.c
 */
int		map_start(t_data *d, char *tmp);
void	init_check_asset(t_data *d);
int		error_colors(t_data *data, char *tmp);
/*
* check_asset.c FULL
*/
int		no(t_data *data, char *tmp);
int		so(t_data *data, char *tmp);
int		we(t_data *data, char *tmp);
int		ea(t_data *data, char *tmp);
int		pars_asset(t_data *d, char *tmp);
/*
* pars_map.c
*/
void	len_line(t_data *data, char *tmp);
int		line_map_ok(const char *tmp);
int		pars_map(t_data *data, int fd);
/*
* stock_map.c
*/
int		stock_map(t_data *data, int fd);
int		malloc_map(t_data *d);
void	*ft_calloc_nine(size_t count, size_t size);
/*
* print_map.c
*/
int		print_map(t_data *data, int fd);
void	get_to_line_map_in_fd(t_data *data, int fd);
int		print_full_map(t_data *data, int fd);
int 	init_pos(t_data *data, const char *tmp, int i);
/*
* error_map.c
*/
int 	error_map(t_data *d);
int 	check_borders(t_data *d);
int		check_y(t_data *d);
int 	check_x(t_data *d);
/*
* error_map_utils.c
*/
int 	check_around(char **map, int y, int x);
int 	zero_is_surrended(t_data *d);

#endif