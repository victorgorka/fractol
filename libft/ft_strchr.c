/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:59:17 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/12 13:59:00 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[] = "";
	puts(strchr(s, '\0'));
	puts(ft_strchr(s, '\0'));
}
*/
