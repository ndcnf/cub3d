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

int	pars_f_n_c(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "F", 1) == SUCCESS)
		if (pars_f(data, tmp) != SUCCESS)
			return (ERROR);
	if (ft_strncmp(tmp, "C", 1) == SUCCESS)
		if (pars_c(data, tmp) != SUCCESS)
			return (ERROR);
	return (SUCCESS);
}

int	get_asset(t_data *d, char *tmp)
{
	int	i;

	(void)d;
	if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
		return (ERROR);
	if (pars_asset(d, tmp) != SUCCESS || pars_f_n_c(d, tmp) != SUCCESS
		|| (tmp[0] == '1'))
	{
		i = 0;
		while (tmp[i] != '\0')
		{
			if (tmp[i] == '1' || tmp[i] == ' ')
				i++;
			else
				return (p_error("❌ at MAP_START\n"));
		}
		return (MAP_START);
	}
	return (SUCCESS);
}

int	asset_all_good(t_data *d)
{
	if (d->no == NULL || d->so == NULL || d->we == NULL || d->ea == NULL
		|| d->f == NULL || d->c == NULL)
		return (p_error("❌ missing assets or colors (floor || celling)\n"));
	return (SUCCESS);
}

int	asset(t_data *d, int fd)
{
	char	*tmp;
	int		start;

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
					return (p_error("❌ asset_all_good(d)\n"));
				break ;
			}
			return (p_error("❌ get_asset(d, tmp)\n"));
		}
		d->fd_line++;
		tmp = get_next_line(fd);
	}
	while (tmp != NULL)
		tmp = get_next_line(fd);
	return (SUCCESS);
}
