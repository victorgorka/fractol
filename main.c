/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:55:19 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/13 17:05:36 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	- Each time is necessary to render the fractal, this function is called
	  and will render the fractal type that was selected in the CLI
*/
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

/*
	- The input from CLI is read by get_next_line function
	- Depending on input, the variable 'fract_type' and
	  'julia_type' is set
	- If input is not correct, the control passes to ft_exit
*/
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

/*
	- The necessary fractals data is initialized
	- Depending of which fractal is selected
	- In case of Burningship fractal, 'max_i' is stablished in a different way.
		- The sum has two addend:
			1st (data->min_i)
			2nd ((data->max_re - data->min_re) * HEIGHT / WIDTH)
		- In the 2nd we got the total lenght of the real part of the complex
		  plane (ex. 3.4 total Real axis) in the first subtract in the parenthesis.
		  But for the Img axis, we are going to stablish a proportion of approx 2/3
		  of real axis. That's why we do the product of the total lenght of Real axis
		  (ex. 3.4) and the quotient of HEIGHT / WIDTH (2/3 approx in my case). With
		  the whole operation (the product of the subtraction and the quotient) we got
		  the total lenght of Imaginary axis
		- The first addend is necessary because in the 2nd addend we only got the total
		  lenght of Img axis, but we only want the upper half of the Img axis, that is,
		  'max_i'. That's why we sum (but its negative, so its a subtract) min_i to the
		  total lenght of Img axis that we got in the second addend.
	Good luck in your fract-ol implementation :]
*/
void	ft_init_data(t_data *data)
{
	data->color = 0;
	data->max_iter = 80;
	data->max_re = 1.2;
	data->min_re = -2.2;
	data->min_i = -1.2;
	data->max_i = 1.2;
	if (data->fract_type == 'j')
	{
		data->max_re = 1.7;
		data->min_re = -1.7;
		data->min_i = -1.2;
		data->max_i = data->min_i + (data->max_re - data->min_re)
			* HEIGHT / WIDTH;
	}
	else if (data->fract_type == 'b')
	{
		data->max_re = 2.5;
		data->min_re = -1.5;
		data->min_i = -1.0;
		data->max_i = data->min_i + (data->max_re - data->min_re)
			* HEIGHT / WIDTH;
	}
}

/*
	- t_data type structure is declared, its initialized
	- the input from CLI is checked in in ft_check_input
	- MLX internal data is initialized and a new image is created.
	- mlx_image_to_window: its used to display the image in a window.
	- mlx_key_hook: its used to control the key use.
	- mlx_scroll_hook: its used to control scroll use.
	- mlx_loop: maintain the the program in execution until we close the window.
	- mlx_terminate: free MLX data memory.
*/
int32_t	main(void)
{
	t_data		data;

	ft_check_input(&data);
	ft_init_data(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	ft_select_fractal(&data);
	mlx_key_hook(data.mlx, &ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, &ft_scroll, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}
