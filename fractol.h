/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:42:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/30 16:26:38 by vde-prad         ###   ########.fr       */
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
# define WIDTH 1700
# define HEIGHT 1400
# define MAX_ITER 1500
# define MAX_RE 2.0
# define MIN_RE -2.0
# define MAX_I 2.2
# define MIN_I -2.2

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
	int			color;
	int			width;
	int			height;
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
void	ft_mandelbrot_set(t_data *data);
int		ft_color(int i, int color);
float	ft_module(float r, float iter);
void	ft_julia_set(t_data *data);
#endif