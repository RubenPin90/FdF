/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:02:05 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 03:56:44 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = NULL;
	if (argc != 2)
		return (1);
	data = init_fdf(data);
	load_map(argv, data);
	system_init(data);
	draw_map(data, data->dots);
	mlx_loop(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
