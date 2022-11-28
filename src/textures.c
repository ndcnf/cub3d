/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:58:25 by nchennaf          #+#    #+#             */
/*   Updated: 2022/11/28 15:40:05 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int		color_side(t_data *d)
// {
// 	// if (d->ray->side == 0 && d->x->ray_dir < 0)
// 	// 	return (LGN);
// 	// else if (d->ray->side == 0 && d->x->ray_dir >= 0)
// 	if (d->ray->side == 0 && d->x->ray_dir >= 0)
// 		// return (PNK);
// 		d->x->tex = TEX_SIZE - d->x->tex - 1;
// 	else if (d->ray->side == 1 && d->y->ray_dir < 0)
// 		// return (RED);
// 		d->x->tex = TEX_SIZE - d->x->tex - 1;

// 	// else
// 	// 	return (BLU);
// }


void	load(t_data *d)
{
	d->n = ft_calloc(1, sizeof(t_img));
	// d->n
	d->e = ft_calloc(1, sizeof(t_img));
	d->w = ft_calloc(1, sizeof(t_img));
	d->s = ft_calloc(1, sizeof(t_img));
}

void	texture_init(t_data *d)
{
	d->ray->tex_num = d->map[d->x->map][d->y->map] - 1;

	if (d->ray->side == 0)
		d->x->wall = d->pposy + d->ray->perpwalldist * d->y->ray_dir;
	else
		d->x->wall = d->pposx + d->ray->perpwalldist * d->x->ray_dir; //pposx ou une autre valeur de position pour "posx" ?
	d->x->wall -= floor(d->x->wall); //floor arrondi a l'int inferieur

	d->x->tex = (int)(d->x->wall * (float)(TEX_SIZE));
	if (d->ray->side == 0 && d->x->ray_dir >= 0)
		d->x->tex = TEX_SIZE - d->x->tex - 1;
	else if (d->ray->side == 1 && d->y->ray_dir < 0)
		d->x->tex = TEX_SIZE - d->x->tex - 1;
}

void	load_tex(t_data *d, int x)
{
	int	i;

	d->ray->step = 1.0 * TEX_SIZE / TEX_SIZE;
	d->ray->tex_pos = (d->ray->drawstart - WIN_H / 2 + d->ray->lineheight / 2) * d->ray->step;
	i = d->ray->drawstart;
	while (i < d->ray->drawend)
	{
		d->y->tex = (int)d->ray->tex_pos & (TEX_SIZE - 1); //attention masque & avec hauteur de texture - 1 pour eviter overflow
		d->ray->tex_pos += d->ray->step;
		// d->ray->color = texture[d->ray->tex_num][TEX_SIZE * d->y->tex + d->x->tex]; //texture n'exite pas encore. CHERCHER concordance dans parsing
		d->ray->buffer[i][x];
		i++;
	}

}
