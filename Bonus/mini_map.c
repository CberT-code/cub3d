/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:46:15 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/20 16:00:22 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_mini(t_data *d)
{
    t_vector    pos;
	
    pos.x = 10;
    pos.y = 0;

    d->mini->img = new_image(d, d->map->x_max * d->mini->size, d->map->y_max * d->mini->size);
    map_color_case(d);
   //color_square(pos, 10, 0x00FF00, d->mini->img);
    mlx_put_image_to_window(d->ptr, d->win, d->mini->img->image, 0, 0);
}

void		map_color_case(t_data *d)
{
    t_vector    pos;
	
    pos.x = 0;
    pos.y = 0;
  
    while (pos.y < d->map->y_max)
    {
        while (pos.x < d->map->x_max)
        {
	       if (d->map->tab_map[(int)pos.y][(int)pos.x] == '1')
		        color_square(pos, d->mini->size, (int)0xCBC9C8, d->mini->img);
	       else
		        color_square(pos, d->mini->size, (int)0xFFFFFF, d->mini->img);
            pos.x += 1;
        }
        pos.y += 1;
    }
}

void		color_square(t_vector pos, int size, int color, t_image *img)
{
    int x;
    int y;
    
    y = 0;
	while (y < size)
	{
        x = 0;
		while (x < size)
        {
			image_set_pixel(img, x + (pos.x * size), y + (pos.y * size * img->width), color);
            x++;
        }
        y++;
	}
}
