/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:30:47 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:30:47 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int print_map(t_data *data, int fd)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_to_line_map_in_fd(data, fd);
	if (print_full_map(data, fd, tmp) != SUCCESS)
		return (ERROR);
	if (error_map(data) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

char	*get_to_line_map_in_fd(t_data *data, int fd)
{
	int 	i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (++i <= data->fd_line + 1)
		tmp = get_next_line(fd);
	return (tmp);
}

int	print_full_map(t_data *data, int fd, char *tmp)
{
	int		i;

	data->sizeof_tab = 0;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp[i] != '\0')
		{
			if (tmp[i] == ' ' || tmp[i] == '\n')
				data->map[data->sizeof_tab][i] = '9';
			else if (init_pos(data, tmp, i) != SUCCESS)
				return (ERROR);
			else if (!(tmp[i] == 'N' || tmp[i] == 'S' ||
								tmp[i] == 'W' || tmp[i] == 'E'))
				data->map[data->sizeof_tab][i] = tmp[i];
			i++;
		}
		if (tmp[i] != '\0')
			data->map[data->sizeof_tab][i] = '\0';
		data->sizeof_tab++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
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
