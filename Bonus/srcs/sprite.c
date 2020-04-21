/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:39:32 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/20 16:25:34 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_sprite(t_data *d, char type, t_vector hit, t_radar *r)
{
	t_sprite	sprite;
	int			i;

	i = 0;
	sprite.vec.x = hit.x;
	sprite.vec.y = hit.y;
	sprite.vec_mid.x = (int)hit.x + 0.5;
	sprite.vec_mid.y = (int)hit.y + 0.5;
	sprite.dist = sqrt(calc_dst_vector(sprite.vec_mid, d->p.vector));
	sprite.type = type;
	sprite.next = 0;
	sprite.alpha = r->alpha;
	if (sprite.alpha > (M_PI * 2))
		sprite.alpha -= M_PI * 2;
	if (sprite.alpha < 0)
		sprite.alpha += M_PI * 2;
	sprite.touch = r->touch;
	while (d->tab_s[i].dist != 0)
		i++;
	d->tab_s[i] = sprite;
}

void		display_sprite(t_data *d, int i)
{
	int		k;
	int		y;
	double	j;
	int		color;
	double	dist;

	k = 0;
	while (d->tab_s[k].dist != 0)
		k++;
	while (--k >= 0)
	{
		j = 0;
		dist = d->r[1] / d->tab_s[k].dist;
		y = ((d->r[1] - dist) / 2) + d->p.angle_visu;
		while (dist-- > 0)
		{
			color = color_sprite(d, j++, d->tab_s[k]);
			if (color > 0x000000 && color < 0xFFFFFF)
				image_set_pixel(&d->img, i, y, color);
			y++;
		}
		d->tab_s[k].dist = 0;
	}
}

int			color_sprite(t_data *d, double pixel, t_sprite sprite)
{
	int		color;
	double	diffx;
	double	diffy;
	float	inter;

	diffx = (sprite.vec.x - (int)sprite.vec.x);
	diffy = (sprite.vec.y - (int)sprite.vec.y);
	if (sprite.alpha <= M_PI_2)
		inter = (sprite.touch == 0 ? cos(sprite.alpha) +
		diffx * sin(sprite.alpha) : diffy * cos(sprite.alpha));
	else if (sprite.alpha > M_PI_2 && sprite.alpha <= M_PI)
		inter = (sprite.touch == 0 ? sin(sprite.alpha) * diffx :
		sin(sprite.alpha) - (1 - diffy) * cos(sprite.alpha));
	else if (sprite.alpha > M_PI && sprite.alpha <= 3 * M_PI_2)
		inter = (sprite.touch == 0 ? 1 + sin(sprite.alpha) * diffx :
		1 + (sin(sprite.alpha) + diffy * cos(sprite.alpha)));
	else
		inter = (sprite.touch == 0 ? sin(sprite.alpha) * (diffx - 1) :
		-sin(sprite.alpha) + diffy * cos(sprite.alpha));
	color = image_get_pixel(&d->texture.sp, inter * d->texture.sp.width,
	pixel / (d->r[1] / sprite.dist) * d->texture.sp.height);
	return (color);
}
