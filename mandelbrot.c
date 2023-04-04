/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:17:12 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/04 14:40:15 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_mandelbrot(t_data *data)
{
	float	tmp_r;
	int		i;

	i = 0;
	data->z_r = data->c_r;
	data->z_i = data->c_i;
	while (i < data->max_iter && ft_module(data->z_r, data->z_i) < 4)
	{
		tmp_r = (data->z_r * data->z_r) - (data->z_i * data->z_i) + data->c_r;
		data->z_i = 2 * data->z_r * data->z_i + data->c_i;
		data->z_r = tmp_r;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	ft_mandelbrot_set(t_data *data)
{
	int	i;

	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			ft_card_to_comp(data);
			i = ft_mandelbrot(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color, data));
			data->x++;
		}
		data->y++;
	}
}
