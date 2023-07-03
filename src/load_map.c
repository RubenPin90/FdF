/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubsky <rubsky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:45:57 by yourLogin         #+#    #+#             */
/*   Updated: 2023/06/30 15:36:21 by rubsky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Open File, read file descriptor and save data in data->content. 
Get width and heigth with def_map
and define all coordinates with x, y, z with get_matirx
*/
void	load_map(char **argv, t_fdf *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		ft_error(NULL, MLX_ERROR, data);
	data->content = next_line_mini(fd, data);
	close(fd);
	def_map(data);
	get_matrix(data);
}

char	*next_line_mini(int fd, t_fdf *data)
{
	char	*map;
	char	*buf;
	char	*temp;

	map = ft_calloc(sizeof(char), 1);
	buf = ft_calloc(sizeof(char), 2);
	if (!buf || !map)
	{
		free_null(map);
		ft_error(buf, PTR, data);
	}
	ft_printf("Loading Map...\n");
	while (read(fd, buf, 1) > 0)
	{
		temp = map;
		map = ft_strjoin(temp, buf);
		if (!map)
		{
			free_null(temp);
			ft_error(buf, PTR, data);
		}
		free_null(temp);
	}
	free_null(buf);
	return (map);
}

/*
check content if its valid
split content according to \n and save in t_map
get height and width
get ***pointer of all numbers
*/
void	def_map(t_fdf *data)
{
	int		i;
	int		height;
	char	*temp;

	temp = data->content;
	i = 0;
	height = 0;
	while (temp[i])
	{
		if (!ft_isalnum(temp[i]) && temp[i] != ' ' && \
		temp[i] != '-' && temp[i] != '\n')
			ft_error(temp, PTR, data);
		i++;
	}
	data->lines = ft_split(temp, '\n');
	if (!data->lines)
		ft_error(temp, PTR, data);
	while (data->lines[height])
		height++;
	data->height = height;
	data->width = getwidth(data);
}

int	getwidth(t_fdf *data)
{
	int		i;
	int		width;
	int		temp;

	width = 0;
	temp = 0;
	data->points = ft_calloc(sizeof(char *), (data->height + 1));
	if (!data->points)
		ft_error(data->content, PTR, data);
	i = 0;
	while (data->lines[i])
	{	
		data->points[i] = ft_split(data->lines[i], ' ');
		if (!data->points[i])
			ft_error(data->content, PTR, data);
		while (data->points[i][width])
			width++;
		if (temp != 0 && temp != width)
			ft_error(data->content, PTR, data);
		temp = width;
		i++;
	}
	return (width);
}

void	get_matrix(t_fdf *data)
{
	int	y;
	int	x;
	int	i;

	data->map_size = data->height * data->width;
	data->map = ft_calloc(sizeof(t_map), data->map_size + 1);
	if (!data->map)
		ft_error(data->content, PTR, data);
	y = 0;
	i = 0;
	while (data->points[y])
	{
		x = 0;
		while (data->points[y][x])
		{
			data->map[i].z = ft_atoi(data->points[y][x++]);
			data->map[i].y = y;
			data->map[i].x = x;
			//data->map[i].color = if_color(data->points[y][x]);
			i++;
		}
		y++;
	}	
}
