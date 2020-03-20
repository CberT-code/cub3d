/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:45 by cbertola          #+#    #+#             */
/*   Updated: 2020/03/20 20:15:58 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# define CHECKER 255

/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| r | c ls| f | S | EA| WE| SO| NO|
** 0 -> 4 = char **check
** 5 = int *f
** 6 = int *c
*/

#  define K_ESC			53
#  define K_COMM		12
#  define K_NUM_MULT	67
#  define K_NUM_DIV		75
#  define K_NUM_PLUS	69
#  define K_NUM_MINUS	78
#  define K_NUM_ENTER	76
#  define K_NUM_0		82
#  define K_UP			126
#  define K_DOWN		125
#  define K_LEFT		123
#  define K_RIGHT		124
#  define K_DIGIT_0		29
#  define K_DIGIT_1		18
#  define K_DIGIT_7		26
#  define K_DIGIT_8		28
#  define K_DIGIT_9		25
#  define K_A			0
#  define K_S			1
#  define K_D			2
#  define K_W			13
#  define K_E			14
#  define K_L			37
#  define K_M			46
#  define K_Q			259
#  define K_MINUS		27
#  define K_PLUS		24

# define ERROR_NOT_OPEN "Error\nPROGRAM COULD NOT OPEN THE FILE\n"
# define ERROR_MAP_N_WALL "Error\nThe wall is open on the north side\n"
# define ERROR_MAP_W_WALL "Error\nThe wall is open on the west side\n"
# define ERROR_MAP_E_WALL "Error\nThe wall is open on the east side\n"
# define ERROR_MAP_S_WALL "Error\nThe wall is open on the south side\n"
# define ERROR_MAP_NO "Error\nNO MAP FOUND\n"
# define ERROR_COLOR "Error\nCOLOR DOESNT\n"
# define ERROR_MAP "Error\n MAP\n"
# define ERROR_P_NO_POS "Error\nNO p POSITION FOUND\n"
# define ERROR_P_EX_POS "Error\nTOO MANY p POSITION FOUND\n"
# define ERROR_NO_FILE "Error\nNO FILE FOUND\n"
# define ERROR_TEXTURE "Error\ntextureENT IS MISSING\n"
# define ERROR_CALLOC "Error\ncalloc didn't go well\n"
# define COLOR_PLAYER (int)0x318CE7

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

typedef struct			s_vector
{
	double				y;
	double				x;
	double				dist;
}						t_vector;

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

typedef struct			s_lmap
{
	int					size;
	char				*str;
	struct s_lmap		*next;
}						t_lmap;

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
	t_vector			*vector;
	t_image				*img;
	double				alpha;
	double				move;
	double 				vitesse;
	double				vitesse_rot;
}						t_p;

typedef struct			s_texture
{
	short				bit_texture;
	t_image				*no;
	t_image				*so;
	t_image				*we;
	t_image				*ea;
	t_image				*sp;
	unsigned int		f;
	unsigned int		c;
}						t_texture;

typedef struct			s_mini
{
	t_image				*img;
	int					size;
	int					display;
}						t_mini;

typedef struct			s_data
{
	void				*ptr;
	void				*win;
	int					r[2];
	t_texture			*texture;
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

/* 
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/

int						num_p(t_data *d, t_map *map);
int						num_p2(t_data *d, int j, int h);
int						fill_int(int bit, char *str, int *tab, short *bit_texture);
int						fill_int_rgb(int bit, char *str, unsigned int *rgb, short *bit_texture);
int						check_elem(char *str, t_texture *texture, t_data *d);
void					full_map(t_map *map);
void					fill_str(int bit, char *str, t_texture *texture, t_image *tex);
void					parsing_elem(char *str, t_data *d);
void					init_struct(t_data *d);
void					free_texture(t_data *d);
void					*ft_error_map(char *str, t_data *d, int i);
void					*ft_error(char *str, t_data *d);
void					*check_map(t_data *d);
void					map_str(char *str, t_map *map);
void					*check_map(t_data *d);
void					check_map2(t_data *d, int j);
void					full_map(t_map *map);
void					parsing(char *doc_map, t_data *d);
void					move_fb(t_data *d, int i);
void					move_lr(t_data *d, int i);
void					draw_mini(t_data *d);
void					draw_square(t_vector pos, int size, int color, t_image *img);
void      				display_mini(t_data *d);
t_image					*del_image(t_data *d, t_image *img);
t_image					*new_image(t_data *d, int w, int h);
void					image_set_pixel(t_image *image, int x, int y, int color);
void					draw_circle(int color, t_image *img, t_vector pos, int radius);
double						calc_dst_vector(t_vector *vector, int actual_x, int actual_y);
 int					refresh_img(t_data *d);
 void					radar(t_data *d);
 void					init_radar(t_radar *r, t_data *d);
 t_vector				calc_next_y(t_radar r);
 t_vector				calc_next_x(t_radar r);
#endif

