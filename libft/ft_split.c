/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:45:28 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/17 16:40:05 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include "libft.h"
#include <stdio.h>

static unsigned int	ft_nstrings(char const *s, char c)
{
	unsigned int	res;
	unsigned int	sep;

	sep = 0;
	res = 0;
	while (*s)
	{
		if (*s != c && sep == 0)
		{
			res++;
			sep = 1;
		}
		else if (*s == c)
			sep = 0;
		s++;
	}
	return (res);
}

char	**ft_settab(char const *s, char const *cpy, char **tab)
{
	unsigned int	i;
	unsigned int	tabindex;
	unsigned int	aux;

	aux = 0;
	tabindex = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (cpy[i] != '\0' && aux == 0)
		{
			tab[tabindex] = ft_strdup(&cpy[i]);
			aux = 1;
			tabindex++;
		}
		else if (cpy[i] == '\0')
			aux = 0;
		i++;
	}	
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	char			*cpy;

	cpy = (char *)ft_strdup(s);
	i = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((ft_nstrings(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (cpy[i])
	{
		if (cpy[i] == c)
			cpy[i] = '\0';
		i++;
	}
	tab = ft_settab(s, cpy, tab);
	tab[ft_nstrings(s, c)] = NULL;
	free(cpy);
	return (tab);
}
/*
int	main(void)
{
	//char	*s = "      split       this for   me  !       ";
	char	**ret = ft_split("  tripouille  42  ", ' ');
	//	printf("%d", ft_nstrings(s, ' '));
	printf("%s\n", ret[0]);
	printf("%s\n", ret[1]);
	printf("%s\n", ret[2]);
	free(ret);
}
*/
