/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:16:15 by vde-prad          #+#    #+#             */
/*   Updated: 2022/07/07 15:12:58 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_putnbru(unsigned long n)
{
	long			numb;
	unsigned int	len;

	len = 0;
	numb = n;
	if (numb <= 9)
	{
		ft_putchar((numb + '0'));
		len++;
	}
	else
	{
		len += ft_putnbr(numb / 10);
		ft_putchar((numb % 10) + '0');
		len++;
	}
	return (len);
}

unsigned int	ft_putnbr(int n)
{
	long			numb;
	unsigned int	len;

	len = 0;
	numb = n;
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		numb *= -1;
	}
	if (numb <= 9)
	{
		ft_putchar((numb + '0'));
		len++;
	}
	else
	{
		len += ft_putnbr(numb / 10);
		ft_putchar((numb % 10) + '0');
		len++;
	}
	return (len);
}
/*
int main()
{
	ft_putnbr(-2147483648);
}
*/
