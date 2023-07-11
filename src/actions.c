/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:09:18 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:20:53 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	position(t_fdf *data, t_map *map)
{
	int	i;
	int	center_x;
	int	center_y;

	i = -1;
	center_x = data->tools.width / 2;
	center_y = data->tools.height / 2;
	while (++i < data->map_size)
	{
		map[i].new[X] += ((WIN_W - M_WIDTH - data->tools.width) / 2) - center_x;
		map[i].new[Y] += ((WIN_H - data->tools.height) / 2) - center_y;
	}
}

void	motion(t_fdf *data, t_map *map)
{
	int		i;

	i = 0;
	while (i < data->map_size)
	{
		map[i].new[X] = map[i].new[X] * data->scale + data->x_offset;
		map[i].new[Y] = map[i].new[Y] * data->scale + data->y_offset;
		i++;
	}
}

void	isometric2(t_fdf *data, t_map *p)
{
	int	i;

	i = 0;
	while (i < data->map_size)
	{
		p[i].new[Z] = p[i].z / data->z_offset;
		p[i].new[X] = (p[i].x - p[i].y) * cos(data->angle);
		p[i].new[Y] = (p[i].x + p[i].y) * sin(data->angle) - p[i].new[Z];
		i++;
	}
}
