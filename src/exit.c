/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourLogin <yourLogin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:56:10 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/16 21:16:12 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	ft_error(void *arg, int type)
{
	char	**ar;
	fdf	*data;

	if (type == PTR)
		free_null((char *)arg);
	if (type == ARRAY)
	{
		ar = (char **)arg;
		free_ar(ar);
	}
	if (type == STRUCT)
	{
		data = (fdf *)arg;
		free_struct(data);
	}
	ft_printf("Error\n");
	exit(0);
}

void	free_struct(fdf *data)
{
	if (*lst)
	{
		free_list(&(*lst)->next);
		free(*lst);
		*lst = NULL;
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

void
