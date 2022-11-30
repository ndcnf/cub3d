/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:27:37 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:49:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_img(t_data *d, t_img *i, char *asset)
{
	i->img = mlx_xpm_file_to_image(d->mlx, asset, &i->w, &i->h);
	i->pxs = (int *)mlx_get_data_addr(i->img, &i->bpp, \
	&i->line_length, &i->endian);
}

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
	int		i;
	char	*s;

	s = ft_strtrim(tmp, " \t\n\r\f\v");
	if (!s)
		return (ERROR);
	if (pars_asset(d, s) != SUCCESS || pars_f_n_c(d, s) != SUCCESS
		|| (s[0] == '1'))
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == '1' || s[i] == ' ' || s[i] == '0')
				i++;
			else
			{
				free(s);
				return (p_error("❌ at MAP_START\n"));
			}
		}
		free(s);
		return (MAP_START);
	}
	free(s);
	return (SUCCESS);
}

int	asset_all_good(t_data *d)
{
	if (d->no == NULL || d->so == NULL || d->we == NULL || d->ea == NULL
		|| d->f < 0 || d->c < 0)
		return (p_error("❌ missing assets or colors (floor || celling)\n"));
	return (SUCCESS);
}

int	asset(t_data *d, int fd, char *tmp)
{
	int		start;

	while (tmp != NULL)
	{
		start = get_asset(d, tmp);
		if (start != SUCCESS)
		{
			if (start == MAP_START)
			{
				if (asset_all_good(d) != SUCCESS)
				{
					safe_free(tmp);
					return (p_error(" ↪ asset_all_good(d)\n"));
				}
				break ;
			}
			safe_free(tmp);
			return (p_error(" ↪ get_asset(d, tmp)\n"));
		}
		d->fd_line++;
		safe_free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	return (SUCCESS);
}
