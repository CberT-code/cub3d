/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:06:06 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/20 18:57:09 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		display_wall(t_data *d, t_radar *r, int i)
{
	int		top;
	double	wall;
	int		y;
	double	j;

	j = 0;
	r->dist = fabs(r->dist * cos(d->p.alpha - r->alpha));
	wall = d->r[1] / r->dist;
	top = d->p.angle_visu + ((d->r[1] - wall) / 2);
	y = top < 0 ? top : 0;
	while (top-- > 0)
		image_set_pixel(&d->img, i, y++, d->texture.c);
	while (wall-- > 0)
		image_set_pixel(&d->img, i, y++,
				color_wall(*r, d, j++, d->r[1] / r->dist));
	while (y < d->r[1])
		image_set_pixel(&d->img, i, y++, d->texture.f);
}

int			color_wall(t_radar r, t_data *d, double pixel, int wall)
{
	int color;

	if (r.touch == 0 && sin(r.alpha) > 0)
		color = image_get_pixel(&d->texture.no, (r.vec.x - (int)r.vec.x) *
				d->texture.no.width, pixel / wall * d->texture.no.height);
	else if (r.touch == 0)
		color = image_get_pixel(&d->texture.so, (r.vec.x - (int)r.vec.x) *
				d->texture.so.width, pixel / wall * d->texture.so.height);
	else if (r.touch == 1 && cos(r.alpha) > 0)
		color = image_get_pixel(&d->texture.ea, (r.vec.y - (int)r.vec.y) *
				d->texture.ea.width, pixel / wall * d->texture.ea.height);
	else
		color = image_get_pixel(&d->texture.we, (r.vec.y - (int)r.vec.y) *
				d->texture.we.width, pixel / wall * d->texture.we.height);
	return (color);
}
