/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:17:12 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/13 19:12:39 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	- It consist to iterate the succession 'Zn+1 = Zn^2 + C' until the module
	  of Z is > 4 or we reach the maximum of iterations.
	- Z is initialized to 0.
	- The solution of the math part is:
		Z = (Z_r + Z_i)^2 + C_r + C_i;
	 ---Z = Z_r^2 - Z_i^2 + 2*Z_r*Z_i + C_r + C_i; // Lets separate Re and Img
	|
	|	// Important thing, the square of a sum (a + b)^2 = a^2 + b^2 + 2*a*b;
	|	// but as you can see a subtract is done in the square of Z sum. It's
	|	// because I did the square of the imaginary part of the number Zi. So
	|	// if i^2 = -1; then Z_i^2 = -Z_i;
	|	// Maybe It is confuse to still see the 'i' in 'Z_i' and consider it a
	|	// real number now, even after we eliminate the imaginary part of 'Z_i',
	|	// but I prefer to do this explanation using the variables names so you
	|	// can understand the code below.
	|	 _________________________
	|-->|Z_r = Z_r^2 - Z_i^2 + C_r|
	|-->|Z_i = 2 * Z_r * Z_i + C_i|
		 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
*/
static int	ft_mandelbrot(t_data *data)
{
	float	tmp_r;
	int		i;

	i = 0;
	data->z_r = 0;
	data->z_i = 0;
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

/*
	- It iterate each pixel, and aplly it ft_burningship, to determine what color
	  print in that pixel.
*/
void	ft_mandelbrot_set(t_data *data)
{
	int	i;

	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			ft_cart_to_comp(data);
			i = ft_mandelbrot(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color, data));
			data->x++;
		}
		data->y++;
	}
}
