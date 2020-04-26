/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 13:57:56 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/26 12:19:37 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			fill_int(int bit, char *str, t_data *d, short *bit_texture)
{
	int		i;

	i = -1;

	while (i++ < 1)
	{
		while (*str == ' ')
			str++;
		if (ft_isdigit(*str))
			d->r[i] = ft_atoi(str);
		else
			ft_error("ERROR\nResolution", d, 0);
		while (ft_isdigit(*str))
			str++;
	}
	d->r[0] = d->r[0] <= WIDTH_MAX? d->r[0] : WIDTH_MAX;
	d->r[1] = d->r[1] <= HEIGHT_MAX ? d->r[1] : HEIGHT_MAX;
	d->r[0] = d->r[0] >= 400 ? d->r[0] : 400;
	d->r[1] = d->r[1] >= 400 ? d->r[1] : 400;
	*bit_texture = *bit_texture | (1 << bit);
	return (i);
}

int			fill_int_rgb(int bit, char *str,
		unsigned int *rgb, t_data *d)
{
	int		tab[3];
	int		i;

	i = -1;
	while (i++ < 2)
	{
		while (*str == ' ')
			str++;
		if (ft_atoi(str) <= 255 && ft_atoi(str) >= 0 && ft_isdigit(*str))
			tab[i] = ft_atoi(str);
		else
			ft_error(ERROR_COLOR, d, 0);
		while (ft_isdigit(*str) || *str == ' ')
			str++;
		if (*str == ',')
			str++;
	}
	tab[0] = (int)pow(256, 2) * tab[0];
	tab[1] = 256 * tab[1];
	*rgb = tab[0] + tab[1] + tab[2];
	d->texture.bit_texture = d->texture.bit_texture | (1 << bit);
	return (i);
}

void		fill_str(int bit, char *str, t_data *d, t_image *img)
{
	int		i;
	char	*temp;
	int		fd;

	i = 0;
	while (str[i] == ' ')
		i++;
	temp = str + i + 2;
	if (ft_strcmp(temp + ft_strlen(temp) - 4, ".xpm"))
		ft_error("Error\nTexture is not an .xpm\n", d, 0);
	temp = ft_strjoin("./textures/", temp);
	if ((fd = open(temp, O_RDONLY)) == -1)
		ft_error("Error\nTexture couldn't be find\n", d, 0);
	close(fd);
	if ((img->image = mlx_xpm_file_to_image(d->ptr, temp,
					&img->width, &img->height)) == NULL)
		ft_error("Error\nTexture to image didn't work\n", d, 0);
	free(temp);
	img->buffer = (int *)mlx_get_data_addr(img->image, &img->bpp,
			&img->size_l, &img->endian);
	d->texture.bit_texture = d->texture.bit_texture | (1 << bit);
}

void		parsing_elem(char *str, t_data *d)
{
	while (*str == ' ')
		str++;
	if (!ft_strncmp("NO ", str, 3) && !(d->texture.bit_texture & (1 << 0)))
		fill_str(0, str + 3, d, &d->texture.no);
	if (!ft_strncmp("SO ", str, 3) && !(d->texture.bit_texture & (1 << 1)))
		fill_str(1, str + 3, d, &d->texture.so);
	if (!ft_strncmp("WE ", str, 3) && !(d->texture.bit_texture & (1 << 2)))
		fill_str(2, str + 3, d, &d->texture.we);
	if (!ft_strncmp("EA ", str, 3) && !(d->texture.bit_texture & (1 << 3)))
		fill_str(3, str + 3, d, &d->texture.ea);
	if (!ft_strncmp("S ", str, 2) && !(d->texture.bit_texture & (1 << 4)))
		fill_str(4, str + 2, d, &d->texture.sp);
	if (!ft_strncmp("F ", str, 2) && !(d->texture.bit_texture & (1 << 5)))
		fill_int_rgb(5, str + 2, &d->texture.f, d);
	if (!ft_strncmp("C ", str, 2) && !(d->texture.bit_texture & (1 << 6)))
		fill_int_rgb(6, str + 2, &d->texture.c, d);
	if (!ft_strncmp("R ", str, 2) && !(d->texture.bit_texture & (1 << 7)))
		fill_int(7, str + 2, d, &(d->texture.bit_texture));
}
