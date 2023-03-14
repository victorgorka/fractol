/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:38:25 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/17 16:29:08 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s);
	if (start > ft_strlen(s) || !s)
		return (ft_strdup(""));
	if ((length - start) > len)
		size = len + 1;
	else
		size = length - start + 1;
	if (start >= length)
		size = 1;
	sub = malloc((size) * sizeof(char));
	if (sub == 0)
		return (NULL);
	while (s[start + i] && i < len && start < length)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

/*
Reserva (con malloc(3)) y devuelve una substring de
la string ’s’.
La substring empieza desde el índice ’start’ y
tiene una longitud máxima ’len’.
*/
