/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 23:24:56 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 00:00:24 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			calc_dst_vector(t_vector *vector, int actual_x, int actual_y)
{
	int dst;

	dst = sqrt(pow(vector->x - actual_x, 2) + pow(vector->y - actual_y, 2));
	return (dst);
}

void		check_wall(t_data *d, t_vector *target, int radius)
{
	t_map		*map;
	t_vector	*actual;
	int			t_case;

	map = d->map;
	actual = d->p->vector;
	t_case = d->mini->t_case;
	if (map->tab_map[((int)target->y - 1) / t_case][((int)actual->x) / t_case] == '1')
		actual->y--;
	if (map->tab_map[((int)actual->y - radius) / t_case]
	[((int)actual->x) / t_case] == '1')
		actual->y++;
	if (map->tab_map[(int)actual->y / t_case][((int)actual->x - radius) / t_case] == '1')
		actual->x++;
	if (map->tab_map[((int)actual->y - radius) / t_case]
	[((int)target->x - 1) / t_case] == '1')
		actual->x--;
}

void		draw_circle(int ligne, t_image *img, t_data *d, int radius)
{
	t_vector		target;
	t_vector		actual;

	target.x = d->mini->vector->x + radius;
	target.y = d->mini->vector->y + radius;
	actual.x = d->mini->vector->x - radius;
	check_wall(d, &target, radius);
	while (actual.x <= target.x)
	{
		actual.y = d->mini->vector->y - radius;
		while (actual.y <= target.y)
		{
			if (calc_dst_vector(d->mini->vector, (int)actual.x, (int)actual.y) < radius)
				img->buffer[(int)actual.x + ((int)actual.y * ligne)] = (int)0x318CE7;
			actual.y++;
		}
		actual.x++;
	}
}
