/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:12:55 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/21 10:13:06 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
#include<stdio.h>
#include<ctype.h>
int main(int argc, char *argv[])
{
	(void)argc;
	if(isprint(argv[1][0]) == ft_isprint(argv[1][0]))
	{
		printf("%s", "OK!\n");
	}else
	{
		printf("%s", "KO!\n");
	}
	printf("%d", ft_isprint(argv[1][0]));
}
*/
