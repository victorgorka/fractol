/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:52:22 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/04 14:40:39 by vde-prad         ###   ########.fr       */
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

static void	ft_calculate_arrows(t_data *data, char key)
{
	float	cent_r;
	float	cent_i;

	cent_r = data->min_re - data->max_re;
	cent_i = data->max_i - data->min_i;
	if (key == 'D')
	{
		data->max_re -= cent_r * 0.1;
		data->min_re -= cent_r * 0.1;
	}
	else if (key == 'A')
	{
		data->max_re += cent_r * 0.1;
		data->min_re += cent_r * 0.1;
	}
	else if (key == 'W')
	{
		data->max_i += cent_i * 0.1;
		data->min_i += cent_i * 0.1;
	}
	else if (key == 'S')
	{
		data->max_i -= cent_i * 0.1;
		data->min_i -= cent_i * 0.1;
	}
}

void	ft_arrows(mlx_key_data_t keydata, t_data *data)
{
	if ((keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		&& keydata.action == MLX_RELEASE)
	{
		ft_calculate_arrows(data, 'D');
		ft_select_fractal(data);
	}
	else if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		&& keydata.action == MLX_RELEASE)
	{
		ft_calculate_arrows(data, 'A');
		ft_select_fractal(data);
	}
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		&& keydata.action == MLX_RELEASE)
	{
		ft_calculate_arrows(data, 'W');
		ft_select_fractal(data);
	}
	else if ((keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		&& keydata.action == MLX_RELEASE)
	{
		ft_calculate_arrows(data, 'S');
		ft_select_fractal(data);
	}
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
	ft_select_fractal((t_data *)param);
}
