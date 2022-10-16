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

int   pars_asset(t_data *d, char *tmp)
{
	if (no(d, tmp) != SUCCESS)
		return (ERROR);
	if (we(d, tmp) != SUCCESS)
		return (ERROR);
	if (so(d, tmp) != SUCCESS)
		return (ERROR);
	if (ea(d, tmp) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	no(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "NO", 2) == SUCCESS)
	{
		if (data->check_no == 0)
		{
			data->no = ft_strdup(ft_strchr(tmp, (char)'.'));
			data->check_no = 1;
			return (SUCCESS);
		}
		if (data->check_no == 1)
			return (ERROR);
	}
	return (SUCCESS);
}

int so(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "SO", 2) == SUCCESS)
	{
		if (data->check_so == 0)
		{
			data->so = ft_strdup(ft_strchr(tmp, (char)'.'));
			data->check_so = 1;
			return (SUCCESS);
		}
		if (data->check_so == 1)
			return (ERROR);
	}
	return (SUCCESS);
}

int	we(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "WE", 2) == SUCCESS)
	{
		if (data->check_we == 0)
		{
			data->we = ft_strdup(ft_strchr(tmp, (char)'.'));
			data->check_we = 1;
			return (SUCCESS);
		}
		if (data->check_we == 1)
			return (ERROR);
	}
	return (SUCCESS);
}

int	ea(t_data *data, char *tmp)
{
	if (ft_strncmp(tmp, "EA", 2) == SUCCESS)
	{
		if (data->check_ea == 0)
		{
			data->ea = ft_strdup(ft_strchr(tmp, (char)'.'));
			data->check_ea = 1;
			return (SUCCESS);
		}
		if (data->check_ea == 1)
			return (ERROR);
	}
	return (SUCCESS);
}