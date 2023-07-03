/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsky <rubsky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by yourLogin         #+#    #+#             */
/*   Updated: 2023/06/30 14:58:32 by rubsky           ###   ########.fr       */
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
	draw_map(data, data->map);
	mlx_loop(data->mlx_ptr);
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
