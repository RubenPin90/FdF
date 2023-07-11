/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:53:02 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:21:37 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Checks if argument is alphanumeric and + , -
If true func returns a 1 else a 0.
*/
int	valid_char(int c)
{
	return (ft_isalnum(c) || (c >= 43 && c <= 45));
}

/*
Checks if argument is a space/newline/NULL
If true function returns a 1 else a 0.
*/
int	is_space(int c)
{
	return (c == 32 || c == 10 || c == 0);
}

/*
Function defines map size & check for validity.
Iterates over map buffer and counts 
y = map heigth 
x = map width
checks if invalid chars included
checks if map size is inconsistent.
*/
void	def_map(t_fdf *data, char *map)
{
	int		x;
	int		y;
	int		i;

	i = -1;
	x = 0;
	y = 0;
	while (map[++i])
	{
		if (map[i] == '\n' && map[i + 1] == '\0' && x == 0)
			break ;
		if (valid_char(map[i]) && is_space(map[i + 1]))
			x++;
		if (map[i] == '\n' || map[i] == '\0')
		{
			y++;
			if (data->tools.width != 0 && data->tools.width != x)
				ft_error(SIZE_ERR, data);
			data->tools.width = x;
			x = 0;
		}
		else if (!valid_char(map[i]) && !is_space(map[i]))
			ft_error(INVALID_ERR, data);
	}
	data->tools.height = y;
}
