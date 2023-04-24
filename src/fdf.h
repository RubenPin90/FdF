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

/*
** _______________ program structure ________________
** 1. read file
**		- get height (how many lines) of text
**		- get width (how many numbers in line)
**		- allocate memory for **int by using width and height 
**		- read file and write number into **int matrix by using
**				+ ft_split()
**				+ atoi()
** _______________
** 2. drawing line function (google Bresenham algorithm)
**		- find by how much we need to increase x and by how much we need to increase y
**			by using float. Example:
**				x = 2; x1 = 4;
**				y = 2; y1 = 6;
**				steps for x: 2
**				steps for y: 4
**				that means that y should grow 2 times faster than x
**				ewery loop step: y += 1 and x += 0.5
**				after 4 steps x and y will be equal with x1, y1
**
**					real x:y		x:y     pixels				
**			start:		2.0 : 2.0		2:2        .
**			step1:		2.5 : 3.0		2:3        .
**			step2:		3.0 : 4.0		3:4         .
**			step3:		3.5 : 5.0		3:5         .
**			step4:		4.0 : 6.0		4:6          .
**
**				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
**	--------------
**	3. function which draws lines beetwen every dot
**		- examle:
**				0->		0->		0->		0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		0->		0->		0
**			'->' and '|'are lines between dots 
**			every dot has two lines (right and down):	0->
**                                                                      |
**	----------------
**	4. adding 3D
**		- change coordinates by using isometric formulas:
**			x` = (x - y) * cos(angle)
**			y` = (x + y) * sin(angle) - z
**		- x` and y` are coordintes in 3D format (default angle 0.8)
**	----------------
**	5. adding donuses (move, rotation, zoom)
**		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**			call the func. deal_key.
**		- In the deal key func. you have to change some parametrs, clear the window with
**			mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
**	----------------
**	6. error handling
**		- check if argc == 2
**		- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
**	----------------
**	7. fix leaks
**		- type leaks a.out or leaks fdf in your shell
 */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_W 600
# define WIN_H 300
# define MLX_ERROR 1
# define ARRAY 2
# define PTR 3
# define STRUCT 4

typedef struct s_map
{
	int		x_axis;
	int		y_axis;
	int		z_axis;
	char	*color;	
}	t_map;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
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

/*Free Functions*/
void	ft_error(void *arg, int type, t_fdf *data);
void	free_struct(t_fdf *data);
void	*free_ar(char **ar);
void	*free_null(char *ptr);
int		close_fdf(t_fdf *data);

/*Key and Mouse Bindings*/
int		key_press(int keysym, t_fdf *data);
int		key_release(int keysym, t_fdf *data);
int		mouse_press(int keysym, t_fdf *data);
int		mouse_release(int keysym, t_fdf *data);

#endif
