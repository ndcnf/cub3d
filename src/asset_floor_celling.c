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

int	safe_open_mn(const char *mn)
{
	int len;

	len = (int)ft_strlen(mn);
	if (mn == NULL || len < 4 || (ft_strncmp(&mn[len - 4], ".cub", 5) != 0))
		return (-1);
	else
		return(open(mn, O_RDONLY));
}

int get_asset(t_data *d, char *tmp)
{
	(void)d;
	if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
		return (ERROR);
	if (pars_asset(d, tmp) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	asset(t_data *d, int fd)
{
	char	*tmp;

	d->full_asset = -1;
	d->check_no = 0;
	d->check_so = 0;
	d->check_we = 0;
	d->check_ea = 0;
	d->check_f = 0;
	d->check_c = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		if (get_asset(d, tmp) != SUCCESS)
			return (ERROR);
		if (pars_f_n_c(d, tmp) != SUCCESS)
			return (ERROR);
		tmp = get_next_line(fd);
	}
	return (SUCCESS);
}

int pars_f_n_c(t_data *data, char *tmp)
{

	if (ft_strncmp(tmp, "F", 1) == SUCCESS)
	{
		if (data->check_f == 0)
		{
			data->f = ft_strdup(ft_strtrim(tmp, "F "));
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
			data->check_c = 1;
			return (SUCCESS);
		}
		if (data->check_c == 1)
			return (ERROR);
	}
	return (SUCCESS);
}
