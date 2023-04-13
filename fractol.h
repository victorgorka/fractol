/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:42:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/13 14:40:15 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
//*********************** STANDARD LIBRARIES *********************************
# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
//************************** DEFINITIONS *************************************
# define WIDTH 1000
# define HEIGHT 700

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		fract_type;
	int			julia_type;
	int			x;
	int			y;
	int			color;
	int			max_iter;
	float		max_re;
	float		min_re;
	float		max_i;
	float		min_i;
	float		z_r;
	float		z_i;
	float		c_r;
	float		c_i;
}	t_data;

//*************************** FUNCTIONS **************************************

//depending on the number of iterations that were necessary to determine if
// it is within the set of the fractal
int		ft_color(int i, int color, t_data *data);

// Simply calculates the module of the vector from '0 + 0i' to 'r + i' passed
// to the function
float	ft_module(float r, float i);

// loops through each pixel and determines which pixel is within the set and
// which is not, and print each pixel in the image
void	ft_mandelbrot_set(t_data *data);

// loops through each pixel and determines which pixel is within the set and
// which is not, and print each pixel in the image
void	ft_julia_set(t_data *data);

// loops through each pixel and determines which pixel is within the set and
// which is not, and print each pixel in the image
void	ft_burningship_set(t_data *data);

// Transforms the cartesian coordinates to the complex plane
void	ft_cart_to_comp(t_data *data);

// Transforms the cartesian coordinates to the complex plane specificaly for
// Julia set
void	ft_cart_to_comp_jul(t_data *data);

// If input by CLI is not valid, this function print a message on stderror or
// stdout depending on the case and free memory of 'buff' variable
void	ft_exit(int n, char *buff);

// This function set the julia parameters for each julia set I selected
void	ft_set_julia(t_data *data);

// Depending on wich fractal was selected in using the CLI, it call the specific
// function that render the fractal selected
void	ft_select_fractal(t_data *data);

// It handels the scroll for zoom implementation
void	ft_scroll(double xdelta, double ydelta, void *param);

// It handles the key usage for direction movement and ESC key to terminate the
// program
void	ft_key_hook(mlx_key_data_t keydata, void *param);

// It detects which key was pressed and it changes some parameters for the next
// rendering
void	ft_arrows(mlx_key_data_t keydata, t_data *data);
#endif
