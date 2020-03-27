/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:24:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/27 16:00:23 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		destroy(t_data *d)
{
	ft_error_map("Exit\n", d, 3);
	return (0);
}
 int		refresh_img(t_data *d)
{
// 	mlx_destroy_image(d.ptr, d.img.image);
// 	mlx_destroy_image(d.ptr, d.p.img.image);
	radar(d);
 if (d->mini.display == 0)
 	display_mini(d);
//mlx_put_image_to_window(d.ptr, d.win, d.texture.no.image, 0, 0);
//printf("img = %d\n", d.texture.no.width );
// if (d.mini.display == 1)
// 	mlx_destroy_image(d.ptr, d.mini.img.image);
 	return (0);
}

int	key_press(int key, t_data *d)
{
	printf("key = %d\n", key);
	if (key == K_W)
		move_fb(d, 1);
	if (key == K_A)
		move_lr(d, 1);
	if (key == K_S)
		move_fb(d, -1);
	if (key == K_D)
		move_lr(d, -1);			//move_side
	if (key == K_UP)
		d->p.angle_visu += d->p.angle_visu < d->r[1] / 3 ? 10 : 0;			//move_side
	if (key == K_DOWN)
		d->p.angle_visu -= d->p.angle_visu > -d->r[1] / 3 ? 10 : 0;				//move_side
	if (key == K_RIGHT)
		d->p.alpha += d->p.vitesse_rot;
	if (key == K_LEFT)
		d->p.alpha -= d->p.vitesse_rot;
	if (key == K_M)					//je sais pas ce que cest celui la (je lai pas dans ma liste)
		d->mini.display = !d->mini.display;
	if (key == K_ESC)
	 	destroy(d);
	refresh_img(d);//ici ca sera update_game
	return (0);
}

int		loop_game(t_data *d)
{
	mlx_hook(d->win, 17, 0, destroy, d);
	mlx_hook(d->win, 2, 0, key_press, d);
	//mlx_hook(d.win, 3, 0, key_release, d);
	return (0);
}

int main(int argc, char **argv)
{
	t_data			d;
	int				i;

	i = 0;
	ft_bzero(&d, sizeof(t_data));
	if (argc < 2)
		return (ft_printf("Error Missing Map\n"));
	d.ptr = mlx_init();
	parsing(argv[1], &d);
	d.win = mlx_new_window(d.ptr, d.r[0], d.r[1], "CUB3D");
	d.img = new_image(&d, d.r[0], d.r[1]);
	d.mini.img = new_image(&d, d.map.x_max * d.mini.size, d.map.y_max * d.mini.size);
	refresh_img(&d);
	mlx_loop_hook(d.ptr, loop_game, &d);
	mlx_loop(d.ptr);
}