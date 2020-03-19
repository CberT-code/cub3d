/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:59:15 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:02:39 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		display_map(t_data *d, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	img = d->mini->img;
	img->image = mlx_new_image(d->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	y = 1;
	while (y <= (map->y_max * t_case))
	{
		x = 1;
		while (x <= (t_case * map->x_max))
		{
			map_color_case(d, y, x, t_case);
			x += t_case;
		}
		y += t_case;
	}
}

void		calcul_vector(t_p *p, t_mini *mini, int t_case)
{
	if (!(mini->vector = ft_calloc(sizeof(t_vector), 1)))
		return ;
	mini->vector->x = (p->vector->x * t_case) + (t_case / 2);
	mini->vector->y = (p->vector->y * t_case) + (t_case / 2);
}

void		init_mini(t_data *d, t_elem *elem, t_mini *mini)
{
	if (!(d->mini = ft_calloc(sizeof(t_mini), 1)))
		return ;
	mini = d->mini;
	if (!(mini->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	mini->t_case = elem->r[0] / 3 / d->map->x_max;
	while ((mini->t_case * d->map->y_max) > (elem->r[0] / 3) ||
		(mini->t_case * d->map->x_max) > (elem->r[1] / 2))
		mini->t_case--;
	d->mini->ligne = mini->t_case * d->map->x_max;
}

void		mini_map(t_data *d, t_elem *elem)
{
	t_mini *mini;

	if (!d->mini)
		init_mini(d, elem, mini);
	mini = d->mini;
	if (mini->t_case < 10)
		printf("Map too big to be displayed %d\n", mini->t_case);
	if (mini->t_case >= 10)
	{
		if (!d->mini->vector)
			calcul_vector(d->p, d->mini, mini->t_case);
		display_map(d, d->map, mini->t_case);
		mlx_put_image_to_window(d->ptr, d->win, mini->img->image, 0, 0);
	}
}

void		display_p(t_data *d, t_map *map, int t_case)
{
	int			x;
	int			y;
	t_image		*img;
	t_mini		*mini;
	int			i;

	y = t_case * map->y_max;
	x = t_case * map->x_max;
	i = y * x;
	mini = d->mini;
	if (!(d->p->img = ft_calloc(sizeof(t_image), 1)))
		return ;
	img = d->p->img;
	img->image = mlx_new_image(d->ptr, x, y);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	while (i--)
		img->buffer[i] = mini->img->buffer[i];
	move_fb(d);
	draw_circle(mini->ligne, d->p->img, d, mini->t_case / 3);
	printf("test\n");
	radar(d);
	mlx_put_image_to_window(d->ptr, d->win, d->p->img->image, 0, 0);
}
