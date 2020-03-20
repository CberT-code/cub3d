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

// int		click_mouse(int key)
// {
// 	char  i;
// 	i = key + ‘0’;
// 	write(1, &i, 1);
// 	return (0);
// }
int		destroy(t_data *d)
{
	ft_error_map("Exit\n", d, 3);
	return (0);
}
// int		refresh_img(t_data *d)
// {
// 	mlx_destroy_image(d->ptr, d->img->image);
// 	mlx_destroy_image(d->ptr, d->p->img->image);
// 	browse_column(d);
// 	display_p(d, d->map, d->mini->t_case);
// 	return (0);
// }

int	key_press(int key, t_data *d)
{
	printf("key = %d\n", key);
	if (key == K_W)
		d->m->move_up = 1;				//ici il faudra faire une fonction move_straight
	if (key == K_A)
		d->m->move_left = 1;
	if (key == K_S)
		d->m->move_down = 1;			//move_straight
	if (key == K_D)
		d->m->move_right = 1;			//move_side
	if (key == K_RIGHT)
		d->m->watch_right += VITESSEROTATION;			//d->p->alpha += d->p->vit_rot
	if (key == K_LEFT)
		d->m->watch_left -= VITESSEROTATION;			//d->p->alpha += d->p->vit_rot
	if (key == 46)					//je sais pas ce que cest celui la (je lai pas dans ma liste)
	{
		d->mini->display = !d->mini->display;
		if (d->mini->display == 1)
			mlx_destroy_image(d->ptr, d->p->img->image);
	}
	if (key == K_ESC)
	 	destroy(d);
	printf("player position : x %f, y %f, alpha %f\n", d.p->vector->x, d.p->vector->y, d.p->alpha);
	// move(d);							//ici ca sera update_game
	return (0);
}
int		key_release(int key, t_data *d)
{
	if (key == K_W)
		d->m->move_up = 0;
	if (key == K_A)
		d->m->move_left = 0;
	if (key == K_S)
		d->m->move_down = 0;
	if (key == K_D)
		d->m->move_right = 0;
	if (key == K_RIGHT)
		d->m->watch_right = 0;
	if (key == K_LEFT)
		d->m->watch_left = 0;
	if (key == K_ESC)
		destroy(d);
	return (0);
}
int		loop_game(t_data *d)
{
	mlx_hook(d->win, 17, 0, destroy, d);
	mlx_hook(d->win, 2, 0, key_press, d);
	//mlx_hook(d->win, 3, 0, key_release, d);
	return (0);
}
int main(int argc, char **argv)
{
	t_data			d;
	if (argc < 2)
		return (ft_printf("Error Missing Map\n"));
	parsing(argv[1], &d);
	// int i;
	// i = 0;
	//while (d.map->tab_map[i])
	//	printf(“tab map = %s\n”, d.map->tab_map[i++]);
	d.ptr = mlx_init();
	d.win = mlx_new_window(d.ptr, d.r[0], d.r[1], "CUB3D");
	mlx_loop_hook(d.ptr, loop_game, &d);
	mlx_loop(d.ptr);
}