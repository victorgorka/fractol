/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:49:35 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/07 12:00:53 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include<stdio.h>
int main()
{
	
	t_list	*a, *b, *c, *z;

	z = ft_lstnew("0");
	c = ft_lstnew("15");
	b = ft_lstnew("10");	
	a = ft_lstnew("5");
	b->next = c;
	a->next = b;
	ft_lstadd_front(&a, z);
	puts(z->next->content);
	

	t_list *list;

	ft_lstadd_front(&list, ft_lstnew("15"));
	ft_lstadd_front(&list, ft_lstnew("10"));
	ft_lstadd_front(&list, ft_lstnew("5"));
	ft_lstadd_front(&list, ft_lstnew("0"));
	puts(list->content);
}
*/
