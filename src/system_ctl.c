/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:20:28 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/17 14:53:50 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	system_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{	
		free_struct(data);
		return (MLX_ERROR);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "rpinchas-FdF");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

void system_cmd(t_fdf *data)
{
	mlx_hook(data->win_ptr, 17, NoEventMask, &close_fdf, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, NoEventMask, &key_release, data);
	mlx_hook(data->win_ptr, ButtonPress, NoEventMask, &mouse_press, data);
	mlx_hook(data->win_ptr, ButtonRelease, NoEventMask, &mouse_release, data);
}