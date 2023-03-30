/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:17:12 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/30 16:56:22 by vde-prad         ###   ########.fr       */
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
	while (i < MAX_ITER && ft_module(data->z_r, data->z_i) < 4)
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
	while (data->y < data.height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			data->z_r = data.min_re + data->x * (data->max_re - data->min_re) / (data->width - 1);
			data->z_i = data->max_i - data->y * (data->max_i - data->min_i) / (data->height - 1);
			i = ft_mandelbrot(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color));
			data->x++;
		}
		data->y++;
	}
}