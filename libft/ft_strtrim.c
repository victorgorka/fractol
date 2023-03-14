/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:23 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/12 13:43:45 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_find_char(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(s1) - 1;
	i = 0;
	while (ft_find_char(s1[i], set))
	{
		i++;
	}
	while (ft_find_char(s1[len], set))
	{
		len--;
		j++;
	}
	return (ft_substr(s1, i, ft_strlen(s1) - i - j));
}
/*
#include<stdio.h>
int	main(void)
{
	char	str[] = "lorem \n ipsum \t dolor \n sit \t amet";
	char	set[] = " ";

	puts(ft_strtrim(str, set));
}
*/
