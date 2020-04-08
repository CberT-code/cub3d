/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:44:07 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/08 19:16:41 by cyrillebe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_map2(t_data *d, int j)
{
	int size;

	size = ft_strlen(d->map.tab_map[j]) - 1;
	if (size > d->map.x_max)
		d->map.x_max = size + 1;
	if (size == (ft_strlen(d->map.tab_map[j - 1]) - 1))
	{
		if (d->map.tab_map[j][size] != '1')
			ft_error(ERROR_MAP_E_WALL, d, 1);
	}
	else
	{
		while (size < (ft_strlen(d->map.tab_map[j - 1]) - 1))
			if (d->map.tab_map[j - 1][size++] != '1')
				ft_error(ERROR_MAP_N_WALL, d, 1);
		while (size > (ft_strlen(d->map.tab_map[j - 1]) - 1))
			if (d->map.tab_map[j][size--] != '1')
				ft_error(ERROR_MAP_S_WALL, d, 1);
	}
}

void		*check_map(t_data *d)
{
	int j;

	j = 0;
	if (!(is_tab_full(d->map.tab_map[j], '1')))
		ft_error(ERROR_MAP_N_WALL, d, 1);
	while (++j < d->map.line_len)
	{
		if (d->map.tab_map[j][0] != '1')
			ft_error(ERROR_MAP_W_WALL, d, 1);
		check_map2(d, j);
	}
	if (!(is_tab_full(d->map.tab_map[j], '1')))
		ft_error(ERROR_MAP_S_WALL, d, 1);
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
