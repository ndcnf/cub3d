/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:30:47 by lzima             #+#    #+#             */
/*   Updated: 2022/11/21 13:11:37 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	print_map(t_data *data, int fd)
{
	char	*tmp;

	tmp = NULL;
	tmp = get_to_line_map_in_fd(data, fd);
	if (print_full_map(data, fd, tmp) != SUCCESS)
		return (p_error("↪ print_full_map(data, fd, tmp)\n"));
	if (error_map(data) != SUCCESS)
		return (p_error("↪ error_map(data)\n"));
	return (SUCCESS);
}

char	*get_to_line_map_in_fd(t_data *data, int fd)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (++i <= data->fd_line + 1)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
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
				data->map[data->sizeof_tab][i] = '1';
			else if (init_pos(data, tmp, i) != SUCCESS)
				return (ERROR);
			else if (!(tmp[i] == 'N' || tmp[i] == 'S'
					|| tmp[i] == 'W' || tmp[i] == 'E'))
				data->map[data->sizeof_tab][i] = tmp[i];
			i++;
		}
		if (tmp[i] != '\0')
			data->map[data->sizeof_tab][i] = '\0';
		data->sizeof_tab++;
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
}

int	init_pos(t_data *data, const char *tmp, int i)
{
	if (tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' || tmp[i] == 'E')
	{
		if (data->pposx == -1 && data->pposy == -1)
		{
			data->pos = tmp[i];
			data->pposx = (float)i + 0.5;
			data->pposy = (float)data->sizeof_tab + 0.5;
			data->map[data->sizeof_tab][i] = '0';
		}
		else
			return (p_error("↪ init_pos(data, tmp, i)\n"));
	}
	return (SUCCESS);
}
