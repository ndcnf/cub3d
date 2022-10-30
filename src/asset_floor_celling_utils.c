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
	char	*s;

	if (data->check_f == 0)
	{
		s = ft_strtrim(tmp, "F ");
		data->f = 0;
		if (error_colors(s, &data->f) != SUCCESS)
		{
			free(s);
			return (p_error("❌ F colors setting error\n"));
		}
		free(s);
		data->check_f = 1;
		return (SUCCESS);
	}
	if (data->check_f == 1)
		return (p_error("❌ Duplicate F \n"));
	return (SUCCESS);
}

int	pars_c(t_data *data, char *tmp)
{
	char	*s;

	if (data->check_c == 0)
	{
		s = ft_strtrim(tmp, "C ");
		data->c = 0;
		if (error_colors(s, &data->c) != SUCCESS)
		{
			free(s);
			return (p_error("❌ C colors setting error\n"));
		}
		free(s);
		data->check_c = 1;
		return (SUCCESS);
	}
	if (data->check_c == 1)
		return (p_error("❌ Duplicate C \n"));
	return (SUCCESS);
}

int	map_start(t_data *d, char *tmp)
{
	char	*s;

	(void)d;
	s = ft_strtrim(tmp, " \t\n\r\f\v");
	if (!s)
		return (ERROR);
	free(s);
	return (0);
}

static int	check_colors(char **colors, int *out)
{
	int	c;
	int	i;

	i = 0;
	while (i < 3)
	{
		c = ft_atoi(colors[i]);
		if (c < 0 || c >= 256)
			return (p_error("❌ Range's colors\n"));
		*out = (*out << 8) | c;
		i++;
	}
	return (SUCCESS);
}

int	error_colors(char *tmp, int *out)
{
	char	**colors;

	colors = ft_split(tmp, ',');
	if (colors == NULL)
		return (ERROR);
	if (len_tab((void *)colors) != 3)
	{
		free_tab((void *)colors);
		return (p_error("❌ too many colors\n"));
	}
	if (ft_str_isdigit(tmp, ',') != 1)
	{
		free_tab((void *)colors);
		return (p_error("❌ F colors setting isn't digit\n"));
	}
	if (check_colors(colors, out) != SUCCESS)
	{
		free_tab((void *)colors);
		return (p_error("↪️ check_colors(colors, out)\n"));
	}
	free_tab((void *)colors);
	return (SUCCESS);
}
