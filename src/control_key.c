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

int	key_press(int keysym, t_fdf *data)
{
	if (keysym == XK_Escape)
		close_fdf(data);
	return (0);
}

int	key_release(int keysym, t_fdf *data)
{
	(void)data;
	return (0);
}