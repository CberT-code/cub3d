/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:57:56 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/24 19:39:39 by cyrillebert      ###   ########.fr       */
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
	tab[0] = tab[0] <= WIDTH_MAX ? tab[0] : WIDTH_MAX ;
	tab[1] = tab[1] <= HEIGHT_MAX ? tab[1] : HEIGHT_MAX ;
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

int			fill_int_rgb(int bit, char *str, unsigned int *rgb, short *bit_texture)
{
	int		tab[3];
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
	*rgb = tab[0] + tab[1] + tab[2];
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

void		fill_str(int bit, char *str, t_data *d, t_image *text)
{
	int		i;
	int		j;
	char	*temp;
	int fd;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	temp = str + i + 2;
	printf("temp = %s\n", ft_strjoin("./textures/", temp));
		text = malloc(sizeof(t_image));
	if ((fd = open("./textures/tropical.xpm", O_RDONLY)) == -1)
	 	printf("eroor open\n");
	 if ((text->image = mlx_xpm_file_to_image(d->ptr,"./textures/tropical.xpm", &text->width, &text->height)) == NULL)
	 	printf("errooooor\n");
	//text->buffer = (int *)mlx_get_data_addr(text->image, &text->bpp, &text->size_l, &text->endian);
	printf("coucou\n");
	d->texture->bit_texture = d->texture->bit_texture | (1 << bit);
}

void		parsing_elem(char *str, t_data *d)
{
	while (*str == ' ')
		str++;
	if 	(!ft_strncmp("NO ", str, 3))
		fill_str(0, str + 3, d, d->texture->no);
	if (!ft_strncmp("SO ", str, 3))
		fill_str(1, str + 3, d, d->texture->so);
	if (!ft_strncmp("WE ", str, 3))
		fill_str(2, str + 3, d, d->texture->we);
	if (!ft_strncmp("EA ", str, 3))
		fill_str(3, str + 3, d, d->texture->ea);
	if (!ft_strncmp("S ", str, 2))
		fill_str(4, str + 2, d, d->texture->sp);
	if (!ft_strncmp("F ", str, 2))
		fill_int_rgb(5, str + 2, &d->texture->f, &(d->texture->bit_texture));
	if (!ft_strncmp("C ", str, 2))
		fill_int_rgb(6, str + 2, &d->texture->c, &(d->texture->bit_texture));
	if (!ft_strncmp("R ", str, 2))
		fill_int(7, str + 2, d->r, &(d->texture->bit_texture));
}
