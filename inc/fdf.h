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
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <libft.h>
# include <mlx.h>

# define READ_SIZE 10000
# define WIN_W 1280
# define WIN_H 720
# define MLX_ERROR 1
# define ARRAY 2
# define PTR 3
# define STRUCT 4
# define X 0
# define Y 1
# define Z 2

# define READ_ERR "File could not be opened!"
# define ALLOC_ERR "MALLOC Error detected!"
# define INVALID_ERR "Invalid Map: Incompatible char detected!"
# define SIZE_ERR "Invalid Map: Line lenth not consistent!"
# define MLX_ERR "MLX Error detected!"
# define ERR	"Error"

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

typedef struct s_load
{
	char	*map;
	char	*buf;
	int		height;
	int		width;
}	t_load;

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
	int		map_size;
	t_load	tools;
	t_map	*dots;
}	t_fdf;

/*Loading Map*/
void	load_map(char **argv, t_fdf *data);
void	next_line_mini(int fd, t_fdf *data, t_load *utils);
void	def_map(t_fdf *data, char *tmp);
void	get_points(t_map *dots, char *line);
void	get_matrix(t_fdf *data, t_load *tools);

/*Checking Map*/
int		valid_char(int c);
int		is_space(int c);
void	def_map(t_fdf *data, char *map);
char	*ft_strnjoin(char const *s1, char const *s2, int len);

/*System Control*/
int		system_init(t_fdf *data);
void	system_cmd(t_fdf *data);
t_fdf	*init_fdf(t_fdf *data);

/*Free Functions*/
void	ft_error(char *msg, t_fdf *data);
void	ft_exit(t_fdf *data);
void	*free_ar(char **ar);
void	*free_null(void *ptr);
int		close_fdf(t_fdf *data);

/*Key and Mouse Bindings*/
int		key_press(int keysym, t_fdf *data);
int		key_release(int keysym, t_fdf *data);

/*Draw Map*/
int		draw_map(t_fdf *data, t_map *map);
void	pixel_to_img(t_fdf *data, t_map *map);
void	draw_line(t_fdf *data, t_map n, t_map m);
int		my_pix_put(t_fdf *data, int x, int y, int z);

/*Draw Menu*/
void	print_menu(t_fdf *data);

/*Utils*/
float	ft_max(float a, float b);
char	*ft_strnjoin(char const *s1, char const *s2, int len);
void	str_put(t_fdf *data, int x, int y, char *str);
void	nbr_put(t_fdf *data, int x, int y, int n);

/*Actions*/
void	motion(t_fdf *data, t_map *map);
void	position(t_fdf *data, t_map *map);
void	isometric(t_map *p, t_fdf *data);

#endif
