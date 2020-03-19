/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:46:34 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 14:20:03 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_way(t_data *d)
{
	if (d->p->move == 1)
		d->p->move = M_PI * 2;
	if (d->p->move == 3)
		d->p->move = M_PI_2 / 2 * 7;
	if (d->p->move == 2)
		d->p->move = M_PI_2 * 3;
	if (d->p->move == 6)
		d->p->move = M_PI_2 / 2 * 5;
	if (d->p->move == 4)
		d->p->move = M_PI;
	if (d->p->move == 12)
		d->p->move = M_PI_2 / 2 * 3;
	if (d->p->move == 8)
		d->p->move = M_PI_2;
	if (d->p->move == 9)
		d->p->move = M_PI_2 / 2;
}

void		move_fb(t_data *d)
{
	t_radar	r;
	int		i;

	i = 0;
	init_way(d);
	if (d->p->move > 0)
	{
		
		r.alpha = d->p->alpha + d->p->move;
		init_radar(&r, d);
		if (r.alpha - M_PI_2 < 0.000001 && r.alpha - M_PI_2 > 0.000001)
			r.y = r.y - sin(r.alpha);
		else
		{
			r.x = r.x + cos(r.alpha);
			r.y = r.t * r.x + r.b;
		}
		if (d->map->tab_map[(int)r.y / d->mini->t_case]
		[(int)r.x / d->mini->t_case] != '1')
		{
			d->mini->vector->y = r.y;
			d->mini->vector->x = r.x;
		}
	}
}
