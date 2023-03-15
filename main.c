/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/15 15:22:26 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_module(float r, float i)
{
	return ((r * r) + (i * i));
}

int	ft_color(int i)
{
	if (i >= MAX_ITER - 1)
		return (0x000000ff);
	else
		return (0x80ff80ff + (i * 0x10100000));
}

void	leaks(void)
{
	system("leaks fractol");
}

int32_t	main(void)
{
	t_data		data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	ft_memset(data.img->pixels, 255,
		data.img->width * data.img->height * sizeof(int));
	ft_mandelbrot_set(&data);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	atexit(leaks);
	return (EXIT_SUCCESS);
}
