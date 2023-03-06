/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:10:06 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/09 15:07:46 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char s1[] = {0, 1, 2 ,3 ,4 ,5};
	char s2[] = {0, 1, 2 ,3 ,4 ,5};
	puts(memchr(s1, 0, 0));
	puts(ft_memchr(s2, 0, 0));
}
*/
