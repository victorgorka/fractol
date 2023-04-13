/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:12:55 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/13 18:22:31 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	- It's the same as Mandelbrot set, but C is not the complex coordinates of
	  the pixel we are iterating. It's a prestablished value of the complex
	  plane I chose of interesting Julia sets.
	- A very interesting solution to do this is to let the user to enter
	  by CLI 'c_r' and 'c_i' to generate a different Julia set dependending
	  on those inputs. I needed to finish this project as soon as possible
	  and I didnt try.
*/
static int	ft_julia(t_data *data)
{
	float	tmp_zr;
	int		i;

	i = 0;
	while (i < data->max_iter && ft_module(data->z_r, data->z_i) < 4)
	{
		tmp_zr = (data->z_r * data->z_r) - (data->z_i * data->z_i) + data->c_r;
		data->z_i = 2 * data->z_r * data->z_i + data->c_i;
		data->z_r = tmp_zr;
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
void	ft_julia_set(t_data *data)
{
	int	i;

	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			ft_cart_to_comp_jul(data);
			i = ft_julia(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color, data));
			data->x++;
		}
		data->y++;
	}
}

void	ft_set_julia(t_data *data)
{
	if (data->julia_type == 0)
	{
		data->c_r = -0.12;
		data->c_i = -0.77;
	}
	else if (data->julia_type == 1)
	{
		data->c_r = -0.79;
		data->c_i = 0.15;
	}
	else if (data->julia_type == 2)
	{
		data->c_r = -0.162;
		data->c_i = 1.04;
	}
	else if (data->julia_type == 3)
	{
		data->c_r = 0.3;
		data->c_i = -0.1;
	}
}
