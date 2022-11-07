/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:33:29 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/07 15:11:36 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlist;
	t_list	*a;

	(void) d;
	newlist = NULL;
	if (l->content)
	{
		while (l)
		{
			a = ft_lstnew(f(l->content));
			if (!a)
				return (NULL);
			ft_lstadd_back(&newlist, a);
			l = l->next;
		}
	}
	return (newlist);
}
