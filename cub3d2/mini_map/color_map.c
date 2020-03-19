/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:23:52 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/18 23:46:16 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		color_square(int i, t_mini *mini, int color, int mult)
{
	int x;
	int y;

	y = -1;
	while (++y < mini->t_case - 1)
	{
		x = -1;
		while (++x < mini->t_case - 1)
			mini->img->buffer[i + x + (y * mini->t_case * mult)] = color;
	}
}

void		map_color_case(t_data *d, int y, int x, int t_case)
{
	t_map	*map;
	int		i;
	int		centre_x;
	int		centre_y;

	i = x + (y * (d->map->x_max * t_case));
	map = d->map;
	if (map->tab_map[y / t_case][x / t_case] == '1' ||
			(x / t_case) > ft_strlen(map->tab_map[y / t_case]))
		color_square(i, d->mini, (int)0xCBC9C8, map->x_max);
	else
		color_square(i, d->mini, (int)0xFFFFFF, map->x_max);
}
