/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:44:07 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/25 14:50:43 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void		check_map2(t_data *d, int j)
{
	int size;
	int	sizeb;

	if (!(ft_checkline(d->map.tab_map[j], "NSEW012")))
		ft_error("ERROR\nWrong symbol in MAP", d, 1);
	size = ft_strlen(d->map.tab_map[j]) - 1;
	if (size > d->map.x_max)
		d->map.x_max = size + 1;
	sizeb = ft_strlen(d->map.tab_map[j - 1]) - 1;
	if (size >= sizeb && (d->map.tab_map[j - 1][sizeb] == '1' &&
	d->map.tab_map[j][size] == '1'))
	{
		while (size > sizeb)
			if (d->map.tab_map[j][sizeb++] != '1')
				ft_error(ERROR_MAP_WALL, d, 1);
	}
	else if (size < sizeb && (d->map.tab_map[j - 1][sizeb] == '1' ||
	d->map.tab_map[j][size] == '1'))
	{
		while (size < sizeb)
			if (d->map.tab_map[j - 1][size++] != '1')
				ft_error(ERROR_MAP_WALL, d, 1);
	}
	else
		ft_error(ERROR_MAP_WALL, d, 1);
}

void		*check_map(t_data *d)
{
	int j;

	j = 0;
	if (!(is_tab_full(d->map.tab_map[j], '1')))
		ft_error(ERROR_MAP_WALL, d, 1);
	while (++j < d->map.line_len + 1)
	{
		if (d->map.tab_map[j][0] != '1')
			ft_error(ERROR_MAP_WALL, d, 1);
		check_map2(d, j);
	}
	if (!(is_tab_full(d->map.tab_map[--j], '1')))
		ft_error(ERROR_MAP_WALL, d, 1);
	d->map.y_max = ++j;
	return (&d->map);
}

void		map_str(char *str, t_map *map, t_data *d)
{
	t_lmap	*line;
	t_lmap	*mouv;

	if (!(line = malloc(sizeof(t_map))))
		ft_error("Error\n MALLOC DIDN'T GO WELL", d, 0);
	line->str = ft_replace(str, ' ', '1');
	line->size = ft_strlen(line->str);
	map->tab_line++;
	line->next = 0;
	if (!map->line)
		map->line = line;
	else
	{
		mouv = map->line;
		while (mouv->next != 0)
		{
			mouv = mouv->next;
		}
		mouv->next = line;
	}
}

void		full_map(t_map *map, t_data *d)
{
	t_lmap	*mouv;
	int		i;

	if (d->map.tab_line < 3)
		ft_error(ERROR_MAP_SMALL, d, 0);
	i = 0;
	if (!(map->tab_map = (char **)malloc(sizeof(char *) * (map->tab_line + 1))))
	{
		clear_lstmap(d->map.line);
		ft_error(ERROR_MALLOC, d, 0);
	}
	mouv = map->line;
	while (mouv->next)
	{
		map->tab_map[i++] = mouv->str;
		mouv = mouv->next;
		map->line_len++;
	}
	map->tab_map[i++] = mouv->str;
	map->tab_map[i] = 0;
}
