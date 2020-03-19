/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:45 by cbertola          #+#    #+#             */
/*   Updated: 2020/02/19 19:28:37 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# define CHECKER 255

/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| r | c | f | S | EA| WE| SO| NO|
** 0 -> 4 = char **check
** 5 = int *f
** 6 = int *c
*/

# define ERROR_MAP_N_WALL "Error\nThe wall is open on the north side\n"
# define ERROR_MAP_W_WALL "Error\nThe wall is open on the west side\n"
# define ERROR_MAP_E_WALL "Error\nThe wall is open on the east side\n"
# define ERROR_MAP_S_WALL "Error\nThe wall is open on the south side\n"
# define ERROR_MAP_NO "Error\nNO MAP FOUND\n"
# define ERROR_MAP "Error\n MAP\n"
# define ERROR_P_NO_POS "Error\nNO p POSITION FOUND\n"
# define ERROR_P_EX_POS "Error\nTOO MANY p POSITION FOUND\n"
# define ERROR_NO_FILE "Error\nNO FILE FOUND\n"
# define ERROR_ELEM "Error\nELEMENT IS MISSING\n"
# define VITESSE 0.4
# define VITESSEROTATION 0.05

typedef struct			s_key
{
	int					key;
	struct s_key		*next;
}						t_key;

typedef struct			s_move
{
	int					move_up;
	int					move_down;
	int					move_left;
	int					move_right;
	int					watch_right;
	int					watch_left;
}						t_move;

typedef struct			s_coord
{
	int					y;
	int					x;
}						t_coord;

typedef struct			s_lmap
{
	int					size;
	char				*str;
	struct s_lmap		*next;
}						t_lmap;

typedef struct			s_image
{
	void				*image;
	int					height;
	int					width;
	int					bpp;
	int					size_l;
	int					endian;
	int					*buffer;
}						t_image;

typedef struct			s_map
{
	char				**tab_map;
	t_lmap				*line;
	int					tab_line;
	int					line_len;
	int					x_max;
	int					y_max;
}						t_map;

typedef struct			s_player
{
	t_coord				*coord;
	t_image				*img;
	double				alpha;
	double				move;
}						t_p;

typedef struct			s_elem
{
	short				bit_elem;
	char				**texture;
	int					r[2];
	int					f[3];
	int					c[3];
}						t_elem;

typedef struct			s_mini
{
	t_image				*img;
	int					t_case;
	int					ligne;
	int					display;
	t_coord				*coord;
}						t_mini;

typedef struct			s_data
{
	void				*ptr;
	void				*win;
	t_elem				*elem;
	t_image				*img;
	t_mini				*mini;
	t_map				*map;
	t_p					*p;
	t_move				*m;
}						t_data;

typedef struct			s_radar
{
	double				b;
	double				y;
	double				x;
	double				t;
	double				alpha;
	double				width;
	double				dist;
	int					inc;
}						t_radar;

typedef struct			s_vector
{
	double				y;
	double				x;
}						t_vector;

/* 
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/

int						num_p(t_data *d, t_map *map);
int						num_p2(t_data *d, int j, int h);
int						fill_int(int bit, char *str, int *tab, short *bit_elem);
int						fill_int_rgb(int bit, char *str, int *tab,
						short *bit_elem);
int						check_elem(char *str, t_elem *elem, t_data *d);
int						calc_dst_vector(t_coord *coord, int actual_x,
						int actual_y);
void					full_map(t_map *map);
void					fill_str(int bit, char *str, t_elem *elem);
void					parsing_elem(char *str, t_elem *elem);
void					init_struct(t_data *d);
void					free_elem(t_data *d);
void					*ft_error_map(char *str, t_data *d, int i);
void					*ft_error(char *str, t_data *d);
void					*check_map(t_data *d);
void					map_str(char *str, t_map *map);
void					*check_map(t_data *d);
void					check_map2(t_data *d, int j);
void					full_map(t_map *map);
void					parsing(char *doc_map, t_data *d);
void					mini_map(t_data *d, t_elem *elem);
void					init_mini(t_data *d, t_elem *elem, t_mini *mini);
void					calcul_coord(t_p *p, t_mini *mini, int t_case);
void					display_map(t_data *d, t_map *map, int t_case);
void					map_color_case(t_data *d, int y, int x, int t_case);
void					color_square(int i, t_mini *mini, int color, int mult);
void					draw_circle(int ligne, t_image *img, t_data *d,
						int radius);
void					display_p(t_data *d, t_map *map, int t_case);
void					vision(t_data *d);
void					init_radar(t_radar *r, t_data *d);
void					radar(t_data *d);
void					browse_column(t_data *d);
void					display_raycast(t_data *d, double vec, int i, unsigned int color);
void					move_fb(t_data *d);
#endif
