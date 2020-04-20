/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:20:16 by thgermai          #+#    #+#             */
/*   Updated: 2020/04/20 17:17:01 by cbertola         ###   ########.fr       */
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

void	get_file_header(t_data *d, int fd)
{
	unsigned char		file_header[14];
	int					size;

	size = 3 * (d->r[0] * d->r[1]);
	ft_memset(&file_header, 0, 14);
	file_header[0] = 'B';
	file_header[1] = 'M';
	moving_bits(&file_header[2], size + 54);
	file_header[10] = 54;
	write(fd, file_header, 14);
}

void	get_image_header(t_data *d, int fd)
{
	unsigned char	image_header[40];

	ft_memset(&image_header, 0, 40);
	image_header[0] = 40;
	moving_bits(&image_header[4], d->r[0]);
	moving_bits(&image_header[8], d->r[1]);
	image_header[12] = 1;
	image_header[14] = 24;
	image_header[20] = 3 * (d->r[0] * d->r[1]);
	write(fd, image_header, 40);
}

void	get_image_mapping(t_data *d, int fd)
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
    printf("coucou\n");

	if ((fd = open("image.bmp", O_RDWR | O_CREAT, S_IRWXU)) == -1)
        ft_error("Error can't be print", d, 1);
	get_file_header(d, fd);
	get_image_header(d, fd);
	get_image_mapping(d, fd);
	close(fd);
}