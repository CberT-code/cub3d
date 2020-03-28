/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:46:15 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/28 12:48:25 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_mini(t_data *d)
{
    t_vector    pos;
	
    pos.x = d->p.vector.x * d->mini.size;
    pos.y = d->p.vector.y * d->mini.size;
    draw_mini(d);
    draw_circle(COLOR_PLAYER, &d->mini.img, pos, d->mini.size/3);
    radar_mini(d);
    mlx_put_image_to_window(d->ptr, d->win, d->mini.img.image, 0, 0);
}

void		draw_mini(t_data *d)
{
    t_vector    pos;
	
    pos.y = 0;
    while (pos.y < d->map.y_max)
    {
        pos.x = 0;
        while (pos.x < d->map.x_max)
        {
	       if (d->map.tab_map[(int)pos.y][(int)pos.x] == '1')
		        draw_square_border(pos, d->mini.size, SQUARE_FULL, &d->mini.img);
	       else
		        draw_square_border(pos, d->mini.size, SQUARE_EMPTY, &d->mini.img);
            pos.x += 1;
        }
        pos.y += 1;
    }
}

void		draw_square_border(t_vector pos, int size, int color, t_image *img)
{
    int x;
    int y;
    
    y = 0;
	while (y < size)
	{
        x = 0;
		while (x < size)
        {
            if (x == 0 || y == 0)
                image_set_pixel(img, x + (pos.x * size), y + (pos.y * size), (int)0x000000);
            else
			    image_set_pixel(img, x + (pos.x * size), y + (pos.y * size), color);
            x++;
        }
        y++;
	}
}

void		draw_circle(int color, t_image *img, t_vector pos, int radius)
{
	t_vector		target;
	t_vector		actual;

	target.x = (int)pos.x + radius;
	target.y = (int)pos.y + radius;
	actual.x = (int)pos.x - radius;
	while (actual.x <= target.x)
	{
		actual.y = (int)pos.y - radius;
		while (actual.y <= target.y)
		{
			if (calc_dst_vector(pos, actual) < radius * radius)
                image_set_pixel(img, actual.x, actual.y, color);
			actual.y++;
		}
		actual.x++;
	}
}