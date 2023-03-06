/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:56:01 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/27 13:47:50 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*gooddst;
	unsigned char	*goodsrc;

	gooddst = (unsigned char *)dst;
	goodsrc = (unsigned char *)src;
	if (dst == src || !len)
		return (dst);
	if (gooddst < goodsrc)
	{
		while (len--)
		*gooddst++ = *goodsrc++;
	}
	else
	{	
		while (len--)
			gooddst[len] = goodsrc[len];
	}
	return (dst);
}
/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	char	dst1[100] = "Holaa";
	char	src1[] = "Mu";
	//char	dst2[10] = "";
	//char	src2[] = "";
	memmove(dst1, src1, 6);
	//ft_memmove(dst2, src2, 6);
	puts(dst1);
	//puts(dst2);
}
*/
