/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:46:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/20 16:16:12 by cbertola         ###   ########.fr       */
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
	if (d->map.tab_map[(int)vec.y][(int)vec.x] == '2')
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
		d->p.life -= 1;
		d->map.tab_map[(int)vec.y][(int)vec.x] = 0;
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
	if (d->map.tab_map[(int)vec.y][(int)vec.x] == '2')
	{
		d->p.vector.x = vec.x;
		d->p.vector.y = vec.y;
		d->p.life -= 1;
		d->map.tab_map[(int)vec.y][(int)vec.x] = 0;
	}
}
