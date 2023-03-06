/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:27:26 by vde-prad          #+#    #+#             */
/*   Updated: 2022/04/21 09:52:45 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	if(ft_isascii(argv[1][0]) == isascii(argv[1][0]))
	{
		printf("%s", "OK!\n");
	}else
	{
		printf("%s", "KO!\n");
	}
	printf("%d", ft_isascii(argv[1][0]));
}
*/
