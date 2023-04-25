/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:20:28 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/25 18:47:36 rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	system_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error(NULL, MLX_ERROR, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "rpinchas-FdF");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_error(NULL, MLX_ERROR, data);
	}
	system_cmd(data);
	return (0);
}

void system_cmd(t_fdf *data)
{
	//mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, NoEventMask, &key_release, data);
	mlx_hook(data->win_ptr, ButtonPress, NoEventMask, &mouse_press, data);
	mlx_hook(data->win_ptr, ButtonRelease, NoEventMask, &mouse_release, data);
	mlx_hook(data->win_ptr, 17, NoEventMask, &close_fdf, data);
}

t_fdf	*init_fdf(t_fdf *data)
{
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error(NULL, MLX_ERROR, NULL);
	data->width = 0;
	data->height = 0;
	data->map_size = 0;
	data->content = NULL;
	data->lines = NULL;
	data->points = NULL;
	data->map = NULL;
	return (data);
}

int no_event(void *data)
{
	return (0);
}