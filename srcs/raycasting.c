/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/20 19:56:59 by cyrillebert      ###   ########.fr       */
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

void		radar(t_data *d)
{
	t_radar	r;
    t_vector vec_x;
	t_vector vec_y;
	r.alpha = d->p->alpha; // + M_PI / 6;
	//while (r.alpha > d->p->alpha - M_PI / 6)
	//{
		init_radar(&r, d);
		//while (d->map->tab_map[(int)r.y][(int)r.x] != ‘1’)
		//{
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
            if (calc_dst_vector(d->p->vector, vec_y.x, vec_y.y) > calc_dst_vector(d->p->vector, vec_x.x, vec_x.y))
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
            //image_set_pixel(d->mini->img, r.x, r.y, 0x00FF00);
        //}
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
        vec_y.y = ((int)vec_y.y);
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
    printf("r tan = %f\n",r.t);
    vec_x.y = r.t * vec_x.x + r.b;
    return (vec_x);
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
