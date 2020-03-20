/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:03:38 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_texture(t_data *d)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (d->texture->bit_texture & (1 << i++))
			free(d->texture->texture[i - 1]);
	}
	free(d->texture->texture);
	free(d->map);
	free(d->p);
	free(d->texture);
}

void		*ft_error_map(char *str, t_data *d, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
	{
		while (d->map->tab_map[j])
			free(d->map->tab_map[j++]);
	}
	free_texture(d);
	exit(0);
}

void		*ft_error(char *str, t_data *d)
{
	ft_printf(str);
	if (d->texture != NULL)
		free_texture(d);
	exit(0);
}

void		init_struct(t_data *d)
{
	t_p			*p;
	t_map		*map;
	t_lmap		*line;

	map = ft_calloc(sizeof(t_map), 1);
	p = ft_calloc(sizeof(t_p), 1);
	d->texture->texture = (char **)malloc(sizeof(char *) * 5);
	d->map = map;
	d->p = p;
}
