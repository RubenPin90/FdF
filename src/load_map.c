/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:45:57 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/17 18:33:12 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map(char **argv, t_fdf *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return ; //free_function
	data->map.content = next_line_mini(fd);
	close(fd);
}

char	*next_line_mini(int fd)
{
	char	*map;
	char	*buf;
	char	*temp;

	map = ft_calloc(sizeof(char), 1);
	buf = ft_calloc(sizeof(char), 2);
	if (!buf || !map)
	{
		free_null(map);
		ft_error(buf, PTR);
	}
	ft_printf("Loading Map...\n");
	while (read(fd, buf, 1) > 0)
	{
		temp = map;
		map = ft_strjoin(temp, buf);
		if (!map)
		{
			free_null(temp);
			ft_error(buf, PTR);
		}
		free_null(temp);
	}
	free_null(buf);
	return (map);
}
