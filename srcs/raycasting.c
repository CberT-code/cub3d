/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/20 20:46:03 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_radar(t_radar *r, t_data *d)
{
	r->y = d->p->vector->y;
	r->x = d->p->vector->x;
	r->t = (double)-tan(r->alpha);
	r->b = r->y - r->t * r->x;
}

t_vector	next_block(double rx, double ry, t_vector *p)
{
	t_vector hit;
	hit.x = rx - (p->x > rx && rx == (int)rx ? 0.0001 : 0);
	hit.y = ry - (p->y > ry && ry == (int)ry ? 0.0001 : 0);
	return (hit);
}

void		radar(t_data *d)
{
	t_radar	r;
    t_vector vec_x;
	t_vector vec_y;
    t_vector hit;

	r.alpha = d->p->alpha; // + M_PI / 6;
	//while (r.alpha > d->p->alpha - M_PI / 6)
	//{
		init_radar(&r, d);
        hit = next_block(r.x, r.y, d->p->vector);
		while (d->map->tab_map[(int)hit.y][(int)hit.x] != '1')
		{
            vec_y = calc_next_y(r);
             printf("vec Y.x = %f\n",vec_y.x);
             printf("vec Y.y = %f\n",vec_y.y);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size, vec_y.y * d->mini->size, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size, vec_y.y * d->mini->size + 1, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size, vec_y.y * d->mini->size + 2, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 1, vec_y.y * d->mini->size, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 1, vec_y.y * d->mini->size + 1, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 1, vec_y.y * d->mini->size + 2, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 2, vec_y.y * d->mini->size, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 2, vec_y.y * d->mini->size + 1, 0xFF0000);
            image_set_pixel(d->mini->img, vec_y.x * d->mini->size + 2, vec_y.y * d->mini->size + 2, 0xFF0000);
            vec_x = calc_next_x(r);
             printf("vec X.x = %f\n",vec_x.x);
             printf("vec X.y = %f\n",vec_x.y);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size, vec_x.y * d->mini->size, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size, vec_x.y * d->mini->size, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size, vec_x.y * d->mini->size + 1, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size, vec_x.y * d->mini->size + 2, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 1, vec_x.y * d->mini->size, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 1, vec_x.y * d->mini->size + 1, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 1, vec_x.y * d->mini->size + 2, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 2, vec_x.y * d->mini->size, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 2, vec_x.y * d->mini->size + 1, 0x00FF00);
            image_set_pixel(d->mini->img, vec_x.x * d->mini->size + 2, vec_x.y * d->mini->size + 2, 0x00FF00);
            printf("calc distance vec_y = %f\n", calc_dst_vector(d->p->vector, vec_y.x, vec_y.y));
            printf("calc distance vec_x = %f\n", calc_dst_vector(d->p->vector, vec_x.x, vec_x.y));
            if (calc_dst_vector(d->p->vector, vec_y.x, vec_y.y) < calc_dst_vector(d->p->vector, vec_x.x, vec_x.y))
            {
                r.x = vec_y.x;
                r.y = vec_y.y;
            }
            else
            {
                r.x = vec_x.x;
                r.y = vec_x.y;
            }
            printf("rx = %f\n",r.x);
            printf("ry = %f\n",r.y);
            image_set_pixel(d->mini->img, r.x * d->mini->size, r.y * d->mini->size, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size, r.y * d->mini->size, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size, r.y * d->mini->size + 1, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size, r.y * d->mini->size + 2, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 1, r.y * d->mini->size, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 1, r.y * d->mini->size + 1, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 1, r.y * d->mini->size + 2, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 2, r.y * d->mini->size, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 2, r.y * d->mini->size + 1, 0x0000ff);
            image_set_pixel(d->mini->img, r.x * d->mini->size + 2, r.y * d->mini->size + 2, 0x0000FF);
        hit = next_block(r.x, r.y, d->p->vector);
        }
        r.dist = calc_dst_vector(d->p->vector, r.x, r.y);
        printf("dist = %f\n", r.dist);
	//	r.alpha -= M_PI / 3 / d->texture->r[0];
//	}
}

t_vector       calc_next_y(t_radar r)
{
    t_vector vec_y;
    
    vec_y.x = r.x;
 	vec_y.y = r.y;
    if (sin(r.alpha) < 0)
        vec_y.y = ((int)vec_y.y) + 1;
    else
        vec_y.y = (int) vec_y.y + (vec_y.y == (int) vec_y.y ? -1 : 0);
    vec_y.x = (vec_y.y - r.b) / r.t;
    return (vec_y);
}

t_vector       calc_next_x(t_radar r)
{
    t_vector vec_x;
     
    vec_x.x = r.x;
 	vec_x.y = r.y;
    if (cos(r.alpha) > 0 )
        vec_x.x = ((int)vec_x.x + 1);
    else
        vec_x.x = (int) vec_x.x + (vec_x.x == (int) vec_x.x ? -1 : 0);
    vec_x.y = r.t * vec_x.x + r.b;
    return (vec_x);
}
