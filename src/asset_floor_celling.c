/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:27:37 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:27:46 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int error_colors(t_data *data, char *tmp)
{
	return (SUCCESS);
}

int pars_f_n_c(t_data *data, char *tmp)
{

	if (ft_strncmp(tmp, "F", 1) == SUCCESS)
	{
		if (data->check_f == 0)
		{
			data->f = ft_strdup(ft_strtrim(tmp, "F "));
			if (error_colors(data, tmp) != SUCCESS)
				return (p_error("PARSING ERROR: colors setting error\n"));
			data->check_f = 1;
			return (SUCCESS);
		}
		if (data->check_f == 1)
			return (ERROR);
	}
	if (ft_strncmp(tmp, "C", 1) == SUCCESS)
	{
		if (data->check_c == 0)
		{
			data->c = ft_strdup(ft_strtrim(tmp, "C "));
			if (error_colors(data, tmp) != SUCCESS)
				return (p_error("PARSING ERROR: colors setting error\n"));
			data->check_c = 1;
			return (SUCCESS);
		}
		if (data->check_c == 1)
			return (ERROR);
	}
	return (SUCCESS);
}

int get_asset(t_data *d, char *tmp)
{
	(void)d;
	if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
		return (ERROR);
	if (pars_asset(d, tmp) != SUCCESS || pars_f_n_c(d, tmp) != SUCCESS)
	{
		if (tmp[0] != '\0')
			return (SUCCESS);
		if (tmp[1] == '1')
			return (MAP_START);
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int asset_all_good(t_data *d)
{
	if (d->no == NULL || d->so == NULL || d->we == NULL || !d->ea ||
			d->f == NULL || d->c == NULL)
		return (p_error("PARSING ERROR: missing assets or colors (floor || celling)\n"));
	return (SUCCESS);
}

int	asset(t_data *d, int fd)
{
	char	*tmp;
	int		start;

	init_check_asset(d);
	tmp = get_next_line(fd);
	d->fd_line = 0;
	while (tmp != NULL)
	{
		start = get_asset(d, tmp);
		if (start != SUCCESS)
		{
			if (start == MAP_START)
			{
				if (asset_all_good(d) != SUCCESS)
					return (ERROR);
				break ;
			}
			return (ERROR);
		}
		d->fd_line++;
		tmp = get_next_line(fd);
	}
	while (tmp != NULL)
		tmp = get_next_line(fd);
	return (SUCCESS);
}
