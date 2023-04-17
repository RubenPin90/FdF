/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourLogin <yourLogin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/16 17:51:25 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysym.h>
#include <X11/X.h>

int no_event(void *data)
{
	return (0);
}

int press_escape(int keysym, fdf *data)
{
	printf("Keypress: %d\n", keysym);
	printf("XK_Escape: %d\n", XK_Escape);
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}


int main(int argc, char **argv)
{
	fdf	*data;

	if (argc != 2)
		return (1);
	data = (fdf *)malloc(sizeof(fdf));
	if (!data)
		return (MLX_ERROR);
	load_map(argc, argv, data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{	
	//	free(data);
		return (MLX_ERROR);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (MLX_ERROR);	
	}
	mlx_loop_hook(data->mlx_ptr, &no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &press_escape, data);
	//mlx_key_hook(data.win_ptr, &escape, &data);

	mlx_loop(data->mlx_ptr);

	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}

