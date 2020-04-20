/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:39:31 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/20 16:16:09 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			num_p2(t_data *d, int j, int h)
{
	if (d->map.tab_map[j][h] == 'N' || d->map.tab_map[j][h] == 'S' ||
			d->map.tab_map[j][h] == 'E' || d->map.tab_map[j][h] == 'W')
	{
		d->p.vector.y = j + 0.5;
		d->p.vector.x = h + 0.5;
		if (d->map.tab_map[j][h] == 'N')
			d->p.alpha = M_PI_2;
		if (d->map.tab_map[j][h] == 'S')
			d->p.alpha = M_PI_2 * 3;
		if (d->map.tab_map[j][h] == 'E')
			d->p.alpha = 0;
		if (d->map.tab_map[j][h] == 'W')
			d->p.alpha = M_PI;
		d->map.tab_map[j][h] = '0';
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
	while (d->map.tab_map[j])
	{
		h = 0;
		while (d->map.tab_map[j][h])
		{
			if (num_p2(d, j, h) == 1)
				i++;
			h++;
		}
		j++;
	}
	if (i < 1)
		ft_error(ERROR_P_NO_POS, d, 0);
	if (i > 1)
		ft_error(ERROR_P_EX_POS, d, 0);
	return (i);
}

int			check_elem(char *str, t_texture *texture, t_data *d)
{
	int		i;

	i = 0;
	if (texture->bit_texture < 255)
	{
		parsing_elem(str, d);
		return (1);
	}
	if (*str == '1' || *str == ' ')
	{
		i = 1;
		map_str(str, &d->map, d);
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

	if (!(d->file = doc_map) || ft_strlen(doc_map) < 4 ||
			ft_strcmp(doc_map + ft_strlen(doc_map) - 4, ".cub"))
		ft_error(ERROR_NO_FILE, NULL, 0);
	init_struct(d);
	if (!(fd = open(doc_map, O_RDONLY)))
		ft_error(ERROR_NOT_OPEN, NULL, 0);
	while (get_next_line(fd, &line) != 0)
	{
		check_elem(line, &d->texture, d);
		free(line);
	}
	check_elem(line, &d->texture, d);
	free(line);
	if (d->texture.bit_texture < 255)
		ft_error(ERROR_TEXTURE, d, 0);
	full_map(&d->map, d);
	clear_lstmap(d->map.line);
	check_map(d);
	num_p(d, &d->map);
}
