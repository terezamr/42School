/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:34 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/24 13:26:53 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	a = NULL;
	if (!lst || !new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		a = ft_lstlast(*lst);
		a->next = new;
		new->prev = a;
	}
}

t_list	*ft_lstnew(int new_number, int i)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->index = i;
	p->number = new_number;
	p->prev = NULL;
	p->next = NULL;
	return (p);
}
