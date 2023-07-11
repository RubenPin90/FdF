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

	i = 0;
	center_x = data->tools.width / 2;
	center_y = data->tools.height / 2;
	while (i < data->map_size)
	{
		map[i].new[X] += ((WIN_W - M_WIDTH - data->tools.width) / 2) - center_x;
		map[i].new[Y] += ((WIN_H - data->tools.height) / 2) - center_y;
		i++;
	}
}

void	motion(t_fdf *data, t_map *map)
{
	int		i;

	i = 0;
	while (i < data->map_size)
	{
		map[i].new[X] = map[i].x * data->scale + data->x_offset;
		map[i].new[Y] = map[i].y * data->scale + data->y_offset;
		map[i].new[Z] = map[i].z / data->z_offset;
		i++;
	}
}

void	isometric(t_map *p, t_fdf *data)
{
	p->new[X] = (p->new[X] - p->new[Y]) * cos(data->angle);
	p->new[Y] = (p->new[X] + p->new[Y]) * sin(data->angle) - p->new[Z];
	p->new[X] += (WIN_W - M_WIDTH + data->tools.width) / 3;
	p->new[Y] += (WIN_H + data->tools.height) / 3;
}
