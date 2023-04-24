/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/24 20:12:20 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int no_event(void *data)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (1);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (MLX_ERROR);
	load_map(argv, data);
	ft_printf("map: %d", data->width);
	ft_printf("map: %d\n", data->height);
	for(int i = 0; i <= data->map_size; i++)
	{
		ft_printf("x_axis: %d\t", data->map[i].x_axis);
		ft_printf("y_axis: %d\t", data->map[i].y_axis);
		ft_printf("z_axis: %d\n", data->map[i].z_axis);
	}
	system_init(data);
	system_cmd(data);
	mlx_loop_hook(data->mlx_ptr, &no_event, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_null(data->content);
	free_struct(data);
	return (0);
}
