/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:37:49 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/25 20:30:10 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//bresenham();
//isometric();

int	draw_map(t_fdf *data)
{
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		WIN_W / 2, WIN_H / 2, 0xFFFFFF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		WIN_W / 3, WIN_H / 2, 0xFFFFFF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		WIN_W / 4, WIN_H / 2, 0xFFFFFF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		WIN_W / 5, WIN_H / 2, 0xFFFFFF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, \
		WIN_W / 6, WIN_H / 2, 0xFFFFFF);
	return (0);
}