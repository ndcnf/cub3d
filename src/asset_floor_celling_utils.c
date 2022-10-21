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

int map_start(t_data *d, char *tmp)
{
	if (leakfree_strtrim(&tmp, " \t\n\r\f\v") != SUCCESS)
		return (ERROR);
	return (0);
}

void	init_check_asset(t_data *d)
{
	d->check_no = 0;
	d->check_so = 0;
	d->check_we = 0;
	d->check_ea = 0;
	d->check_f = 0;
	d->check_c = 0;
	d->fd_line = 0;
}

int check_colors(char **colors, int c)
{
	if (c < 0 || c > 256)
	{
		free_tab((void *)colors);
		return (p_error(" PARSING ERROR: colors"));
	}
	return (SUCCESS);
}

int error_colors(char *tmp)
{
	int 	x;
	int 	i;
	char	**c;

	c= ft_split(tmp, ',');
	if (c == NULL)
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		x = -1;
		if (c[i] != NULL)
			x = ft_atoi(c[i]);
		if (check_colors(c, x) != SUCCESS)
			return (ERROR);
	}
	if (c[3] != NULL)
	{
		free_tab((void *)c);
		return (p_error(" PARSING ERROR: colors"));
	}
	free_tab((void *)c);
	return (SUCCESS);
}
