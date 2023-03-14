/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:00:53 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/09 12:04:55 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	while (s_len)
	{
		if (s[s_len - 1] == (unsigned char)c)
			return ((char *)&s[s_len - 1]);
		s_len--;
	}
	return (0);
}
/*
#include<stdio.h>
int main()
{
	char	*s = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	puts(ft_strrchr(s, '\0'));
}
*/
