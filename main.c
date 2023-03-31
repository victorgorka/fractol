/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/31 19:22:23 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks fractol");
}

static void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		((t_data *)param)->color++;
		ft_julia_set((t_data *)param);
	}
}

void	ft_select_fractal(t_data *data)
{
	char	buff[42];

	read(0, buff, 42);
	if (ft_strlen(buff) == 2 && buff[0] == 'j'
		&& buff[1] >= '0' && buff[1] <= '4')
	{
		data->fract_type = 'j';
		data->julia_type = ft_atoi(&buff[1]);
	}
	else if (ft_strlen(buff) == 1 && buff[0] == 'm')
		data->fract_type = 'm';
	else if (buff[0] == '' || buff[0] == NULL)
	{
		ft_putstr_fd("m = Mandelbrot\n j[0...5] = fractales de Julia", 1);
		mlx_terminate(data->mlx);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error, argumento no valido", 2);
		mlx_terminate(data->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_exec_fractal(t_data *data)
{

}

void	ft_init_data(t_data *data)
{
	data->color = 0;
	data->width = 1700;
	data->height = 1500;
	data->max_iter = 100;
	data->max_re = 2.0;
	data->min_re = -2.0;
	data->max_i = 2.2;
	data->min_i = -2.2;
}

int32_t	main(int argc, char	**argv)
{
	t_data		data;

	data.mlx = mlx_init(data.width, data.height, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	ft_memset(data.img->pixels, 255,
		data.img->width * data.img->height * sizeof(int));
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	ft_select_fractal(&data);
	mlx_key_hook(data.mlx, &ft_key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	atexit(leaks);
	return (EXIT_SUCCESS);
}
