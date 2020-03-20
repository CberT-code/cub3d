/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:40 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 15:00:35 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_radar(t_radar *r, t_data *d)
{
	r->y = (double)d->mini->vector->y;
	r->x = (double)d->mini->vector->x;
	r->t = (double)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->map->x_max * d->mini->t_case;
}

void		radar(t_data *d)
{
	t_radar	r;
	r.alpha = d->p->alpha + M_PI / 6;
	while (r.alpha > d->p->alpha - M_PI / 6)
	{
		init_radar(&r, d);
		while (r.width--)
		{
			if (r.alpha - M_PI_2 < 0.000001 && r.alpha - M_PI_2 > 0.000001)
				r.y = r.y - sin(r.alpha);
			else
			{
				r.x = r.x + cos(r.alpha);
				r.y = r.t * r.x + r.b;
			}
			if (d->map->tab_map[(int)r.y / d->mini->t_case]
			[(int)r.x / d->mini->t_case] != '1')
				d->p->img->buffer[(int)r.y * (int)d->mini->ligne
				+ (int)(r.x)] = (int)0xFF0000;
			else
				r.width = 0;
		}
		r.alpha -= M_PI / 3 / d->texture->r[0];
	}
}

// void		radar2(t_data *d)
// {
// 	t_radar	r;
// 	t_vector vec_x;
// 	t_vector vec_y;
// 	int i;

// i=0;
// 	r.alpha = d->p->alpha + M_PI / 6;


// 	while (r.alpha > d->p->alpha - M_PI / 6)
// 	{
// 		init_radar(&r, d);
// 		while (r.width--)
// 		{
// 			vec_x.x = r.x;
// 			vec_x.y = r.y;
// 			vec_y.x = r.x;
// 			vec_y.y = r.y;
// 			if (r.alpha - M_PI_2 == 0)
// 				r.y = r.y - sin(r.alpha);
// 			else
// 			{
// 				if (cos(r.alpha) > 0 )
// 					vec_x.x = ((int)vec_x.x + 1);
// 				else
// 					vec_x.x = (int) vec_x.x + (vec_x.x == (int) vec_x.x ? -1 : 0);
// 				vec_x.y = r.t * vec_x.x + r.b;


// 				if (sin(r.alpha) < 0)
// 					vec_y.y = ((int)vec_y.y);
// 				else
// 					vec_y.y = (int) vec_y.y + (vec_y.y == (int) vec_y.y ? -1 : 0);
// 				vec_y.x = (vec_y.y - r.b) / r.t;
				
// 				if ((vec_x.dist = pow(p.x - vec_x.x, 2) + pow(p.y - vec_x.y, 2)) > (vec_y.dist = pow(p.x - vec_y.x, 2) + pow(p.y - vec_y.y, 2)))
// 				{
// 					r.x = vec_y.x;
// 					r.y = vec_y.y;
// 					r.dist = vec_y.dist;
// 				}	
// 				else
// 				{
// 					r.x = vec_x.x;
// 					r.y = vec_x.y;
// 					r.dist = vec_x.dist;
// 				}
				
					
// 			}
// 			if (d->map->tab_map[(int)r.y / d->mini->t_case]
// 			[(int)r.x / d->mini->t_case] != '1')
// 				d->p->img->buffer[(int)r.y * (int)d->mini->ligne
// 				+ (int)(r.x)] = (int)0xFF0000;
// 			else
// 			{
// 				r.width = 0;
// 				r.dist = sqrt( pow(player.x - r.x, 2) + pow(player.y - r.y, 2));
// 				display_raycast(d, r.dist, i, color);
// 			}
// 		}
// 		r.alpha -= M_PI / 3 / d->texture->r[0];
// 		i++;
// 	}
// 		printf("nombre de rayons %d\n", i);
// }
