/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/26 20:27:34 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_wall(t_data *d, t_radar *r, int i)
{
	int     top;
	double 	wall;
    int     y;
    double     j;

    j = 0;
	y = d->p.angle_visu;
    r->dist = fabs(r->dist * cos(fabs(d->p.alpha - r->alpha)));
    wall = fabs((d->r[1]) / r->dist);
	top = ((d->r[1] - wall) / 2) + d->p.angle_visu;
	while (top-- > 0)
        image_set_pixel(&d->img, i, y++, 0x5555FF);
	while (wall-- > 0)
        image_set_pixel(&d->img, i, y++, color_wall(*r, d, j++, fabs((d->r[1]) / r->dist)));
	while (y < d->r[1])
        image_set_pixel(&d->img, i, y++, 0x005500);
    d->texture.vec.x = d->texture.vec.x < 100 ? d->texture.vec.x + 1 : 0; 
}

int         color_wall(t_radar r, t_data *d, double pixel, int wall)
{
    int color;
    int i;

    i = 0;
    if ((int)wall > (int)d->r[1])
        i = (wall - d->r[1]) / 2;
    if (r.touch == 0 && sin(r.alpha) > 0)
        color = image_get_pixel(&d->texture.no, (r.vec.x - (int)r.vec.x) * d->texture.no.width, ((pixel + i) / wall) * d->texture.no.height);
    else if (r.touch == 0)
         color = image_get_pixel(&d->texture.so, (r.vec.x - (int)r.vec.x) * d->texture.so.width, ((pixel + i) / wall) * d->texture.so.height);
    else if (r.touch == 1 && cos(r.alpha) > 0)
        color = image_get_pixel(&d->texture.ea,(r.vec.y - (int)r.vec.y) * d->texture.ea.width, ((pixel + i) / wall) * d->texture.ea.height);
    else
         color = image_get_pixel(&d->texture.we, (r.vec.y - (int)r.vec.y) * d->texture.we.width, ((pixel + i) / wall) * d->texture.we.height);
    return (color);
}