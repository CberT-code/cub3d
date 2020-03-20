/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:46:48 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/27 18:26:15 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		display_raycast(t_data *d, double vec, int i, unsigned int color)
{
	t_column col;
	int ind;

	ind = 0;
	col.wall = fabs(vec * sin(30) * 20);
	col.top = (d->texture->r[1] - col.wall) / 2;
	col.bottom = col.top;
	while (col.top > ind)
	{
		d->img->buffer[ind * d->texture->r[0] + i] = d->texture->c;
		ind++;
	}
	while ((col.wall + col.top) > ind)
	{
		d->img->buffer[ind * d->texture->r[0] + i] = color;
		ind++;
	}
	while ((col.wall + col.top + col.bottom) > ind)
	{
		d->img->buffer[ind * d->texture->r[0] + i] = d->texture->f;
		ind++;
	}

}


void		init_radar_r(t_radar *r, t_data *d)
{
	r->y = (double)d->p->vector->y + 0.5;
	r->x = (double)d->p->vector->x + 0.5;
	r->t = (double)tan(r->alpha);
	r->b = r->y - r->t * r->x;
	r->width = d->texture->r[1];
}

double			calc_vector_x(t_radar *r, t_data *d)
{
	double x;
	double y;
	int pas;
	int i;

	i = 0;
	pas = 20;
	x = r->x;
	y = r->y;
	while (i < 20)
	{
		y = (x + i * cos(r->alpha) * pas) * r->t + r->b;
		i++;
		
	}
	return (r->y - y);
}
/* double			calc_vector_y(t_radar *r, t_data *d)
{
	double x;
	double y;

	x = r->x;
	y = r->y;
	printf("int y = %d\n",(int)y);
	printf("int x = %d\n",(int)x);
	while (d->map->tab_map[(int)y][(int)x] != '1')
	{
		if (r->alpha > M_PI && r->alpha < M_2_PI)
			y += 1;
		else
			y -= 1;
		x = (y - r->b) / r->t;
		printf("y = %f\n", y);
		printf("int y = %d\n",(int)y);
	printf("int x = %d\n",(int)x);
	}
	return (r->x - x);
} */

void		display_column(t_radar *r, t_data *d, int i)
{
	double	vec_x;
	double	vec_y;

	init_radar_r(r, d);

		vec_x = calc_vector_x(r, d);
		//vec_y = calc_vector_y(r, d);

	if (vec_y > vec_x)
	 	vec_x = vec_y;
	//	printf("%f\n", vec_x);
	//display_raycast(d, vec_x, i, 0xffffff);

}

void		init_img_ray(t_data *d)
{
	if (!(d->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	d->img->image = mlx_new_image(d->ptr, d->texture->r[0], d->texture->r[1]);
	d->img->buffer = (int *)mlx_get_data_addr(d->img->image, &d->img->bpp,
	&d->img->size_l, &d->img->endian);
}

void		browse_column(t_data *d)
{
	t_radar			r;
	unsigned int	color;
	int				i;

	i = 0;
	init_img_ray(d);
	r.alpha = d->p->alpha + M_PI / 6;
	//while (r.alpha > d->p->alpha - M_PI / 6)
	//{
		display_column(&r, d, i);
	// 	i++;
	//	r.alpha -= M_PI / 3 / d->texture->r[0];
	//}

	mlx_put_image_to_window(d->ptr, d->win, d->img->image, 0, 0);
}

