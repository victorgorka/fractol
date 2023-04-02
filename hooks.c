/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:52:22 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/02 22:33:52 by vde-prad         ###   ########.fr       */
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
		data->max_re += 0.1;
		data->min_re += 0.1;
	}	
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_re -= 0.1;
		data->min_re -= 0.1;
	}
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_i += 0.1;
		data->min_i += 0.1;
	}
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_RELEASE)
	{
		data->max_i -= 0.1;
		data->min_i -= 0.1;
	}
	ft_select_fractal(data);
}

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	(void)xdelta;
	if (ydelta > 0)
	{
		((t_data *)param)->max_re -= 0.1;
		((t_data *)param)->min_i += 0.1;
		((t_data *)param)->max_re -= 0.1;
		((t_data *)param)->min_i += 0.1;
	}
	else if (ydelta < 0)
	{
		((t_data *)param)->max_re += 0.1;
		((t_data *)param)->min_i -= 0.1;
		((t_data *)param)->max_re += 0.1;
		((t_data *)param)->min_i -= 0.1;
	}
	ft_select_fractal((t_data *)param);
}
