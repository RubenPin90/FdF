/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:56:10 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/25 18:58:49 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_fdf(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_struct(data);
	exit(0);
	return (0);
}

void	ft_error(void *arg, int type, t_fdf *data)
{
	char	**ar;

	if (type == PTR)
		free_null(arg);
	if (type == ARRAY)
	{
		ar = (char **)arg;
		free_ar(ar);
	}
	if (data)
		free_struct(data);
	ft_printf("Error\n");
	exit(0);
}

void	free_struct(t_fdf *data)
{
	int	i;

	i = 0;
	if (data->lines)
		free_ar(data->lines);
	if (data->content)
		free_null(data->content);
	if (data->points)
	{
		while (data->points[i])
			free_ar(data->points[i++]);
		free(data->points);
	}
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
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

void	*free_null(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}
