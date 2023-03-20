/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:17:12 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/20 20:28:45 by vde-prad         ###   ########.fr       */
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
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			data->c_r = MIN_RE + data->x * (MAX_RE - MIN_RE) / (WIDTH - 1);
			data->c_i = MAX_I - data->y * (MAX_I - MIN_I) / (HEIGHT - 1);
			i = ft_mandelbrot(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color));
			data->x++;
		}
		data->y++;
	}
}