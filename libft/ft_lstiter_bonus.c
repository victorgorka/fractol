/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:12:00 by vde-prad          #+#    #+#             */
/*   Updated: 2022/06/17 18:37:50 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main()
{
	t_list *start;
	t_list *uno, *dos, *tres;

	uno = ft_lstnew("0");
	dos = ft_lstnew("5");
	tres = ft_lstnew("10");

	ft_lstadd_front(&start, tres);
	ft_lstadd_front(&start, dos);
	ft_lstadd_front(&start, uno);

	ft_lstiter(start, &ft_printcontent);
}
*/
