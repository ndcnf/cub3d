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

int	pars_map(t_data *data, int fd)
{
	char		*tmp;
	tmp = get_next_line(fd);
	data->len_line_map = 0;
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		data->nb_line_map++;
		if (line_map_ok(tmp) != SUCCESS)
			return (ERROR);
		len_line(data, tmp);
	}
	return (SUCCESS);
}