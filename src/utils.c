/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 03:59:26 by rpinchas          #+#    #+#             */
/*   Updated: 2023/07/11 04:18:32 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*
Function is like strjoin but only joins len amount of s2 with
s1. This is needed because the last read operation is not filling 
the buffer completely, resulting in undefined behavior. 
*/
char	*ft_strnjoin(char const *s1, char const *s2, int len)
{
	char	*s3;
	int		slen;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + len + 1;
	s3 = (char *)malloc(slen * sizeof(char));
	if (s3 == NULL)
		return (0);
	ft_strlcpy(s3, s1, slen);
	ft_strlcat(s3, s2, slen);
	return (s3);
}

void	str_put(t_fdf *data, int x, int y, char *str)
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
