/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:30:50 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			num_p2(t_data *d, int j, int h)
{
	if (d->map->tab_map[j][h] == 'N' || d->map->tab_map[j][h] == 'S' ||
			d->map->tab_map[j][h] == 'E' || d->map->tab_map[j][h] == 'W')
	{
		d->p->vector = ft_calloc(sizeof(t_vector), 1);
		d->p->vector->y = j;
		d->p->vector->x = h;
		if (d->map->tab_map[j][h] == 'N')
			d->p->alpha = M_PI_2;
		if (d->map->tab_map[j][h] == 'S')
			d->p->alpha = M_PI_2 * 3;
		if (d->map->tab_map[j][h] == 'E')
			d->p->alpha = 0;
		if (d->map->tab_map[j][h] == 'W')
			d->p->alpha = M_PI;
		return (1);
	}
	return (0);
}

int			num_p(t_data *d, t_map *map)
{
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	while (d->map->tab_map[j])
	{
		h = 0;
		while (d->map->tab_map[j][h])
		{
			if (num_p2(d, j, h) == 1)
				i++;
			h++;
		}
		j++;
	}
	if (i < 1)
		ft_error(ERROR_P_NO_POS, d);
	if (i > 1)
		ft_error(ERROR_P_EX_POS, d);
	return (i);
}

int			check_texture(char *str, t_texture *texture, t_data *d)
{
	int		i;

	i = 0;
	if (texture->bit_texture < 255)
	{
		parsing_texture(str, texture);
		return (1);
	}
	if (*str == '1')
	{
		i = 1;
		map_str(str, d->map);
		return (1);
	}
	if (!i)
		return (1);
	return (0);
}

void		parsing(char *doc_map, t_data *d)
{
	char		*line;
	int			fd;

	if (!doc_map)
		ft_error(ERROR_NO_FILE, NULL);
	d->texture = calloc(sizeof(t_texture), 1);
	d->m = calloc(sizeof(t_move), 1);
	init_struct(d);
	fd = open(doc_map, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		check_texture(line, d->texture, d);
		free(line);
	}
	check_texture(line, d->texture, d);
	free(line);
	if (d->texture->bit_texture < 255)
		ft_error(ERROR_texture, d);
	full_map(d->map);
	check_map(d);
	num_p(d, d->map);
}
