/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:39:32 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/29 13:59:57 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        init_sprite(t_data *d, char sprite, t_vector hit)
{
    d->sprite.vec.x = hit.x;
    d->sprite.vec.y = hit.y;
    d->sprite.vec_mid.x = (int)hit.x + 0.5;
    d->sprite.vec_mid.y = (int)hit.y + 0.5;
    d->sprite.dist = calc_dst_vector(d->sprite.vec_mid, d->p.vector);
    d->sprite.diff = sqrt(pow(d->sprite.dist, 2) / pow(calc_dst_vector(d->sprite.vec, d->p.vector), 2));
    d->sprite.number = sprite;
    d->sprite.next = 0;
}

void        display_sprite(t_data *d, t_radar *r, int i)
{
	double 	sprite;
    int     y;
    double  j;
    double width;
    int color;
    j = 0;
    r->dist = fabs(d->sprite.dist * cos(d->p.alpha - r->alpha));
    sprite = fabs((d->r[1]) / d->sprite.dist);
    width = d->sprite.diff;
    y = ((d->r[1] - sprite) / 2) + d->p.angle_visu;
    while (sprite-- > 0)
    {
        color = color_sprite(*r, d, j++, sprite);
        if (color != 0)
            image_set_pixel(&d->img, i, y, color);
        y++;
    }
   // printf("a = %f\n", d->sprite.a) ;
    //printf("b = %f\n", d->sprite.b) ;
}

int         color_sprite(t_radar r, t_data *d, double pixel, int sprite)
{
    int color;
    int i;
    double a;
    double b;

    i = 0;
    // if ((int)sprite > (int)d->r[1] / r.dist)
    //     i = (sprite - d->r[1]) / 2;

//printf("sin = %f \n cos = %f\n", sin(r.alpha), cos(r.alpha));
    // if (sin(r.alpha) > 0 && cos(r.alpha) > 0 )
    //     color = image_get_pixel(&d->texture.sp, (fabs(d->sprite.vec.x - (int)d->sprite.vec.x - 1)) * (d->texture.sp.width), ((pixel + i) / sprite) * d->texture.sp.height);
    // else 
    if ( (a = d->sprite.vec.x - (int)d->sprite.vec.x) > d->sprite.a)
        d->sprite.a = a;
    if ((b = d->sprite.vec.y - (int)d->sprite.vec.y) > d->sprite.b)
        d->sprite.b = b;
    if (sin(r.alpha) > 0)
        color = image_get_pixel(&d->texture.sp, a * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height); 
    else if (cos(r.alpha) > 0)
        color = image_get_pixel(&d->texture.sp, b * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height); 
    else if (cos(r.alpha) > sin(r.alpha))
        color = image_get_pixel(&d->texture.sp, fabs(d->sprite.a + d->sprite.b) * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height);
    else
        color = image_get_pixel(&d->texture.sp, fabs(d->sprite.a - d->sprite.b) * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height);
    if (color == -16777216)
        color = 0;
    return (color);
}