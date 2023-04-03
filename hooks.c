/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:52:22 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/03 21:24:03 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		((t_data *)param)->color++;
		ft_select_fractal((t_data *)param);
	}
	else
		ft_arrows(keydata, (t_data *)param);
}

void	ft_arrows(mlx_key_data_t keydata, t_data *data)
{
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_re += 0.05;
		data->min_re += 0.05;
		ft_select_fractal(data);
	}	
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_re -= 0.05;
		data->min_re -= 0.05;
		ft_select_fractal(data);
	}
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_i += 0.05;
		data->min_i += 0.05;
		ft_select_fractal(data);
	}
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_i -= 0.05;
		data->min_i -= 0.05;
		ft_select_fractal(data);
	}
	//printf("\nmax_re= %f\nmin_re = %f\nmax_i = %f\nmin_i = %f\n*******arrows", data->max_re, data->min_re, data->max_i, data->min_i);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	float	cent_r;
	float	cent_i;

	cent_r = ((t_data *)param)->min_re - ((t_data *)param)->max_re;
	cent_i = ((t_data *)param)->max_i - ((t_data *)param)->min_i;
	(void)xdelta;
	if (ydelta > 0)
	{
		((t_data *)param)->max_re += (cent_r - 0.5 * cent_r) / 2;
		((t_data *)param)->min_re = ((t_data *)param)->max_re + 0.5 * cent_r;
		((t_data *)param)->min_i += (cent_i - 0.5 * cent_i) / 2;
		((t_data *)param)->max_i = ((t_data *)param)->min_i + 0.5 * cent_i;
	}
	else if (ydelta < 0)
	{
		((t_data *)param)->max_re += (cent_r - 2 * cent_r) / 2;
		((t_data *)param)->min_re = ((t_data *)param)->max_re + 2 * cent_r;
		((t_data *)param)->min_i += (cent_i - 2 * cent_i) / 2;
		((t_data *)param)->max_i = ((t_data *)param)->min_i + 2 * cent_i;
	}
	printf("\nmax_re= %f\nmin_re = %f\nmax_i = %f\nmin_i = %f\n*******zoom", ((t_data *)param)->max_re, ((t_data *)param)->min_re, ((t_data *)param)->max_i, ((t_data *)param)->min_i);
	ft_select_fractal((t_data *)param);
}
