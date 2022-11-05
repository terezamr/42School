/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:47:30 by mvicente          #+#    #+#             */
/*   Updated: 2022/11/05 18:18:22 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	a;

	a = 0;
	while (a < ft_lstsize(lst) && lst)
	{
		lst = lst->next;
		a++;
	}
	return (lst);
}

	