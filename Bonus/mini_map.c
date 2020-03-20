/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 12:46:15 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/20 13:54:48 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void        display_mini(t_data *d)
{
    map_color_case(d);
    mlx_put_image_to_window(d->ptr, d->win, d->mini->img, 0, 0);
}

void		map_color_case(t_data *d)
{
    t_vector    pos;
	
    pos.x = 0;
    pos.y = 0;
    d->mini->img->width = d->map->x_max * d->mini->size;
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
    t_vector s;
    
    s.y = 0;
	while ((int)s.y < size)
	{
        s.x = 0;
		while ((int)s.x < size)
			img->buffer[((int)pos.x * size) + (int)s.x++ + ((((int)pos.y * size) + (int)s.y) * img->width)] = color;
        s.y++;
	}
}
