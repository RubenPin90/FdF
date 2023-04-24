/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:56:10 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/19 23:02:46 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

void	ft_error(void *arg, int type, t_fdf *data)
{
	char	**ar;

	if (type == PTR)
		free_null((char *)arg);
	if (type == ARRAY)
	{
		ar = (char **)arg;
		free_ar(ar);
	}
	free_struct(data);
	ft_printf("Error\n");
	exit(0);
}

void	free_struct(t_fdf *data)
{
	if (data->lines)
		free_ar(data->lines);
	if (data->points)
	{
		free_ar(*data->points);
		free_null((char *)data->points);
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
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

void	*free_null(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
