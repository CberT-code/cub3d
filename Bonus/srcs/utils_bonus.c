/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:32:10 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/25 13:20:18 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

double		calc_dst_vector(t_vector vector, t_vector actual)
{
	double	dst;

	dst = pow(vector.x - actual.x, 2) + pow(vector.y - actual.y, 2);
	return (dst);
}

void		draw_rect(t_vector pos, t_vector size, int color, t_image *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (x == 0 || y == 0)
				image_set_pixel(img, x + pos.x,
						y + pos.y, (int)0x000000);
			else
				image_set_pixel(img, x + pos.x,
						y + pos.y, color);
			x++;
		}
		y++;
	}
}

void		display_life(t_data *d)
{
	t_vector	size;
	t_vector	pos;

	size.x = d->r[0] / 3;
	size.y = d->r[1] / 20;
	pos.x = (d->r[0] / 2) - (size.x / 2);
	pos.y = d->r[1] / 8 * 7;
	draw_rect(pos, size, 0xFFFFFF, &d->img);
	size.x = d->r[0] / 3 / NUMBERLIFE * d->p.life;
	draw_rect(pos, size, 0xFF0000, &d->img);
}

int			ft_checkline(char *str, char *str2)
{
	int i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str2[j] && str[i] != str2[j])
			j++;
		if (str2[j] != str[i])
			return (0);
		i++;
	}
	return (1);
}
