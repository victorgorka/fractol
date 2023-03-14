/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:28:17 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/15 16:49:07 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	n;

	n = 0;
	while (*dst != '\0' && dstsize != 0)
	{
		dst++;
		n++;
		dstsize--;
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
		n++;
	}
	while (*src)
	{
		n++;
		src++;
	}
	if (dstsize)
		*dst = '\0';
	return (n);
}
/*
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int	main()
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	printf("%lu\n", strlcat(dest, "lorem ipsum dolor sit amet", 6));
	write(1, "\n", 1);
	write(1, dest, 15);
}
*/
