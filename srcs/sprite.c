/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cyrille.bertola@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 14:39:32 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/10 16:35:09 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_sprite(t_data *d, char sprite, t_vector hit, t_radar *r)
{
	d->sprite.vec.x = hit.x;
	d->sprite.vec.y = hit.y;
	d->sprite.vec_mid.x = (int)hit.x + 0.5;
	d->sprite.vec_mid.y = (int)hit.y + 0.5;
	d->sprite.dist = sqrt(calc_dst_vector(d->sprite.vec_mid, d->p.vector));
	d->sprite.number = sprite;
	d->sprite.col = 0;
	d->sprite.next = 0;
	d->sprite.alpha = r->alpha;
}

void		display_sprite(t_data *d, int i)
{
	double	sprite;
	int		y;
	double	j;
	double	width;
	int		color;

	j = 0;

	d->sprite.dist = fabs(d->sprite.dist * cos(d->p.alpha - d->sprite.alpha));
	sprite = d->sprite.dist > 1 ? fabs((d->r[1]) / d->sprite.dist) : d->r[1]; //hauteur
	y = ((d->r[1] - sprite) / 2) + d->p.angle_visu; // placement du sprite
	while (sprite-- > 0)
	{
		color = color_sprite(d, j++, sprite);
		//color = 0xff00ff;

			image_set_pixel(&d->img, i, y, color);
		y++;
	}
	d->sprite.col++;
}

int			color_sprite(t_data *d, double pixel, int sprite)
{
	int		color;

	//printf("%f\n",d->sprite.col / sprite);
	//printf("test 2 = %f\n",(pixel / sprite));
	if (sin(d->sprite.alpha) > 0)
		color = image_get_pixel(&d->texture.sp, (d->sprite.col / sprite) * d->texture.sp.width,
				(pixel / sprite) * d->texture.sp.height);
	// else if (cos(r.alpha) > 0)
	// 	color = image_get_pixel(&d->texture.sp, d->sprite.col / sprite * d->texture.sp.width,
	// 			((pixel + i) / sprite) * d->texture.sp.height);
	// else if (cos(r.alpha) > sin(r.alpha))
	// 	color = image_get_pixel(&d->texture.sp,
	// 			d->sprite.col / sprite * d->texture.sp.width,
	// 			((pixel + i) / sprite) * d->texture.sp.height);
	// else
	// 	color = image_get_pixel(&d->texture.sp,
	// 			d->sprite.col / sprite * d->texture.sp.width,
	// 			((pixel + i) / sprite) * d->texture.sp.height);
	// if (color == -16777216)
	// 	color = 0;
	return (color);
}
