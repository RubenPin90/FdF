/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:02:25 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 03:02:30 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Opens File, reads file descriptor and saves data in data->tools.map. 
Checks validity of map and gets size with def_map.
Defines all coordinates with x, y, z with get_matrix
*/
void	load_map(char **argv, t_fdf *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		ft_error(READ_ERR, data);
	next_line_mini(fd, data, &data->tools);
	close(fd);
	def_map(data, data->tools.map);
	get_matrix(data, &data->tools);
}

void	next_line_mini(int fd, t_fdf *data, t_load *tools)
{
	char	*tmp;
	int		res;

	tools->buf = ft_calloc(sizeof(char), READ_SIZE + 1);
	if (!tools->buf)
		ft_error(ALLOC_ERR, data);
	tools->map = ft_strdup("");
	res = 1;
	while (res > 0)
	{
		res = read(fd, tools->buf, READ_SIZE);
		tmp = tools->map;
		tools->map = ft_strnjoin(tmp, tools->buf, res);
		if (!tools->map)
		{
			free_null(tmp);
			free_null(tools->buf);
			ft_error(ERR, data);
		}
		free_null(tmp);
	}
	free_null(tools->buf);
}

void	get_matrix(t_fdf *data, t_load *tools)
{
	int		i;
	int		start;
	char	*tmp;

	data->map_size = tools->height * tools->width;
	data->dots = ft_calloc(sizeof(t_map), data->map_size);
	if (!data->dots)
		ft_error(ALLOC_ERR, data);
	i = -1;
	start = 0;
	tmp = NULL;
	while (tools->map[++i])
	{
		if (tools->map[i] == '\n')
		{
			tmp = ft_substr(tools->map, start, i - start);
			start = i + 1;
			if (get_points(data->dots, tmp))
			{
				free(tmp);
				ft_error(SPLIT_ERR, data);
			}
			free(tmp);
		}
	}
}

int	get_points(t_map *dots, char *line)
{
	int			x;
	char		**coord;
	static int	index = 0;
	static int	y = -1;

	y++;
	x = 0;
	coord = ft_split(line, ' ');
	if (!coord)
		return (1);
	while (coord[x])
	{
		dots[index].x = x;
		dots[index].z = ft_atoi(coord[x]);
		dots[index].y = y;
		index++;
		x++;
	}
	free_ar(coord);
	return (0);
}
