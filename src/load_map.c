/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:45:57 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/19 23:21:29 by rpinchas         ###   ########.fr       */
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
		if (temp[i] == '\n')
			height++;
		i++;
	}
	data->map.width = getwidth(temp);
	data->map.height = height;
}

int	getwidth(char *temp)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (temp[i] && temp[i] != '\n')
	{
		while (temp[i] == ' ' && temp[i])
			i++;
		if (temp[i] != ' ' && temp[i] != '\n' && temp[i])
			width++;
		while (temp[i] != ' ' && temp[i])
		{	
			if (temp[i] == '\n')
				break ;
			i++;
		}
	}
	return (width);
}

void	get_matrix(t_fdf *data)
{
	int	i;
	char	**matrix;

	matrix = ft_calloc(sizeof(int), data->map.height);
	if (!matrix)
		ft_error(data->map.content, PTR, data);
	i = 0;
	while (i <= width)
	{
		matrix[i] = ft_calloc(sizeof(int), data->map.width);
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
		
	}
	return (word);
}