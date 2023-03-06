/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:25:57 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/28 11:05:07 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*gooddst;
	const char	*goodsrc;

	goodsrc = src;
	gooddst = dst;
	if (dst == src || !n)
		return (dst);
	while (n-- > 0)
	{
		*gooddst++ = *goodsrc++;
	}
	return (dst);
}
/*
#include<stdio.h>
int main(void)
{
	char	dst1[100] = "";
	char	src1[] = "hola";
	char	dst2[100] = "";
	char	src2[] = "hola";


	ft_memcpy(dst1, src1, 0);
	memcpy(dst2, src2, 0);
	if(strcmp(dst1, dst2) == 0)
		puts("OK!");
	else
		puts("KO!");
	puts(dst1);
	puts(dst2);
}
*/
