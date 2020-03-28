/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:39:32 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/28 15:39:24 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        init_sprite(t_data *d, char sprite, t_vector hit)
{
    d->texture.sprite.vec.x = hit.x;
    d->texture.sprite.vec.y = hit.y;
    d->texture.sprite.vec_mid.x = (int)hit.x + 0.5;
    d->texture.sprite.vec_mid.y = (int)hit.y + 0.5;
    d->texture.sprite.dist = calc_dst_vector(d->texture.sprite.vec_mid, d->p.vector);
    d->texture.sprite.diff = sqrt(pow(d->texture.sprite.dist, 2) / pow(calc_dst_vector(d->texture.sprite.vec, d->p.vector), 2));
    d->texture.sprite.number = sprite;
    d->texture.sprite.next = 0;
}

void        display_sprite(t_data *d, t_radar *r, int i)
{
    int     top;
	double 	sprite;
    int     y;
    double  j;
    double width;

    j = 0;
	y = d->p.angle_visu;
    r->dist = fabs(d->texture.sprite.dist * cos(fabs(d->p.alpha - r->alpha)));
    sprite = fabs((d->r[1]) / r->dist);
    width = fabs((d->r[0]) / d->texture.sprite.diff);
    if (width * 2 <= d->texture.sp.width)
    {
	top = ((d->r[1] - sprite) / 2) + d->p.angle_visu;
	while (top-- > 0)
        y++;
	while (sprite-- > 0)
        image_set_pixel(&d->img, i, y++, color_sprite(*r, d, j++, fabs((d->r[1]) / r->dist)));
    d->texture.vec.x = d->texture.vec.x < 100 ? d->texture.vec.x + 1 : 0; 
    }
}

int         color_sprite(t_radar r, t_data *d, double pixel, int sprite)
{
    int color;
    int i;
    
    i = 0;
    if ((int)sprite > (int)d->r[1] / r.dist)
        i = (sprite - d->r[1]) / 2;
    if (r.touch == 0 && sin(r.alpha) > 0)
        color = image_get_pixel(&d->texture.sp, (d->texture.sprite.vec.x - (int)d->texture.sprite.vec.x) * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height);
    else
        color = image_get_pixel(&d->texture.sp, (d->texture.sprite.vec.y - (int)d->texture.sprite.vec.y) * d->texture.sp.width, ((pixel + i) / sprite) * d->texture.sp.height);
    return (color);
}