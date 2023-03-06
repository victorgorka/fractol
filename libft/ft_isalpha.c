/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:25:14 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/26 13:12:26 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>
int main(int argc, char *argv[])
{
	(void)argc;
	if(isalpha(argv[1][0]) == ft_isalpha(argv[1][0]))
	{
		printf("%s", "OK!\n");
	}else
	{
		printf("%s", "KO!\n");
	}
	printf("%d", ft_isalpha(argv[1][0]));
}
*/
