/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:20:16 by thgermai          #+#    #+#             */
/*   Updated: 2020/04/20 20:18:52 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	moving_bits(unsigned char *str, int value)
{
	str[0] = (unsigned char)(value);
	str[1] = (unsigned char)(value >> 8);
	str[2] = (unsigned char)(value >> 16);
	str[3] = (unsigned char)(value >> 24);
}

void	header(t_data *d, int fd)
{
	unsigned char		header[14];
	int					size;

	size = 3 * (d->r[0] * d->r[1]);
	ft_memset(&header, 0, 14);
	header[0] = 'B';
	header[1] = 'M';
	moving_bits(&header[2], size + 40 + 14);
	header[10] = 54;
	write(fd, header, 14);
}

void	image_header(t_data *d, int fd)
{
	unsigned char	header[40];

	ft_memset(&header, 0, 40);
	header[0] = 40;
	moving_bits(&header[4], d->r[0]);
	moving_bits(&header[8], d->r[1]);
	header[12] = 1;
	header[14] = 24;
	header[20] = 3 * (d->r[0] * d->r[1]);
	write(fd, header, 40);
}

void	image(t_data *d, int fd)
{
	int					j;
	int					i;
	int					color;
	int					(*array)[d->r[0]][1];
	unsigned char		pad[3];

	array = (void *)d->img.buffer;
	ft_memset(&pad, 0, 3);
	j = d->r[1];
	while (--j >= 0)
	{
		i = -1;
		while (++i < d->r[0])
		{
			color = *array[j][i];
			write(fd, &color, 3);
		}
		i = -1;
		while (++i < (4 - (d->r[0] * 3) % 4) % 4)
			write(fd, &pad, 3);
	}
}

void	get_image(t_data *d)
{
	int		fd;

	if ((fd = open("image.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
        ft_error("Error can't be print", d, 1);
	header(d, fd);
	image_header(d, fd);
	image(d, fd);
	close(fd);
}