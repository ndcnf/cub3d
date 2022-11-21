/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:33:16 by lzima             #+#    #+#             */
/*   Updated: 2022/11/21 20:01:49 by nchennaf         ###   ########.fr       */
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
#	define BUFFER_SIZE 256
# endif

# define SUCCESS 0
# define ERROR 1
# define MAP_START 10
# define BYE "Bye\n"

# define WIN_TITLE "Cub3D : Title TBD"
# define ZOOM 3 // How many times WIN_H and WIN_W (6)
# define WIN_W (320 * ZOOM) // 1080
# define WIN_H (200 * ZOOM) // 720
# define POV 60
# define MM_L 16 // size minimap
# define MM_M 6 // size minimap
# define MM_S 1 // size minimap
# define ROT_ANGL 18 // 360 doit etre divisible par ce nombre
# define SPEED 0.05

# define RED 0x00FF0000
# define WHI 0x00FFFFFF
# define GRN 0x00336600
# define DGR 0x004C9900
# define BLU 0x000000FF

// variables that couldn't be modified though raycast process
typedef struct	s_setup
{
	int		i;
}	t_setup;

// variables that could be modified though raycast process
//typedef struct	s_ray
//{
//	int		drawstart;
//	int 	drawend;
//}	t_ray;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_raycasting
{
	float	map_check;
	int		map_sz;
	float	ray_start;
	float	ray_len;
	// int		step;
	// float	ray_dir;
	float	step_sz;

	//repris de s_ray
	double	dir;
	double	plane;
	int		map;
	double	sidedist;
	double	deltadist;
	double	camera; // uniquement pour x
	double	ray_dir;
	int		step;

	float	o_dir;
	float	o_plane;

}	t_raycasting;

typedef struct	s_rayunits
{
	float	dist_max;
	float	dist;
	int		tile_found; // = hit
	float	intersection;

	//repris de s_ray
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
}	t_rayunits;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	int		mm_size;
	t_img	*img;
	t_raycasting *x;
	t_raycasting *y;
	t_rayunits	*ray;

	char	*no;
	int		check_no;
	char	*so;
	int		check_so;
	char	*we;
	int		check_we;
	char	*ea;
	int		check_ea;
	int 	f;
	int		check_f;
	int 	c;
	int		check_c;
	int		fd_line;
	int		nb_line_map;
	int		len_line_map;
	char	**map;
	char	*tmp;
	int		start;
	int		malloc_check;
	int		sizeof_tab;
	float	pposx;
	float	pposy;
	char	pos;
	int		angle;
//	t_ray	*ray;
	t_setup	*setup;
}			t_data;

/*
 * main.c
 */
int		main(int ac, char **av);
/*
 * main_parsing.c
 */
int		main_parsing(int ac, char **av, t_data *data);
void	print_load_map(t_data *d);
void	print_load_asset(t_data *d);
int		main_minimap(t_data *d);
/*
 * main_utils.c FULL
 */
void	safe_free(void *x);
int		p_error(char *error);
void	free_map(t_data *data);
int		args_error(int ac);
int		safe_open_map_name_cub(const char *mn);
/*
* init_game.c
*/
int		read_map(t_data *data, int fd, const char *map_cub);
int		load_map(t_data *data, int fd, char *map_cub);
/*
* asset_floor_celling.c
*/
int		pars_f_n_c(t_data *data, char *tmp);
int		get_asset(t_data *data, char *tmp);
int		asset_all_good(t_data *d);
int		asset(t_data *data, int fd, char *tmp);
/*
 * asset_floor_celling_utils.c FULL
 */
int		map_start(t_data *d, char *tmp);
int		error_colors(char *tmp, int *out);
int		pars_f(t_data *data, char *tmp);
int		pars_c(t_data *data, char *tmp);
int		translated_colors(int *out, char *s);
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
void	*ft_calloc_p(size_t count, size_t size);
/*
* print_map.c
*/
int		print_map(t_data *data, int fd);
char	*get_to_line_map_in_fd(t_data *data, int fd);
int		print_full_map(t_data *data, int fd, char *tmp);
int		init_pos(t_data *data, const char *tmp, int i);
/*
* error_map.c
*/
int		error_map(t_data *d);
int		check_borders(t_data *d);
int		check_y(t_data *d);
int		check_x(t_data *d);
/*
* error_map_utils.c
*/
int		check_around(char **map, int y, int x);
int		zero_is_surrounded(t_data *d);
/*
* minimap.c
*/
void	init_map(t_data *d);
void	minimap_area(t_data *d, int i, int j, int color);
void	new_mlx_pixel_put(t_data *d, int x, int y, int color);
void	on_minimap(t_data *d, int i, int j, char type);
void	map2d(t_data *d);
int		key_on(int key, t_data *d);
int		close_win(void);
void	player_angle(t_data *d);
int		update_img(t_data *d);
void	minimap_size(t_data *d);

void	move(t_data *d, int key);
void	define_player_head(t_data *d, int x, int y, int c_head);
void	init_move(t_data *d);
// void	init_move(t_data *d, float dir);
/*
* directions.c
*/
void	go_forth(t_data *d);
void	go_back(t_data *d);
void	go_left(t_data *d);
void	go_right(t_data *d);
void	look_around(t_data *d, int key);
/*
* minimap_player.c
*/
void	player_head_e(t_data *d, int x, int y, int c_head);
void	player_head_w(t_data *d, int x, int y, int c_head);
void	player_head_n(t_data *d, int x, int y, int c_head);
void	player_head_s(t_data *d, int x, int y, int c_head);
void	player_is_here(t_data *d, int c_body, int c_head);

/*
 * raycasting.c
 */
int 	main_raycasting(t_data *data);

/*
 * angles.c
 */
// int	dtorad(t_data *d);
float	dtorad(t_data *d);


#endif
