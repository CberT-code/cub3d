/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cyrille.bertola@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:46:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/09 20:47:37 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		move_fb(t_data *d, int i)
{
	t_vector	vec;

	vec.x = d->p.vector.x;
	vec.y = d->p.vector.y;
	vec.x += cos(d->p.alpha) * i * d->p.vitesse;
	vec.y -= sin(d->p.alpha) * i * d->p.vitesse;
	if (d->map.tab_map[(int)vec.y][(int)vec.x] != '1')
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
	}
}

void		move_lr(t_data *d, int i)
{
	t_vector	vec;

	vec.x = d->p.vector.x;
	vec.y = d->p.vector.y;
	vec.x += cos(d->p.alpha + M_PI_2) * i * d->p.vitesse;
	vec.y -= sin(d->p.alpha + M_PI_2) * i * d->p.vitesse;
	if (d->map.tab_map[(int)vec.y][(int)vec.x] != '1')
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
	}
}
