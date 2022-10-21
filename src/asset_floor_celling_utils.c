/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_floor_celling_utils.c                              :+:      :+:    :+:   */
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
	(void)d; // ----------------------------------------------------------------- ajoute pour eviter erreur de compilation
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

int error_colors(t_data *data, char *tmp)
{
	char	**colors;
	// int 	c;
	(void)data; // -------------------------------------------------------------- ajoute pour eviter erreur de compilation

	colors = ft_split(tmp, ',');
	if (colors == NULL)
		return (ERROR);
	//if () // ------------------------------------------------------------------ ajoute pour eviter erreur de compilation

	return (SUCCESS);
}
