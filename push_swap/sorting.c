/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/08 14:50:17 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*check_range(t_list *a, t_list **b, int start, int offset)
{
	int	aux;
	int	end;

	end = start + (offset * 2);
	aux = (end - offset) * 2;
	if (a->position >= start && a->position <= end)
	{
		a = push(a, b, 'b');
		if ((*b)->position <= aux / 2 && ft_lstlast(*b)->index != 1)
			*b = rotate(*b, 'b');
	}
	else if (ft_lstlast(a)->index != 1)
		a = rotate(a, 'a');
	return (a);
}

t_list	*atob(t_list *a, t_list **b, int argc, int offset)
{
	int	aux;
	int	middle;

	middle = argc / 2;
	aux = argc;
	while (a)
	{
		while (argc != 0)
		{
			a = check_range(a, b, middle - offset, offset);
			argc--;
		}
		if (a)
			argc = ft_lstlast(a)->index;
		offset = offset * 2;
	}
	return (a);
}

t_list	*btoa(t_list *a, t_list **b)
{
	int	index;
	int	middle;
	int	max;

	while (*b)
	{
		index = get_max(*b, &max);
		middle = ft_lstlast(*b)->index / 2;
		if (index == 1)
			*b = push(*b, &a, 'a');
		else if (ft_lstlast(*b)->index != 1)
		{
			if (index <= middle)
				*b = rotate(*b, 'b');
			else
				*b = reverse_rotate(*b, 'b');
		}
	}
	return (a);
}

t_list	*sorting(t_list *a, t_list **b, int argc, int n)
{
	int	offset;

	offset = argc / n;
	if (argc == 2)
		return (sort_two(a));
	if (argc == 3)
		return (sort_three(a));
	if (argc <= 5)
		return (sort_five(a, b, argc));
	a = atob(a, b, argc, offset);
	a = btoa(a, b);
	return (a);
}
