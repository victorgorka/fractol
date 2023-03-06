/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:45:09 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/26 16:18:18 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned char	*goodp;

	goodp = (unsigned char *)b;
	while (len--)
		*goodp++ = c;
	return (b);
}
/*
#include<libc.h>
#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char	str1[100];
	char	str2[100];


	memset(str1, 'A', 1);
	ft_memset(str2, 'A', 1);
	if(strcmp(str1, str2) == 0)
	{
		printf("%s", "OK!\n");
	}else
	{
		printf("%s", "KO!\n");
	}
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%d", strcmp(str1, str2));
}
*/
