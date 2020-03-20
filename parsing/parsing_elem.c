/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:43:13 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:30:20 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			fill_int(int bit, char *str, int *tab, short *bit_texture)
{
	int		i;

	i = -1;
	while (i++ < 1)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str))
			tab[i] = ft_atoi(str);
		else
			return (-1);
		while (ft_isdigit(*str))
			str++;
		if (*str == ',')
			str++;
	}
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

int			fill_int_rgb(int bit, char *str, int rgb, short *bit_texture)
{
	int		tab[2];
	int		i;

	i = -1;
	while (i++ < 2)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str) <= 255 && ft_isdigit(*str) >= 0)
			tab[i] = ft_atoi(str);
		else
			ft_error(ERROR_COLOR, NULL);
		while (ft_isdigit(*str))
			str++;
		if (*str == ',')
			str++;
	}
	tab[0] = (int)pow(256, 2) * tab[0];
	tab[1] = 256 * tab[1];
	rgb = tab[0] + tab[1] + tab[2];
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

void		fill_str(int bit, char *str, t_texture *texture, t_image *text)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	temp = str + i;
	text->image = ;
	texture->bit_texture = texture->bit_texture | (1 << bit);
}

void		parsing_texture(char *str, t_data *d)
{
	while (*str == ' ')
		str++;
	if 	(ft_strncmp("NO ", str, 3))
		fill_str(0, str + 3, d->texture, d->texture->no);
	if (ft_strncmp("SO ", str, 3))
		fill_str(1, str + 3, d->texture, d->texture->so);
	if (ft_strncmp("WE ", str, 3))
		fill_str(2, str + 3, d->texture, d->texture->we);
	if (ft_strncmp("EA ", str, 3))
		fill_str(3, str + 3, d->texture, d->texture->ea);
	if (ft_strncmp("S ", str, 3))
		fill_str(4, str + 2, d->texture, d->texture->sp);
	if (ft_strncmp("F ", str))
		fill_int_rgb(5, str + 2, d->texture->f, &(d->texture->bit_texture));
	if (ft_strncmp("C ", str))
		fill_int_rgb(6, str + 2, d->texture->c, &(d->texture->bit_texture));
	if (ft_strncmp("R ", str))
		fill_int(7, str + 2, d->r, &(d->texture->bit_texture));
}
