/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:25:34 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/27 10:53:58 by mvicente         ###   ########.fr       */
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
	t_list	*aux;

	aux = NULL;
	if (!lst || !new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		aux = ft_lstlast(*lst);
		aux->next = new;
		new->prev = aux;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	else if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		new->prev = NULL;
		lst[0]->prev = new;
		*lst = new;
	}
}	

t_list	*ft_lstnew(int new_number, int i)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->index = i;
	new->number = new_number;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	free_lists(t_list *a, t_list *b)
{
	t_list	*ptr;

	while (a)
	{
		ptr = a->next;
		free(a);
		a = ptr;
	}
	while (b)
	{
		ptr = b->next;
		free(b);
		b = ptr;
	}
}
