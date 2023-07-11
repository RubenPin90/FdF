/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:37:49 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:17:54 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_pix_put(t_fdf *data, int x, int y, int z)
{
	char	*pixel;
	int		i;

	i = data->bpp - 8;
	if (x < M_WIDTH || x >= WIN_W || y < 0 || y >= WIN_H)
		return (-1);
	pixel = data->buf + (y * data->lsize + x * (data->bpp / 8));
	if (z)
		*(int *)pixel = RED;
	else
		*(int *)pixel = WHITE;
	return (0);
}

void	draw_line(t_fdf *data, t_map p1, t_map p2)
{
	int			pixel;
	int			i;
	int			max;
	float		x_diff;
	float		y_diff;

	// isometric(&p1, data);
	// isometric(&p2, data);
	x_diff = p2.new[X] - p1.new[X];
	y_diff = p2.new[Y] - p1.new[Y];
	max = ft_max(fabs(x_diff), fabs(y_diff));
	x_diff /= max;
	y_diff /= max;
	while (max > 0)
	{
		my_pix_put(data, p1.new[X], p1.new[Y], p1.new[Z]);
		p1.new[X] += x_diff;
		p1.new[Y] += y_diff;
		max--;
	}
}

void	pixel_to_img(t_fdf *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->tools.height)
	{
		x = 0;
		while (x < data->tools.width)
		{
			if (x < data->tools.width - 1)
				draw_line(data, map[y * data->tools.width + x], \
					map[y * data->tools.width + x + 1]);
			if (y < data->tools.height - 1)
				draw_line(data, map[y * data->tools.width + x], \
					map[(y + 1) * data->tools.width + x]);
			x++;
		}
		y++;
	}
}

void	background(t_fdf *data)
{
	int		x;
	int		y;
	char	*pixel;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pixel = data->buf + (y * data->lsize + x * (data->bpp / 8));
			if (x < M_WIDTH)
				*(int *)pixel = MENU_CLR;
			else
				*(int *)pixel = BACKGROUND;
			x++;
		}
		y++;
	}
}

int	draw_map(t_fdf *data, t_map *map)
{
	if (data->win_ptr != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		data->img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
		if (!data->img)
			mlx_error(MLX_ERR, data);
		background(data);
		isometric2(data, map);
		motion(data, map);
		position(data, map);
		pixel_to_img(data, map);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
		print_menu(data);
	}
	return (0);
}
