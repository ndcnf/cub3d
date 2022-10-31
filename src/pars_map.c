/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:07 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:46:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	len_line(t_data *data, char *tmp)
{
	size_t	x;

	x = ft_strlen(tmp);
	if (x > data->len_line_map)
		data->len_line_map = x;
}

int	line_map_ok(const char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (ft_strchr("10NSWE \n", tmp[i]) != NULL)
			i++;
		else
			return (p_error("❌  map have an wrong char\n"));
	}
	return (SUCCESS);
}

int	pars_map(t_data *d, int fd)
{
	char	*tmp;
	int		i;

	tmp = get_next_line(fd);
	i = 0;
	while (++i <= d->fd_line)
	{
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	while (tmp != NULL)
	{
		if (line_map_ok(tmp) != SUCCESS)
		{
			free(tmp);
			return (p_error(" ↪️ line_map_ok(tmp)\n"));
		}
		len_line(d, tmp);
		d->nb_line_map++;
		free(tmp);
		tmp = NULL;
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
}
