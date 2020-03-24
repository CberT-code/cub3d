/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/24 16:18:10 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_wall(t_data *d, t_radar r, int i)
{
	int     top;
	double 	wall;
	int		height;
    int     y;

	 y = 0;
    wall = (d->r[1] / 1.5) / (int)r.dist;
    printf("vec = %f\n",r.dist);
	top = d->r[1] - (wall + d->p->height);
    printf("r = %d\n",d->r[1]);
    printf("op = %f\n", wall);
    printf("top = %d\n",top);
	while (top > 0)
	{
        image_set_pixel(d->img, i, y++, 0x5555FF);
	 	top--;
    }
	while (wall > 0)
    {
        image_set_pixel(d->img, i, y++, 0xFF5500);
	 	wall--;
    }
	while (y < d->r[1])
        image_set_pixel(d->img, i, y++, 0x005500);

}

double      calc_wall()
{
    return (0);
}