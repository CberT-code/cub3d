/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:30:50 by cbertola         ###   ########.fr       */
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
    d->p->vitesse = 0.2;
    d->p->vitesse_rot = 5;
}
