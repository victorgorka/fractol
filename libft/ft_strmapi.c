/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:47:34 by vde-prad          #+#    #+#             */
/*   Updated: 2022/05/26 20:01:26 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen(s);
	i = 0;
	res = ft_strdup(s);
	if (!res)
		return (0);
	while (i < size)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}

/*
int main()
{
	char *str = "hola perita";
	char *res = ft_strmapi(str, fun);

	puts( res);
}
*/
