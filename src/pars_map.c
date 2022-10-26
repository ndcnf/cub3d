/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:07 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:29:07 by lzima            ###   ########.fr       */
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
			return (p_error("❌ line_map_ok(tmp)\n"));
	}
	return (SUCCESS);
}

int	pars_map(t_data *d, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (++i <= d->fd_line + 1)
		tmp = get_next_line(fd);
	d->nb_line_map = 0;
	d->len_line_map = 0;
	while (tmp != NULL)
	{
		if (line_map_ok(tmp) != SUCCESS)
			return (ERROR);
		len_line(d, tmp);
		d->nb_line_map++;
		tmp = get_next_line(fd);
	}

	return (SUCCESS);
}
