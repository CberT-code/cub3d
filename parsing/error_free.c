/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/26 20:20:48 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void		free_texture(t_data *d)
// {
// 	int i;

// 	i = 0;
// 	free(d->map);
// 	free(d->p);
// 	free(d->texture);
// }

void		*ft_error_map(char *str, t_data *d, int i)
{
	int j;

	j = 0;
	ft_printf(str);
	if (i >= 3)
	{
		while (d->map.tab_map[j])
			free(d->map.tab_map[j++]);
	}
	//free_texture(d);
	exit(0);
}

void		*ft_error(char *str, t_data *d)
{
	ft_printf(str);
	//free_texture(d);
	exit(0);
}