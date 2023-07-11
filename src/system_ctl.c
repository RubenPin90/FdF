/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_ctl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 04:21:13 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:21:14 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	system_init(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error(MLX_ERR, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "rpinchas-FdF");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		ft_error(MLX_ERR, data);
	}
	data->img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->buf = mlx_get_data_addr(data->img, \
		&data->bpp, &data->lsize, &data->endian);
	system_cmd(data);
	return (0);
}

void	system_cmd(t_fdf *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &key_release, data);
	mlx_hook(data->win_ptr, 17, NoEventMask, &close_fdf, data);
}

/*Function allocates t_fdf and initiates all varibles with default values.*/

t_fdf	*init_fdf(t_fdf *data)
{
	data = (t_fdf *)ft_calloc(sizeof(t_fdf), 1);
	if (!data)
		ft_error(ALLOC_ERR, NULL);
	data->scale = 10;
	data->angle = 0.8;
	data->x_offset = 0;
	data->y_offset = 0;
	data->z_offset = 1;
	data->map_size = 0;
	data->tools.width = 0;
	data->tools.height = 0;
	data->dots = NULL;
	return (data);
}
