/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/25 13:44:06 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_struct(t_data *d)
{
	if (!(d->texture = calloc(sizeof(t_texture), 1)))
		ft_error(ERROR_CALLOC, NULL);
	if (!(d->m = calloc(sizeof(t_move), 1)))
		ft_error(ERROR_CALLOC, NULL);
	if (!(d->map = ft_calloc(sizeof(t_map), 1)))
		ft_error(ERROR_CALLOC, NULL);
	if (!(d->p = ft_calloc(sizeof(t_p), 1)))
		ft_error(ERROR_CALLOC, NULL);
    if (!(d->mini = ft_calloc(sizeof(t_mini), 1)))
		ft_error(ERROR_CALLOC, NULL);
		d->texture->no = calloc(sizeof(t_image), 1);
		d->texture->so = calloc(sizeof(t_image), 1);
		d->texture->we = calloc(sizeof(t_image), 1);
		d->texture->ea = calloc(sizeof(t_image), 1);
		d->texture->sp = calloc(sizeof(t_image), 1);
    
    d->p->vitesse = 0.2;
    d->p->vitesse_rot = -M_PI_2 / 6;
    d->p->height = 0;
    d->mini->size = 10;
    d->mini->display = 0;

}
