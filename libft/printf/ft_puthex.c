/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:43:03 by vde-prad          #+#    #+#             */
/*   Updated: 2022/07/25 11:53:07 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_puthex(const char *str, unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(str, n / 16);
		len += ft_puthex(str, n % 16);
	}
	else
	{	
		ft_putchar(str[n]);
		len++;
	}
	return (len);
}
/*
#include <stdio.h>
int main()
{
	unsigned int	len = ft_puthex("0123456789abcdef", 42);
	printf("\n%d", len);
}
*/
