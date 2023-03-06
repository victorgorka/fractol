/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:33:42 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/07 17:03:35 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//no hago new->next = 0; porque me hace segfault
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plast;

	if (*lst == 0)
		*lst = new;
	else
	{
		plast = ft_lstlast(*lst);
		plast->next = new;
	}
}
