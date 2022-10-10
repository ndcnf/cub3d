
#include "./inc/cub3d.h"
#include "./utils/libft.h"
#include "./utils/get_next_line.h"

void	safe_free(void **x)
{
	if ((*x) != NULL)
	{
		free(*x);
		(*x) = NULL;
	}
}

int	args_error(int ac)
{
	if (ac == 1)
	{
		printf("Error: Cud3d needs a *.cub in map folder as an argument\n");
		return (ERROR);
	}
	if (ac > 2)
	{
		printf("Error: Only one argument needed\n");
		return(ERROR);
	}
	return (SUCCESS);
}

void free_map(t_data *data)
{
	safe_free((void *)&data->no);
	safe_free((void *)&data->so);
	safe_free((void *)&data->we);
	safe_free((void *)&data->ea);
}

int	safe_open_mn(const char *mn)
{
	int len;

	len = (int)ft_strlen(mn);
	if (mn == NULL || len < 4 || (ft_strncmp(&mn[len - 4], ".cub", 5) != 0))
		return (-1);
	else
		return(open(mn, O_RDONLY));
}

int	pars_asset(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "NO", 2) == SUCCESS && data->fd_line == 1)
		data->no = ft_strdup(ft_strchr(tmp, (char)'.'));
	else if (ft_strncmp(tmp, "SO", 2) == SUCCESS && data->fd_line == 2)
		data->so = ft_strdup(ft_strchr(tmp, (char)'.'));
	else if (ft_strncmp(tmp, "WE", 2) == SUCCESS && data->fd_line == 3)
		data->we = ft_strdup(ft_strchr(tmp, (char)'.'));
	else if (ft_strncmp(tmp, "EA", 2) == SUCCESS && data->fd_line == 4)
		data->ea = ft_strdup(ft_strchr(tmp, (char)'.'));
	else
		return(ERROR);
	return(SUCCESS);
}

int pars_f_n_c(t_data *data, char *tmp)
{
	if (data->fd_line == 5)
		data->fd_line++;
	else if (ft_strncmp(tmp, "F", 1) == SUCCESS && data->fd_line == 6)
		data->f = ft_strdup(ft_strtrim(tmp, "F "));
	else if (ft_strncmp(tmp, "C", 1) == SUCCESS && data->fd_line == 7)
		data->c = ft_strdup(ft_strtrim(tmp, "C "));
	else
		return (ERROR);
	return (SUCCESS);
}

int	line_map_ok(const char *tmp)
{
	int i;

	i = 0;
	while(tmp[i] != '\0')
	{
		if (tmp[i] == '1' || tmp[i] == '0' || tmp[i] == 'N' || tmp[i] == 'S' \
			|| tmp[i] == 'W' || tmp[i] == 'E' || tmp[i] == ' ' || tmp[i] == '\n')
			i++;
		else
			return (ERROR);
	}
	return (SUCCESS);
}

void	len_line(t_data *data, char *tmp)
{
	size_t	x;

	x = ft_strlen(tmp);
	if (x > data->len_line_map)
		data->len_line_map = x;
}

int	pars_map(t_data *data, int fd)
{
	char		*tmp;

	data->len_line_map = 0;
	while (data->fd_line >= 9 || tmp != NULL)
	{
		tmp = get_next_line(fd);
		data->nb_line_map++;
		if (line_map_ok(tmp) != SUCCESS)
			return (ERROR);
		len_line(data, tmp);
	}
	return (SUCCESS);
}

int asset(t_data *data, int fd)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_next_line(fd);
	data->fd_line = 1;
	while (tmp != NULL && data->fd_line <= 8)
	{
		data->fd_line++;
		if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
			return (ERROR);
		if (pars_asset(data, tmp) != SUCCESS)
			return(ERROR);
		if (pars_f_n_c(data, tmp) != SUCCESS)
			return (ERROR);
		if (data->fd_line == 5 && ft_strncmp(tmp, "\n", ft_strlen(tmp) != SUCCESS))
			return (ERROR);
		if (data->fd_line == 8 && ft_strncmp(tmp, "\n", ft_strlen(tmp) != SUCCESS))
			return (ERROR);
		safe_free((void *)&tmp);
		tmp = get_next_line(fd);
	}
	safe_free((void *)&tmp);
	return(SUCCESS);
}

void	*ft_calloc_nine(size_t count, size_t size)
{
	char	*memoryallocation;

	memoryallocation = malloc(count * size);
	if (memoryallocation == NULL)
		return (memoryallocation);
	ft_memset(memoryallocation, '9', count * size);
	return (memoryallocation);
}

int malloc_map(t_data *d)
{
	int i;

	d->map = malloc(d->nb_line_map * sizeof(char *));
	if (alloc_check(d->map) != SUCCESS)
		return (ERROR);
	i = 0;
	while(d->nb_line_map-- >= 0)
	{
		d->map[i] = (char *)ft_calloc_nine(1, (d->len_line_map * sizeof(char)));
		if (alloc_check(d->map[i]) != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	get_to_line_map_in_fd(t_data *data, int fd)
{
	char *tmp;
	int i;

	tmp = NULL;
	data->fd_line = 0;
	while (data->fd_line < 9)
	{
		tmp = get_next_line(fd);
		free(tmp);
		data->fd_line++;
	}
}

int init_pos(t_data *data, const char *tmp, int i)
{
	if (tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E')
	{
		if (data->pposx == -1 && data->pposy == -1)
		{
			data->pposx = (float)data->sizeof_tab;
			data->pposy = (float)i;
			data->map[data->sizeof_tab][i] = '0';
		}
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int	print_full_map(t_data *data, int fd)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	tmp = get_next_line(fd);
	data->sizeof_tab = 0;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp[i] != '\0' || tmp[i] != '\n')
		{
			if (tmp[i] == ' ')
				data->map[data->sizeof_tab][i] = '9';
			if (init_pos(data, tmp, i) != SUCCESS)
				return (ERROR);
			else
				data->map[data->sizeof_tab][i] = tmp[i];
			i++;
		}
		data->sizeof_tab++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
}

int check_x(t_data *d)
{
	int	x;

	x = 0;
	while (d->map[0][x] != '\0')
	{
		if (d->map[0][x] == 0)
			return (ERROR);
		x++;
	}
	x = 0;
	while (d->map[d->sizeof_tab][x] != '\0')
	{
		if (d->map[d->sizeof_tab][x] == 0)
			return (ERROR);
		x++;
	}
	return (SUCCESS);
}

int	check_y(t_data *d)
{
	int y;

	y = 0;
	while (d->map[y][0] != '\0')
	{
		if (d->map[y][0] == 0)
			return (ERROR);
		y++;
	}

	y = 0;
	while (d->map[y][d->len_line_map])
	{
		if (d->map[y][d->len_line_map] == 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int check_borders(t_data *d)
{
	int	x;
	int	y;

	if (check_x(d) != SUCCESS)
		return (ERROR);
	if (check_y(d) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

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

int zero_is_surrended(t_data *d)
{
	int x;
	int	y;

	y = 0;
	while (d->map[y][x])
	{
		y = 0;
		while (d->map[y][x] != '\0')
		{
			if (check_around(d->map, y, x) != SUCCESS)
				return (ERROR);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}

int error_map(t_data *d)
{
	if (check_borders(d) != SUCCESS)
		return (ERROR);
	if (zero_is_surrended(d) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int print_map(t_data *data, int fd)
{
	get_to_line_map_in_fd(data, fd);
	if (print_full_map(data, fd) != SUCCESS)
		return (ERROR);
	if (error_map(data) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	stock_map(t_data *data, int fd)
{
	if (malloc_map(data) != SUCCESS)
		return (ERROR);
	if (print_map(data, fd) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int read_map(t_data *data, const char *mn)
{
	int fd;

	fd = safe_open_mn(mn);
	if (fd == -1)
		return (ERROR);
	if (asset(data, fd) != SUCCESS)
		return (ERROR);
	if (pars_map(data, fd) != SUCCESS)
		return (ERROR);
	close(fd);
	fd = open(mn, O_RDONLY);
	if (stock_map(data, fd) != SUCCESS)
		return (ERROR);
	return (SUCCESS);

}

int	load_map(t_data *data, char *map_name)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = NULL;
	data->c = NULL;
	data->pposx = -1;
	data->pposy = -1;
	if (read_map(data, map_name) != SUCCESS)
	{
		free_map(data);
		printf("Error: invalid map\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int    main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (args_error(ac) == ERROR)
		return (SUCCESS);
	if (load_map(&data, av[1]) == ERROR)
		return (SUCCESS);


}
