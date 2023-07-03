/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by rpinchas          #+#    #+#             */
/*   Updated: 2023/04/25 20:29:29 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	str_put(t_fdf *data, int x, int y, char *str)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, FONT_CLR, str);
}

void	nbr_put(t_fdf *data, int x, int y, int n)
{
	char	*tmp;

	tmp = ft_itoa(n);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, FONT_CLR, tmp);
	free (tmp);
}

void	menu_data(t_fdf *data)
{
	int		line;

	line = FDFINFO_BOX;
	str_put(data, M_TAB, line, "** FDF INFO **");
	line += L_SIZE;
	str_put(data, M_TAB, line, "  X     Y     Z");
	line += 20;
	str_put(data, M_TAB, line, "[    ][    ][    ]");
	nbr_put(data, M_TAB + 5, line, data->map->new[X]);
	nbr_put(data, M_TAB + 40, line, data->map->new[Y]);
	nbr_put(data, M_TAB + 80, line, data->map->new[Z]);
	line += L_SIZE;
	str_put(data, M_TAB, line, "Zoom:");
	nbr_put(data, M_TAB + 80, line, data->scale);
}

void	map_info(t_fdf *data)
{
	int		line;

	line = MAPINFO_BOX;
	str_put(data, M_TAB, line, "** MAP INFO **");
	line += L_SIZE;
	str_put(data, M_TAB, line, "Size:");
	nbr_put(data, M_TAB + 80, line, data->map_size);
	line += L_SIZE;
	str_put(data, M_TAB, line, "Map Width");
	nbr_put(data, M_TAB + 80, line, data->width);
	line += L_SIZE;
	str_put(data, M_TAB, line, "Map Height");
	nbr_put(data, M_TAB + 80, line, data->height);
	line += L_SIZE;
}

static void	control_info(t_fdf *data)
{
	int		line;

	line = CTL_BOX;
	str_put(data, M_TAB, line, "** CONTROLS **");
	line += L_SIZE;
	str_put(data, M_TAB, line, "+/-: Zoom In/Out");
	line += L_SIZE;
	str_put(data, M_TAB, line, "Arrows: Move");
	line += L_SIZE;
	str_put(data, M_TAB, line, "a/s: Z Movment");
	line += L_SIZE;
}


void	print_menu(t_fdf *data)
{
	menu_data(data);
	map_info(data);
	control_info(data);
}