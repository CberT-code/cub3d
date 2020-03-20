/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:24:01 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/27 17:16:13 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		click_mouse(int key)
{
	char  i;

	i = key + '0';
	write(1, &i, 1);
	return (0);
}

int		destroy(t_data *d)
{
	ft_error_map("Exit\n", d, 3); 
	return (0);
}

int		refresh_img(t_data *d)
{
	mlx_destroy_image(d->ptr, d->img->image);
	mlx_destroy_image(d->ptr, d->p->img->image);
	browse_column(d);
	display_p(d, d->map, d->mini->t_case);
	
	return (0);
}

int		move(t_data *d)
{
	int i;

	i = VITESSE * 10;
	while (i--)
	{
		d->p->move = 0;
		if (d->m->move_up == 1)
			d->p->move += 1;
		if (d->m->move_right == 1)
			d->p->move += 2;
		if (d->m->move_down == 1)
			d->p->move += 4;
		if (d->m->move_left == 1)
			d->p->move += 8;
		if (d->m->watch_right == 1)
			d->p->alpha += VITESSEROTATION;
		if (d->m->watch_left == 1)
			d->p->alpha -= VITESSEROTATION;
		if (d->mini->display == 0)
			refresh_img(d);
	}
	return (0);
}

int	key_press(int key, t_data *d)
{
	printf("key = %d\n", key);
	if (key == 13)
		d->m->move_up = 1;
	if (key == 0)
		d->m->move_left = 1;
	if (key == 1)
		d->m->move_down = 1;
	if (key == 2)
		d->m->move_right = 1;
	if (key == 123)
		d->m->watch_right = 1;
	if (key == 124)
		d->m->watch_left = 1;
	if (key == 46)
	{
		d->mini->display = !d->mini->display;
		if (d->mini->display == 1)
			mlx_destroy_image(d->ptr, d->p->img->image);
	}
	if (key == 53)
		destroy(d);
	move(d);
	return (0);
}

int		key_release(int key, t_data *d)
{
	if (key == 13)
		d->m->move_up = 0;
	if (key == 0)
		d->m->move_left = 0;
	if (key == 1)
		d->m->move_down = 0;
	if (key == 2)
		d->m->move_right = 0;
	if (key == 123)
		d->m->watch_right = 0;
	if (key == 124)
		d->m->watch_left = 0;
	if (key == 53)
		destroy(d);
	return (0);
}

int		loop_game(t_data *d)
{
	mlx_hook(d->win, 17, 0, destroy, d);
	mlx_hook(d->win, 2, 0, key_press, d);
	mlx_hook(d->win, 3, 0, key_release, d);
	return (0);
}

int main(int argc, char **argv)
{
	t_data			d;
	unsigned int	c;

	if (argc != 2)
		return (ft_printf("cc\n"));
	parsing(argv[1], &d);
	d.ptr = mlx_init();
	d.win = mlx_new_window(d.ptr, d.texture->r[0], d.texture->r[1], "CUB3D");
	mini_map(&d, d.texture);
	browse_column(&d);
	display_p(&d, d.map, d.mini->t_case);
	mlx_loop_hook(d.ptr, loop_game, &d);
	mlx_loop(d.ptr);
}