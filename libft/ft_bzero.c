/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 19:50:36 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/22 20:25:20 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<strings.h>

void	ft_bzero(void *s, size_t n)
{
	char	*goods;

	goods = s;
	while (n-- > 0)
	{
		*goods++ = 0;
	}	
}
/*
#include<libc.h>
#include<stdio.h>
int main(void)
{
	char str1[] = "Hello World";
	char str2[] = "Hello World";
	int	zeroes = 4;
	int	check = 0;
	unsigned long int i = 0;
	unsigned long int len = strlen(str1);

	
	bzero(str1, zeroes);
	ft_bzero(str2, zeroes);
	while (i++ < len)
	{
		if(str1[i] == str2[i])
		{	
		}
		else
		{
			check = 1;
			break;
		}
	}

	printf("%d", check);
}
*/
