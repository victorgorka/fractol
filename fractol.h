/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:42:37 by vde-prad          #+#    #+#             */
/*   Updated: 2023/03/10 18:38:03 by vde-prad         ###   ########.fr       */
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
# define HEIGHT 1000

typedef struct s_data
{
	float	x;
	float	y;
	float	z_r;
	float	z_i;
}	t_data;

//*************************** FUNCTIONS **************************************

#endif