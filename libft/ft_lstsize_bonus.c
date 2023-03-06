/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:24:54 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/07 12:00:18 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//return the size of the list
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 1;
	if (lst == 0)
		return (0);
	while (lst->next != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
