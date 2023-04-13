/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:57:38 by vde-prad          #+#    #+#             */
/*   Updated: 2023/04/13 12:40:14 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_burningship(t_data *data)
{
	float	tmp_r;
	int		i;

	i = 0;
	data->z_r = 0;
	data->z_i = 0;
	while (i < data->max_iter && ft_module(data->z_r, data->z_i) < 4)
	{
		if (data->z_r < 0)
			data->z_r = data->z_r * -1;
		if (data->z_i < 0)
			data->z_i = data->z_i * -1;
		tmp_r = (data->z_r * data->z_r) - (data->z_i * data->z_i) - data->c_r;
		data->z_i = 2 * data->z_r * data->z_i - data->c_i;
		data->z_r = tmp_r;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	ft_burningship_set(t_data *data)
{
	int	i;

	data->y = 0;
	while (data->y < HEIGHT)
	{
		data->x = 0;
		while (data->x < WIDTH)
		{
			ft_card_to_comp(data);
			i = ft_burningship(data);
			mlx_put_pixel(data->img, data->x,
				data->y, ft_color(i, data->color, data));
			data->x++;
		}
		data->y++;
	}
}
