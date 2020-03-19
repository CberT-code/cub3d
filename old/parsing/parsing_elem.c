/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:43:13 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 01:30:20 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			fill_int(int bit, char *str, int *tab, short *bit_elem)
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
	*bit_elem = *bit_elem | (1 << bit);
	return (i);
}

int			fill_int_rgb(int bit, char *str, int *tab, short *bit_elem)
{
	int		i;

	i = -1;
	while (i++ < 2)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str))
		{
			tab[i] = ft_atoi(str);
			if ((tab[i] > 255) || (tab[i] < 0))
				return (-1);
		}
		else
			return (-1);
		while (ft_isdigit(*str))
			str++;
		if (*str == ',')
			str++;
	}
	*bit_elem = *bit_elem | (1 << bit);
	return (i);
}

void		fill_str(int bit, char *str, t_elem *elem)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	temp = str + i;
	j = ft_strlen(temp);
	if (!(elem->texture[bit] = malloc((sizeof(char) * j) + 1)))
		return ;
	elem->bit_elem = elem->bit_elem | (1 << bit);
	j = 0;
	while (temp[j])
	{
		elem->texture[bit][j] = temp[j];
		j++;
	}
	elem->texture[bit][j] = '\0';
}

void		parsing_elem(char *str, t_elem *elem)
{
	while (*str == ' ')
		str++;
	if (ft_start_str("NO ", str) > 0)
		fill_str(0, str + 3, elem);
	if (ft_start_str("SO ", str) > 0)
		fill_str(1, str + 3, elem);
	if (ft_start_str("WE ", str) > 0)
		fill_str(2, str + 3, elem);
	if (ft_start_str("EA ", str) > 0)
		fill_str(3, str + 3, elem);
	if (ft_start_str("S ", str) > 0)
		fill_str(4, str + 2, elem);
	if (ft_start_str("F ", str) > 0)
		fill_int_rgb(5, str + 2, elem->f, &(elem->bit_elem));
	if (ft_start_str("C ", str) > 0)
		fill_int_rgb(6, str + 2, elem->c, &(elem->bit_elem));
	if (ft_start_str("R ", str) > 0)
		fill_int(7, str + 2, elem->r, &(elem->bit_elem));
}
