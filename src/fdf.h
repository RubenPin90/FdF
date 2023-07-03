/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:30:35 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/24 16:27:40y rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_W 1280
# define WIN_H 720
# define MLX_ERROR 1
# define ARRAY 2
# define PTR 3
# define STRUCT 4
# define X 0
# define Y 1
# define Z 2

/*COLORS*/
# define WHITE 0xFFFFFF
# define RED 0xe80c0c
# define FONT_CLR 0xEEEEEE
# define MENU_CLR 0x1A1A1A
# define BACKGROUND 0x0B0B0B

/*MENU*/
# define M_WIDTH 160
# define FDFINFO_BOX 40
# define MAPINFO_BOX 200
# define CTL_BOX	400
# define M_TAB   30
# define L_SIZE  30

typedef struct s_map
{
	float	x;
	float	y;
	float	z;
	float	new[3];
	int		color;	
}	t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*buf;
	int		bpp;
	int		lsize;
	int		endian;
	float	scale;
	double	angle;
	int		x_offset;
	int		y_offset;
	float	z_offset;
	int		check;
	float	tmpx;
	float	tmpy;
	int		width;
	int		height;
	int		map_size;
	char	*content;
	char	**lines;
	char	***points;
	t_map	*map;
}	t_fdf;

/*Loading Map*/
void	load_map(char **argv, t_fdf *data);
char	*next_line_mini(int fd, t_fdf *data);
void	def_map(t_fdf *data);
int		getwidth(t_fdf *data);
void	get_matrix(t_fdf *data);

/*System Control*/
int		system_init(t_fdf *data);
void	system_cmd(t_fdf *data);
t_fdf	*init_fdf(t_fdf *data);
int		no_event(void *data);

/*Free Functions*/
void	ft_error(void *arg, int type, t_fdf *data);
void	free_struct(t_fdf *data);
void	*free_ar(char **ar);
void	*free_null(void *ptr);
int		close_fdf(t_fdf *data);

/*Key and Mouse Bindings*/
int		key_press(int keysym, t_fdf *data);
int		key_release(int keysym, t_fdf *data);
int		mouse_press(int button, t_fdf *data);

int		draw_map(t_fdf *data, t_map *map);
void	isometric(t_map *p, t_fdf *data);
void	pixel_to_img(t_fdf *data, t_map *map);
void	draw_line(t_fdf *data, t_map n, t_map m);
int		render(t_fdf *data);
int		my_pix_put(t_fdf *data, int x, int y, int z);

void	print_menu(t_fdf *data);

#endif
