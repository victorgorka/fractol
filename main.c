/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/04 15:54:15 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_select_fractal(t_data *data)
{
	if (data->fract_type == 'm')
		ft_mandelbrot_set(data);
	else if (data->fract_type == 'j')
	{
		ft_set_julia(data);
		ft_julia_set(data);
	}
	else if (data->fract_type == 'b')
		ft_burningship_set(data);
}

void	ft_check_input(t_data *data)
{
	char	*buff;

	buff = get_next_line(0);
	if (buff[0] == 'j' && buff[1] >= '0' && buff[1] <= '3'
		&& ft_strlen(buff) == 3)
	{
		data->fract_type = 'j';
		if (buff[1] == '0')
			data->julia_type = 0;
		else if (buff[1] == '1')
			data->julia_type = 1;
		else if (buff[1] == '2')
			data->julia_type = 2;
		else if (buff[1] == '3')
			data->julia_type = 3;
	}
	else if (!ft_strncmp(buff, "m\n", ft_strlen(buff)))
		data->fract_type = 'm';
	else if (!ft_strncmp(buff, "b\n", ft_strlen(buff)))
		data->fract_type = 'b';
	else if (ft_strlen(buff) == 1)
		ft_exit(0, buff);
	else
		ft_exit(1, buff);
	free(buff);
}

void	ft_init_data(t_data *data)
{
	data->color = 0;
	data->width = 1000;
	data->height = 700;
	data->max_iter = 80;
	data->max_re = 1.0;
	data->min_re = -2.0;
	data->min_i = -1.2;
	data->max_i = 1.2;
	if (data->fract_type == 'j')
	{
		data->max_re = 1.7;
		data->min_re = -1.7;
		data->min_i = -1.2;
		data->max_i = data->min_i + (data->max_re - data->min_re)
			* data->height / data->width;
	}
	else if (data->fract_type == 'b')
	{
		data->max_re = 2.5;
		data->min_re = -1.5;
		data->min_i = -1.0;
		data->max_i = data->min_i + (data->max_re - data->min_re)
			* data->height / data->width;
	}
}

int32_t	main(void)
{
	t_data		data;

	ft_check_input(&data);
	ft_init_data(&data);
	data.mlx = mlx_init(data.width, data.height, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	ft_memset(data.img->pixels, 255,
		data.img->width * data.img->height * sizeof(int));
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	ft_select_fractal(&data);
	mlx_key_hook(data.mlx, &ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, &ft_scroll, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
