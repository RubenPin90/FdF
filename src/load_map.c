/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:45:57 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/21 19:06:26 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map(char **argv, t_fdf *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		ft_error(NULL, MLX_ERROR, data);
	data->map.content = next_line_mini(fd, data);
	close(fd);
	def_map(data);
	//get_matrix(data);
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
	count \n and save count in height
	save width with wordcount-function getwidth
	initialising **int with get_matrix
	*/
void	def_map(t_fdf *data)
{
	int		i;
	int		height;
	char	*temp;

	temp = data->map.content;
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
	ft_printf("height: %d\n", height);
	data->map.width = getwidth(data);
	data->map.height = height;
	ft_printf("width: %d\n", data->map.width);
}

int	getwidth(t_fdf *data)
{
	int		i;
	int		width;
	int		temp;

	data->points = ft_calloc(sizeof(char **), (data->map.height + 1));
	if (!data->points)
		ft_error(data->map.content, PTR, data);
	i = 0;
	width = 0;
	temp = 0;
	while (data->lines[i])
	{	
		data->points[i] = ft_split(data->lines[i], ' ');
		if (!data->points[i])
			ft_error(data->map.content, PTR, data);
		while (data->points[i][width])
				width++;
		if (temp != 0 && temp != width)
			ft_error(data->map.content, PTR, data);
		temp = width;
		i++;
	}
	return (width);
}
/*
void	get_matrix(t_fdf *data)
{
	int		i;
	t_cord	**matrix;

	matrix = ft_calloc(sizeof(char *), data->map.height);
	if (!matrix)
		ft_error(data->map.content, PTR, data);
	i = 0;
	while (i <= width)
	{
		matrix[i] = ft_calloc(sizeof(char), data->map.width);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			ft_error(data->map.content, PTR, data);
		}
		i++;
	}
	matrix = ft_split(data->map.content, '\n');
	while (i++)
	{
	i = 0;
	}
	return (word);
}*/