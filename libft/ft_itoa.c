/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:15:47 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/25 13:15:24 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_digit_counter(long *n, unsigned int *i, unsigned int *sign)
{
	int	aux;

	if (*n < 0)
	{
		(*i)++;
		*sign = 1;
		*n *= -1;
	}
	aux = *n;
	if (*n == 0)
		*i = 1;
	while (aux != 0)
	{
		(*i)++;
		aux /= 10;
	}
}

static char	*ft_getstring(char *res, long n, unsigned int i)
{
	res[i] = 0;
	i--;
	while (n > 9)
	{
		res[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (n <= 9)
		res[i] = n + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	sign;
	char			*res;
	long			num;

	num = n;
	sign = 0;
	i = 0;
	ft_digit_counter(&num, &i, &sign);
	res = (char *)malloc(i + 1 * sizeof(char));
	if (!res)
		return (0);
	res = ft_getstring(res, num, i);
	if (sign == 1)
		res[0] = '-';
	return (res);
}
/*
#include <stdio.h>
int main()
{	
	char	*res;

	res = ft_itoa(-2147483647 -1);
	puts(res);
	free(res);
}
*/
