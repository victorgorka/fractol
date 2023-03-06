/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:49:09 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/29 13:41:15 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	size;

	if (ft_strlen(src) < dstsize)
		size = ft_strlen(src);
	else
		size = dstsize - 1;
	if (dstsize != 0)
	{
		ft_memcpy(dst, src, size);
		dst[size] = 0;
	}
	return (ft_strlen(src));
}
/*
#include<string.h>
#include<stdio.h>
int main(void)
{
	char dst1[100] = "";
	char src1[100] = "adios";
	char dst2[100] = "";
	char src2[100] = "adios";
	printf("%lu\n",strlcpy(dst1, src1, 3));
	printf("%lu\n",ft_strlcpy(dst2, src2, 3));
	puts(dst1);
	puts(dst2);
}
*/
