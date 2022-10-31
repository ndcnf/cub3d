
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

# define WIN_TITLE "Cub3D : Title TBD"
# define WIN_H 512
# define WIN_W 512
# define IMG_PXL 64 //16 sera mieux a terme

# define RED 0x00FF0000
# define WHI 0x00FFFFFF
# define GRN 0x00336600
# define DGR 0x004C9900

typedef struct s_colors
{
	int	red;
	int	green;
	int	blue;
}	t_colors;

typedef struct	s_minimap
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_minimap;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	t_minimap	*m2d;

	char	*no;
	int		check_no;
	char	*so;
	int		check_so;
	char	*we;
	int		check_we;
	char	*ea;
	int		check_ea;
	char	*f;
	int		check_f;
	char	*c;
	int		check_c;
	int		fd_line;
	int		nb_line_map; // == y_len
	size_t	len_line_map; // == x_len ET INT ?
	int		x_len; //copie de len_line_map
	int		y_len; //copie de nb_line_map
	char	**map;
	int		malloc_check;
	int		sizeof_tab;
	float	pposx;
	float	pposy;
	char	p_orient;
}			t_data;

typedef struct s_map
{
	int		x;
	int		y;
	int		x_len; // == len_line_map
	int		y_len; // == nb_line_map
	int		cd_x;
	int		cd_y;
	char	*content;
	char	**map2d;
}	t_map;

typedef struct s_items
{
	int	p;
	int	e;
	int	one;
	int	zero;
	int	c;
	int	x_e;
	int	y_e;
}	t_items;

typedef struct s_player
{
	int	x;
	int	y;
	int	cd_x;
	int	cd_y;
}	t_player;

typedef struct s_sprite
{
	int		w;
	int		h;
	void	*img;
}	t_sprite;

typedef struct s_board
{
	t_map		map;
	t_sprite	*spr;
	t_items		*itm;
	t_player	*p1;
	// void		*mlx;
	// void		*img;
	// void		*win;
	int			w;
	int			h;
}	t_board;

/*
 * main.c
 */
int		main(int ac, char **av);
void	print_load_map(t_data *d);
void	print_load_asset(t_data *d);
/*
 * main_utils.c FULL
 */
void	safe_free(void **x);
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
int		asset(t_data *data, int fd);
/*
 * asset_floor_celling_utils.c FULL
 */
int		map_start(t_data *d, char *tmp);
int		error_colors(char *tmp);
int		pars_f(t_data *data, char *tmp);
int		pars_c(t_data *data, char *tmp);
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
void	my_mlx_pixel_put(t_data *d, int x, int y, int color);
void	on_minimap(t_data *d, int i, int j, char type);
void	player_is_here(t_data *d);
void	map2d(t_data *d);
int		key_on(int key, t_data *d);

#endif
