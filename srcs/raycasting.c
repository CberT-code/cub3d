/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/21 17:47:09 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_wall(t_data *d, double vec, int i)
{
	int     top;
	double 	op;
	int		height;
     int     y;

	 y = 0;
    op = (d->r[1] / 1.5) / (int)vec;
    printf("vec = %f\n",vec);
	top = d->r[1] - (op + d->p->height);
    printf("r = %d\n",d->r[1]);
    printf("op = %f\n",op);
    printf("top = %d\n",top);
	while (top > 0)
	{
        image_set_pixel(d->img, i, y++, 0x5555FF);
	 	top--;
    }
	while (op > 0)
    {
        image_set_pixel(d->img, i, y++, 0xFF5500);
	 	op--;
    }
	while (y < d->r[1])
        image_set_pixel(d->img, i, y++, 0x005500);

}

double      calc_wall()
{
    return (0);
}