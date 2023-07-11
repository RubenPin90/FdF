/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:06:41 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:22:00 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	menu_data(t_fdf *data)
{
	int		line;

	line = FDFINFO_BOX;
	str_put(data, M_TAB, line, "** FDF INFO **");
	line += L_SIZE;
	str_put(data, M_TAB, line, "  X     Y     Z");
	line += 20;
	str_put(data, M_TAB, line, "[    ][    ][    ]");
	nbr_put(data, M_TAB + 5, line, data->dots->new[X]);
	nbr_put(data, M_TAB + 40, line, data->dots->new[Y]);
	nbr_put(data, M_TAB + 80, line, data->dots->new[Z]);
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
	nbr_put(data, M_TAB + 80, line, data->tools.width);
	line += L_SIZE;
	str_put(data, M_TAB, line, "Map Height");
	nbr_put(data, M_TAB + 80, line, data->tools.height);
	line += L_SIZE;
}

void	control_info(t_fdf *data)
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
