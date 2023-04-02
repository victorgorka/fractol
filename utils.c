/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:56:55 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/02 19:59:33 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_module(float r, float i)
{
	return ((r * r) + (i * i));
}

int	ft_color(int iter, int color, t_data *data)
{
	int	color_set[5];

	color_set[0] = 0x1932c2ff;
	color_set[1] = 0x8a601dff;
	color_set[2] = 0x80ff80ff;
	color_set[3] = 0x0fd697ff;
	color_set[4] = 0xd9331aff;
	if (iter >= data->max_iter - 1)
		return (0x000000ff);
	else
		return (color_set[(color % 5)] + (iter * 0x03030000));
}

void	ft_card_to_comp(t_data	*data)
{
	data->c_r = data->min_re + data->x
		* (data->max_re - data->min_re) / (data->width - 1);
	data->c_i = data->max_i - data->y
		* (data->max_i - data->min_i) / (data->height - 1);
}

void	ft_card_to_comp_jul(t_data	*data)
{
	data->z_r = data->min_re + data->x
		* (data->max_re - data->min_re) / (data->width - 1);
	data->z_i = data->max_i - data->y
		* (data->max_i - data->min_i) / (data->height - 1);
}

void	ft_exit(int n)
{
	if (n == 0)
	{
		ft_putstr_fd("m = Mandelbrot\nj[0..5] = fractales de Julia\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error, argumento no valido\n", 2);
		exit(EXIT_FAILURE);
	}
}