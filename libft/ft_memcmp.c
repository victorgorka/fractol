/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:09:52 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/02 18:11:29 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		c1 = (unsigned char *) s1;
		c2 = (unsigned char *) s2;
		if (*c1 != *c2)
			return (*c1 - *c2);
		s1++;
		s2++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
	char	*str1 = "Hola Mondo";
	char	*str2 = "Hola Mundo";

	printf("%d\n", memcmp(str1, str2, 10));	
	printf("%d\n", ft_memcmp(str1, str2, 10));
}
*/
