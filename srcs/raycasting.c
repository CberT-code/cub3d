/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/24 18:01:57 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_wall(t_data *d, t_radar r, int i)
{
	int     top;
	double 	wall;
    int     y;
    int     color;

	y = d->p->angle_visu;
    wall = (d->r[1] / 1.5) / r.dist;
	top = ((d->r[1] - wall) / 2) + d->p->angle_visu;
	while (top-- > 0)
        image_set_pixel(d->img, i, y++, 0x5555FF);
	while (wall-- > 0)
    {
        color = color_wall(r, d);
        image_set_pixel(d->img, i, y++, color);
    }
	while (y < d->r[1])
        image_set_pixel(d->img, i, y++, 0x005500);
}

int         color_wall(t_radar r, t_data *d)
{
    if (r.touch == 0 && sin(r.alpha) > 0)
            return (d->texture->c);
        else if (r.touch == 0)
            return (0x00FFFF);
        else if (cos(r.alpha) > 0)
            return (d->texture->f);
        else
            return (0xF0FF00);
}