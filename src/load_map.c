/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourLogin <yourLogin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 07:45:57 by yourLogin         #+#    #+#             */
/*   Updated: 2023/04/17 09:30:33 by yourLogin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void load_map(int argc, char **argv, t_fdf *data)
{
	int fd;
	
	fd = open(argv[1], O_RDONLY);	
	if (fd < 2)
		return ; //free_function
//	data->map.size = next_line_mini(fd);
	printf("fd: %d", fd);
	printf("map: %s", data->map.size);
	close(fd);
}

char *next_line_mini(int fd)
{
	int count;
	char *map;
	char *buf;
	char *temp;

	map = malloc(sizeof(char)*1);
	if(!map)
		return(NULL); 
	count = 1;
	ft_printf("Loading Map...\n");
	while (count)
	{
		buf = ft_calloc(sizeof(char), 2);
		if (!buf)
		{
			free(map);
			return(NULL);
		}
		count = read(fd, buf, 1);
		temp = map;
		map = ft_strjoin(map, buf);
		free(temp);
	}

	free(buf);
	return(map);	
}


