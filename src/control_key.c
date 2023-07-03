/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:57:15 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/17 14:55:19 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keysym, t_fdf *data)
{
	if (keysym == XK_plus)
		data->scale *= 1.2;
	if (keysym == XK_minus && data->scale > 0.9)
		data->scale /= 1.2;
}

static void	move(int keysym, t_fdf *data)
{
	if (keysym == XK_Up)
		data->y_offset -= 5;
	if (keysym == XK_Down)
		data->y_offset += 5;
	if (keysym == XK_Left)
		data->x_offset -= 5;
	if (keysym == XK_Right)
		data->x_offset += 5;
}

int	key_press(int keysym, t_fdf *data)
{
	if (keysym == XK_Escape)
		close_fdf(data);
	zoom(keysym, data);
	move(keysym, data);
	draw_map(data, data->map);
	return (0);
}

int	key_release(int keysym, t_fdf *data)
{
	if (keysym == XK_a)
		data->z_offset *= 2;
	if (keysym == XK_s)
		data->z_offset /= 2;
	draw_map(data, data->map);
	return (0);
}