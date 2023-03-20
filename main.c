/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/20 21:12:10 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_module(float r, float i)
{
	return ((r * r) + (i * i));
}

int	ft_color(int i, int color)
{
	int	color_set[5] = {0x80ff80ff, 0x8a601dff, 0xe6c329ff,
		0xd9331aff, 0x1932c2ff};

	if (i >= MAX_ITER - 1)
		return (0x000000ff);
	else
		return (color_set[(color % 5)] + (i * 0x10100000));
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
		ft_mandelbrot_set((t_data *)param);
	}
}

int32_t	main(void)
{
	t_data		data;

	data.color = 0;
	data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	ft_memset(data.img->pixels, 255,
		data.img->width * data.img->height * sizeof(int));
	ft_mandelbrot_set(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_key_hook(data.mlx, &ft_key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	atexit(leaks);
	return (EXIT_SUCCESS);
}
