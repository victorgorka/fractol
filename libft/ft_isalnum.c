/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:26:16 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/28 12:21:05 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
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
	if(ft_isalnum(argv[1][0]) == isalnum(argv[1][0]))
	{
		printf("%s", "OK!\n");
	}else
	{
		printf("%s", "KO!\n");
	}
	printf("%d", ft_isalnum(argv[1][0]));
}
*/
