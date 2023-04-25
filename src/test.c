/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/25 20:29:29 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		return (1);
	data = init_fdf(data);
	load_map(argv, data);
	system_init(data);
	draw_map(data);
	mlx_loop(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	/*for(int i = 0; i <= data->map_size; i++)
	{
		ft_printf("x_axis: %d\t", data->map[i].x_axis);
		ft_printf("y_axis: %d\t", data->map[i].y_axis);
		ft_printf("z_axis: %d\n", data->map[i].z_axis);
	}*/
	return (0);
}
