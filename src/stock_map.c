/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:29:40 by lzima             #+#    #+#             */
/*   Updated: 2022/10/31 11:38:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	stock_map(t_data *data, int fd)
{
	if (malloc_map(data) != SUCCESS)
		return (ERROR);
	if (print_map(data, fd) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

int	malloc_map(t_data *d)
{
	int	i;

	d->map = malloc((d->nb_line_map + 1) * sizeof(char *));
	if (alloc_check(d->map) != SUCCESS)
		return (p_error("❌ malloc_map error\n"));
	i = 0;
	while (i < d->nb_line_map)
	{
		d->map[i] = (char *)ft_calloc_p(d->len_line_map + 1, sizeof(char));
		if (alloc_check(d->map[i]) != SUCCESS)
			return (p_error("❌ malloc_map error\n"));
		d->map[i][d->len_line_map] = '\0';
		d->malloc_check = i;
		i++;
	}
	d->map[i] = NULL;
	return (SUCCESS);
}

void	*ft_calloc_p(size_t count, size_t size)
{
	char	*memoryallocation;

	memoryallocation = malloc(count * size);
	if (memoryallocation == NULL)
		return (memoryallocation);
	ft_memset(memoryallocation, '1', count * size);
	return (memoryallocation);
}
