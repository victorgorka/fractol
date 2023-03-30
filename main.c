/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/30 16:52:54 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_module(float r, float i)
{
	return ((r * r) + (i * i));
}

int	ft_color(int iter, int color)
{
	int	color_set[5];

	color_set[0] = 0x1932c2ff;
	color_set[1] = 0x8a601dff;
	color_set[2] = 0x80ff80ff;
	color_set[3] = 0x0fd697ff;
	color_set[4] = 0xd9331aff;
	if (iter >= MAX_ITER - 1)
		return (0x000000ff);
	else
		return (color_set[(color % 5)] + (iter * 0x03030000));
}

void	leaks(void)
{
	system("leaks fractol");
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		((t_data *)param)->color++;
		ft_julia_set((t_data *)param);
	}
}

int32_t	main(void)
{
	t_data		data;

	data.color = 0;
	data.width = 1700;
	data.height = 1500;
	data.max_iter = 100;
	data.max_re = 2.0;
	data.min_re = -2.0;
	data.max_i = 2.2;
	data.min_i = -2.2;
	data.mlx = mlx_init(data.width, data.height, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	ft_memset(data.img->pixels, 255,
		data.img->width * data.img->height * sizeof(int));
	ft_julia_set(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_key_hook(data.mlx, &ft_key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	atexit(leaks);
	return (EXIT_SUCCESS);
}
