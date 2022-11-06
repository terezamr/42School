/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:33:29 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/06 18:11:40 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*a;

	(void) del;
	newlist = NULL;
	if (lst->content)
	{
		while (lst)
		{
			a = ft_lstnew(f(lst->content));
			if (!a)
				return (NULL);
			ft_lstadd_back(&newlist, a);
			lst = lst->next;
		}
	}
	return (newlist);
}
