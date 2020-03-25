/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/25 18:52:49 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_wall(t_data *d, t_radar *r, int i)
{
	int     top;
	double 	wall;
    int     y;
    int     j;

    j = 0;
	y = d->p->angle_visu;
    r->dist = fabs(r->dist * cos(fabs(d->p->alpha - r->alpha)));
    wall = fabs((d->r[1] / 1.5) / r->dist);
	top = ((d->r[1] - wall) / 2) + d->p->angle_visu;
	while (top-- > 0)
        image_set_pixel(d->img, i, y++, 0x5555FF);
	while (wall-- > 0)
        image_set_pixel(d->img, i, y++, color_wall(*r, d, j++,fabs((d->r[1] / 1.5) / r->dist)));
	while (y < d->r[1])
        image_set_pixel(d->img, i, y++, 0x005500);
    d->texture->vec.x = d->texture->vec.x < 100 ? d->texture->vec.x + 1 : 0; 
}

int         color_wall(t_radar r, t_data *d, int i, int wall)
{
    int color;
    int size_wall;
    size_wall = wall;
   // printf("vecy = %f : vecx = %f\n", vec.x, vec.y);
    if (r.touch == 0 && sin(r.alpha) > 0)
    {
        //color = 0xFF0000;
        //printf("x = %d, y = %d\n", (int)(r.vec.x * size_wall) % size_wall , i % size_wall);
        color = image_get_pixel(d->texture->no, (int)(r.vec.x * size_wall) % size_wall, (i * 2) % d->texture->no->height);
        // d->texture->vec.y = vec.y < d->texture->no->height ? vec.y + 1 : 0; 
    }
    else if (r.touch == 0)
    {
        //color = 0x00FF00;
         color = image_get_pixel(d->texture->so, (int)(r.vec.x * size_wall) % size_wall , i);
        //d->texture->vec.y = vec.y < d->texture->so->height ? vec.y + 1 : 0; 
    }
    else if (r.touch == 1 && cos(r.alpha) > 0)
    {
        //color = 0x0000FF;
        color = image_get_pixel(d->texture->ea,(int)(r.vec.y * size_wall) % size_wall , i);
        // d->texture->vec.y = vec.y < d->texture->ea->height ? vec.y + 1 : 0; 
    }
    else
    {
        //color = 0x000000;
         color = image_get_pixel(d->texture->we, (int)(r.vec.y * size_wall) % size_wall , i);
        // d->texture->vec.y = vec.y < d->texture->we->height ? vec.y + 1 : 0; 
     }
    return (color);
}