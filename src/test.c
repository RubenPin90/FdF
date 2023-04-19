/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/19 19:55:14 by rpinchas         ###   ########.fr       */
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
	printf("map: %s", data->map.content);
	printf("map: %d", data->map.width);
	printf("map: %d", data->map.height);
	system_init(data);
	system_cmd(data);
	mlx_loop_hook(data->mlx_ptr, &no_event, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_null(data->map.content);
	free(data);
	return (0);
}
