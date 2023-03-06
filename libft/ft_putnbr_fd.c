/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:16:15 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/27 14:20:45 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;

	numb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		numb *= -1;
	}
	if (numb <= 9)
	{
		ft_putchar_fd((numb + '0'), fd);
	}
	else
	{
		ft_putnbr_fd((numb / 10), fd);
		ft_putchar_fd((numb % 10) + '0', fd);
	}
}
/*
int main()
{
	ft_putnbr_fd(-2147483648, 1);
}
*/