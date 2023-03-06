/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:13:19 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/03 10:31:44 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*hay;
	unsigned char	*nee;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	hay = (unsigned char *) haystack;
	nee = (unsigned char *) needle;
	if (ft_strlen(needle) == 0)
		return ((char *)hay);
	while (hay[i] != 0 && i < len)
	{
		j = 0;
		while (nee[j] == hay[i + j] && nee[j] != 0 && j < len - i
			&& hay[i + j] != 0)
		{
			if (nee[j + 1] == 0)
				return ((char *)&hay[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char *hay = "Hola Mundo";
	char *nee = "Mundo";

	puts(strnstr(hay, nee, 10));
	puts(ft_strnstr(hay, nee, 10));
}
*/
