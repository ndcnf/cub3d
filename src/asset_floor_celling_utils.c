/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_floor_celling_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:27:37 by lzima             #+#    #+#             */
/*   Updated: 2022/10/12 18:27:46 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	pars_f(t_data *data, char *tmp)
{
	if (data->check_f == 0)
	{
		data->f = ft_strdup(ft_strtrim(tmp, "F "));
		if (error_colors(data->f) != SUCCESS)
			return (p_error("❌ F colors setting error\n"));
		data->check_f = 1;
		return (SUCCESS);
	}
	if (data->check_f == 1)
		return (p_error("❌ Duplicate F \n"));
	return (SUCCESS);
}

int	pars_c(t_data *data, char *tmp)
{
	if (data->check_c == 0)
	{
		data->c = ft_strdup(ft_strtrim(tmp, "C "));
		if (error_colors(data->c) != SUCCESS)
			return (p_error("❌ C colors setting error\n"));
		data->check_c = 1;
		return (SUCCESS);
	}
	if (data->check_c == 1)
		return (p_error("❌ Duplicate C \n"));
	return (SUCCESS);
}

int	map_start(t_data *d, char *tmp)
{
	(void)d;
	if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
		return (ERROR);
	return (0);
}

static int	check_colors(char **colors, int c)
{
	if (c < 0 || c > 256)
	{
		free_tab((void *)colors);
		return (p_error("❌ Range's colors"));
	}
	return (SUCCESS);
}

int	error_colors(char *tmp)
{
	int		x;
	int		i;
	char	**colors;

	colors = ft_split(tmp, ',');
	if (colors == NULL)
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		x = -1;
		if (colors[i] != NULL)
			x = ft_atoi(colors[i]);
		if (check_colors(colors, x) != SUCCESS)
			return (ERROR);
		i++;
	}
	if (colors[3] != NULL)
	{
		free_tab((void *)colors);
		return (p_error("❌ too many colors"));
	}
	free_tab((void *)colors);
	return (SUCCESS);
}
