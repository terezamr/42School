/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:33:29 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/17 11:40:29 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Ft_lstmap() iterates through a linked list, applies a function to each element, and returns a new
 * linked list with the results
 * 
 * @param l the list to iterate over
 * @param f a function that takes a void pointer and returns a void pointer
 * @param d a function that will be called on the content of the list when the list is freed.
 * 
 * @return A pointer to the first element of the new list.
 */
t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlist;
	t_list	*a;

	newlist = 0;
	while (l)
	{
		a = ft_lstnew(f(l->content));
		if (!a)
		{
			ft_lstclear(&l, d);
			return (0);
		}
		ft_lstadd_back(&newlist, a);
		l = l->next;
	}
	return (newlist);
}
