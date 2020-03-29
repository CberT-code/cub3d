/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/29 19:07:12 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//  void		free_texture(t_data *d)
//  {
// 	int i;

// 	i = 0;
// 	free(d->map);
// 	free(d->p);
// 	free(d->texture);
// }

void		*free_map(char *str, t_data *d, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
		while (d->map.tab_map[j])
			free(d->map.tab_map[j++]);
	exit(0);
}

void		*ft_error(char *str, t_data *d)
{
	ft_printf(str);
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