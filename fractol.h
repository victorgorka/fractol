/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:42:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/14 17:17:14 by vde-prad         ###   ########.fr       */
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
# define WIDTH 1500
# define HEIGHT 1000
# define MAX_ITER 100
# define MAX_RE 1.0
# define MIN_RE -2.0
# define MAX_I 1.0
# define MIN_I -1.0

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			x;
	int			y;
	float		z_r;
	float		z_i;
	float		c_r;	
	float		c_i;
}	t_data;

//*************************** FUNCTIONS **************************************

#endif