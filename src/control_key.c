/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:57:15 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 03:48:29 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zoom(int keysym, t_fdf *data)
{
	if (keysym == 43)
		data->scale *= 1.2;
	if (keysym == 45 && data->scale > 0.9)
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
	draw_map(data, data->dots);
	return (0);
}	

int	key_release(int keysym, t_fdf *data)
{
	if (keysym == XK_a && data->z_offset < 10)
		data->z_offset *= 1.2;
	if (keysym == XK_s && data->z_offset > 1)
	{
		data->z_offset /= 1.2;

	}
	draw_map(data, data->dots);
	return (0);
}
