/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:51:45 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/25 14:51:26 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include "../minilibx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <X11/X.h>
# define CHECKER 255

/*
** | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
** |ind| r | c ls| f | S | EA| WE| SO| NO|
** 0 . 4 = char **check
** 5 = int *f
** 6 = int *c
*/

# define K_ESC				65307
# define K_UP				65362
# define K_DOWN				65364
# define K_LEFT				65361
# define K_RIGHT			65363
# define K_A				97
# define K_S				115
# define K_D				100
# define K_W				119
# define K_M				109
# define WIDTH_MAX			3072
# define HEIGHT_MAX			1920
# define ERROR_NOT_OPEN 	"Error\nProgramme cant open the file\n"
# define ERROR_MAP_SMALL 	"Error\nMAP is too small\n"
# define ERROR_MAP_WALL 	"Error\nThe wall is open\n"
# define ERROR_MAP_NO 		"Error\nNo map found\n"
# define ERROR_COLOR 		"Error\nColor doesnt exist\n"
# define ERROR_MAP 			"Error\nMAP\n"
# define ERROR_P_NO_POS 	"Error\nNo player position found\n"
# define ERROR_P_EX_POS 	"Error\nToo many positions for the player\n"
# define ERROR_NO_FILE 		"Error\nNo file found\n"
# define ERROR_TEXTURE 		"Error\nTexture is missing\n"
# define ERROR_CALLOC 		"Error\nCalloc didn't go well\n"
# define FAIL_TEXTURE 		"Error\nTexture importation failed\n"
# define ERROR_MALLOC 		"Error\nMalloc failed\n"
# define SQUARE_EMPTY		0xFFFFFF
# define SQUARE_FULL		0xCBC9C8
# define COLOR_PLAYER		0x318CE7
# define NUMBERLIFE			5

typedef struct				s_key
{
	int						key;
	struct s_key			*next;
}							t_key;

typedef struct				s_move
{
	int						move_up;
	int						move_down;
	int						move_left;
	int						move_right;
	int						watch_right;
	int						watch_left;
}							t_move;

typedef struct				s_vector
{
	double					y;
	double					x;
	double					dist;
}							t_vector;

typedef struct				s_sprite
{
	t_vector				vec;
	t_vector				vec_mid;
	double					dist;
	char					type;
	double					col;
	double					a;
	double					b;
	double					alpha;
	double					touch;
	struct s_sprite			*next;
}							t_sprite;

typedef struct				s_image
{
	void					*image;
	int						height;
	int						width;
	int						bpp;
	int						size_l;
	int						endian;
	int						*buffer;
}							t_image;

typedef struct				s_lmap
{
	int						size;
	char					*str;
	struct s_lmap			*next;
}							t_lmap;

typedef struct				s_map
{
	char					**tab_map;
	t_lmap					*line;
	int						tab_line;
	int						line_len;
	int						x_max;
	int						y_max;
}							t_map;

typedef struct				s_player
{
	t_vector				vector;
	t_image					img;
	double					alpha;
	int						height;
	double					move;
	double					vitesse;
	double					vitesse_rot;
	int						angle_visu;
	int						life;
}							t_p;

typedef struct				s_texture
{
	short					bit_texture;
	t_image					no;
	t_image					so;
	t_image					we;
	t_image					ea;
	t_image					sp;
	t_vector				vec;
	unsigned int			f;
	unsigned int			c;
}							t_texture;

typedef struct				s_mini
{
	t_image					img;
	int						size;
	int						display;
}							t_mini;

typedef struct				s_data
{
	void					*ptr;
	void					*win;
	int						r[2];
	char					*file;
	t_texture				texture;
	t_image					img;
	t_mini					mini;
	t_map					map;
	t_p						p;
	t_move					m;
	t_sprite				tab_s[40];
}							t_data;

typedef struct				s_radar
{
	double					b;
	double					t;
	double					alpha;
	double					width;
	double					dist;
	int						touch;
	t_vector				vec;
	t_vector				vec_x;
	t_vector				vec_y;
}							t_radar;

/*
** Position :
** 1 = N , 2 = E , 4 = S , 8 = W
*/

int							refresh_img(t_data *d);
int							num_p(t_data *d);
int							num_p2(t_data *d, int j, int h);
int							fill_int(int bit, char *str, t_data *d,
		short *bit_texture);
int							fill_int_rgb(int bit, char *str, unsigned int *rgb,
		t_data *d);
int							check_elem(char *str, t_texture *texture,
		t_data *d);
void						fill_str(int bit, char *str, t_data *d,
		t_image *img);
void						parsing_elem(char *str, t_data *d);
void						init_struct(t_data *d);
void						free_texture(t_data *d);
void						free_map(t_data *d);
void						*ft_error(char *str, t_data *d, int i);
void						*check_map(t_data *d);
void						map_str(char *str, t_map *map, t_data *d);
void						*check_map(t_data *d);
void						check_map2(t_data *d, int j);
void						full_map(t_map *map, t_data *d);
void						parsing(char *doc_map, t_data *d);
void						move_fb(t_data *d, int i);
void						move_lr(t_data *d, int i);
void						draw_mini(t_data *d);
void						draw_square_border(t_vector pos, int size,
		int color, t_image *img);
void						display_mini(t_data *d);
void						del_image(t_data *d, t_image img);
t_image						new_image(t_data *d, int w, int h);
void						image_set_pixel(t_image *image, int x, int y,
		int color);
void						draw_circle(int color, t_image *img, t_vector pos,
		int radius);
void						init_radar(t_radar *r, t_data *d);
void						radar(t_data *d);
void						radar_mini(t_data *d);
t_vector					next_block(double rx, double ry, t_vector *p);
double						calc_dst_vector(t_vector vector, t_vector actual);
int							compare_vec(t_vector start, t_vector end1,
		t_vector end2, t_vector *recep);
t_vector					calc_next_y(t_radar r);
t_vector					calc_next_x(t_radar r);
void						display_wall(t_data *d, t_radar *r, int i);
int							color_wall(t_radar r, t_data *d, double pixel,
		int wall);
int							image_get_pixel(t_image *image, int x, int y);
void						init_sprite(t_data *d, char sprite, t_vector hit,
t_radar *r);
void						display_sprite(t_data *d, int i);
int							color_sprite(t_data *d, double pixel,
	t_sprite sprite);
void						clear_lstmap(t_lmap *map);
void						display_life(t_data *d);
void						draw_rect(t_vector pos, t_vector size, int color,
t_image *img);
void						get_image(t_data *d);
int							ft_checkline(char *str, char *str2);
#endif
