/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:33:29 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/16 11:31:42 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*newlist;
	t_list	*a;

	newlist = 0;
	(void) d;
	while (l)
	{
		a = ft_lstnew(f(l->content));
		if (!a)
			return (0);
		ft_lstadd_back(&newlist, a);
		l = l->next;
	}
	return (newlist);
}
