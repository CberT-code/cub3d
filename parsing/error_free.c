/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 19:46:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/08 19:17:06 by cyrillebe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		free_map(t_data *d)
{
	int j;

	j = 0;
	while (d->map.tab_map[j])
		free(d->map.tab_map[j++]);
}

void		free_texture(t_data *d)
{
	if (d->texture.bit_texture & (1 << 0))
		mlx_destroy_image(d->ptr, d->texture.no.image);
	if (d->texture.bit_texture & (1 << 1))
		mlx_destroy_image(d->ptr, d->texture.so.image);
	if (d->texture.bit_texture & (1 << 2))
		mlx_destroy_image(d->ptr, d->texture.we.image);
	if (d->texture.bit_texture & (1 << 3))
		mlx_destroy_image(d->ptr, d->texture.ea.image);
	if (d->texture.bit_texture & (1 << 4))
		mlx_destroy_image(d->ptr, d->texture.sp.image);
}

void		*ft_error(char *str, t_data *d, int i)
{
	if (i >= 5)
		del_image(d, d->mini.img);
	if (i >= 4)
		del_image(d, d->img);
	if (i >= 3)
		mlx_destroy_image(d->ptr, d->img.image);
	if (i >= 2)
		mlx_destroy_window(d->ptr, d->win);
	if (i >= 1)
		free_map(d);
	free_texture(d);
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
