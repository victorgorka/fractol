/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/14 17:55:58 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_module(float r, float i)
{
	return ((r * r) + (i * i));
}

int	ft_mandelbrot(t_data *data)
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
	return (i);
}

void	ft_mandelbrot_set(t_data *data)
{
	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			data->c_r = MIN_RE + data->x * (MAX_RE - MIN_RE) / (WIDTH - 1);
			data->c_i = MAX_I - data->y * (MAX_I - MIN_I) / (HEIGHT - 1);
			if (ft_mandelbrot(data) >= MAX_ITER - 1)
				mlx_put_pixel(data->img, data->x, data->y, 0x000000ff);
			data->x++;
		}
		data->y++;
	}
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
	return (EXIT_SUCCESS);
}
