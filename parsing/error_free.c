/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/29 22:21:57 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_map(char *str, t_data *d)
{
	int j;

	j = 0;
	while (d->map.tab_map[j])
		free(d->map.tab_map[j++]);
	ft_error(str, d, 1);
}

void		*ft_error(char *str, t_data *d, int i)
{
	write(2, "error\n", 6);
	write(2, str, ft_strlen(str) + 1);
	free(d->ptr);
	exit(0);
}

void		clear_lstmap(t_lmap *map)
{
	t_lmap	*lst;
	void	*p;

	lst = map;
	while (lst->next != 0)
	{
		while (lst->next->next != 0)
			lst = lst->next;
		free(lst->next);
		lst->next = 0;
		lst = map;
	}
	free(map);
}