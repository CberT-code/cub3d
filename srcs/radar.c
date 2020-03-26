/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/26 20:27:01 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_radar(t_radar *r, t_data *d)
{
	r->vec.y = d->p.vector.y;
	r->vec.x = d->p.vector.x;
	r->t = (double)-tan(r->alpha);
	r->b = r->vec.y - r->t * r->vec.x;
    r->width = d->mini.img.width;
	r->touch = 0;
}

void		radar_mini(t_data *d)
{
	t_radar	r;
    t_vector hit;

	r.alpha = d->p.alpha + M_PI / 6;
	while (r.alpha > d->p.alpha - M_PI / 6)
	{
		init_radar(&r, d);
		while (d->map.tab_map[(int)r.vec.y ][(int)r.vec.x] != '1' && r.width)
		{   
            image_set_pixel(&d->mini.img, r.vec.x * d->mini.size, r.vec.y * d->mini.size, (int)0xFF0000);
            if (r.alpha == M_PI_2)
				r.vec.y = r.vec.y - (sin(r.alpha) / d->mini.size);
			else
			{
				r.vec.x = r.vec.x + (cos(r.alpha) / d->mini.size);
				r.vec.y = r.t * r.vec.x + r.b;
			}
            r.width--;
        }
		r.alpha -= M_PI / 3 / d->r[0];
	}
}

void		radar(t_data *d)
{
	t_radar	r;
    t_vector hit;
    int i;

    i = 0;
	r.alpha = d->p.alpha + M_PI / 6;
	while (r.alpha > d->p.alpha - M_PI / 6)
	{
		r.sprite = 0;
		init_radar(&r, d);
        hit = next_block(r.vec.x, r.vec.y, &d->p.vector);
		while (d->map.tab_map[(int)hit.y][(int)hit.x] != '1')
		{
            r.vec_y = calc_next_y(r);
            r.vec_x = calc_next_x(r);
            if (r.touch != (r.touch = compare_vec(&d->p.vector, r.vec_y, r.vec_x, &r.vec)))
			 {
				  d->texture.vec.x = 0;
				  d->texture.vec.y = 0;
			 }
            hit = next_block(r.vec.x, r.vec.y, &d->p.vector);
			// if (d->map.tab_map[(int)hit.y][(int)hit.x] != '1' && d->map.tab_map[(int)hit.y][(int)hit.x] != '0')
			// 	r.sprite = 1;
        }
        r.dist = sqrt(calc_dst_vector(&d->p.vector, r.vec.x, r.vec.y));
        display_wall(d, &r, i);
		// if (r.sprite == 1)
		// 	sprite();
        i++;
		//printf("coucou %f\n", r.alpha);
		r.alpha -= M_PI / 3 / d->r[0];
	}
    mlx_put_image_to_window(d->ptr, d->win, d->img.image, 0, 0);
}

