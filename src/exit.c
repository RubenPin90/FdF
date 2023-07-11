/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:02:45 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 03:55:23 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_exit(data);
	exit(0);
	return (0);
}

void	ft_error(char *msg, t_fdf *data)
{
	ft_putstr_fd(msg, 2);
	if (data)
		ft_exit(data);
	exit(1);
}

void	ft_exit(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->tools.map)
		free_null(data->tools.map);
	if (data->dots)
		free_null(data->dots);
	if (data)
		free_null(data);
}

void	*free_ar(char **ar)
{
	int	i;

	if (!ar)
		return (NULL);
	i = 0;
	while (ar[i])
	{
		free_null(ar[i]);
		i++;
	}
	free(ar);
	ar = NULL;
	return (NULL);
}

void	*free_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
