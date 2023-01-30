/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/30 17:18:04 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack)
{
	int	index;
	int	number;

	index = stack->index;
	number = stack->number;
	while (stack)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		if (stack->number > number)
			index = stack->index;
	}
	return (index);
}

t_list	*sorting(t_list *a, t_list **b, int argc)
{
	int	n;
	int	middle;
	int	offset;
	int	start;
	int	end;
	int	index;

	if (argc <= 10)
		n = 5;
	else if (argc <= 150)
		n = 8;
	else
		n = 18;
	middle = argc / 2;
	offset = argc / n;
	start = middle - offset;
	end = middle + offset;
	while (a)
	{
		while (argc != 0)
		{
			if (a->number >= start && a->number <= end)
				a = push(a, &b[0]);
			else if (ft_lstlast(a)->index != 1)
				a = rotate(a);
			argc--;
		}
		if (a != NULL)
			argc = ft_lstlast(a)->index;
		start = start - offset;
		end = end + offset;
	}
	while (*b)
	{
		index = get_max(*b);
		if (a == NULL || index == 1)
			*b = push(*b, &a);
		else if (b[0]->number > ft_lstlast(a)->number)
		{
			printf("check first\n");
			*b = push(*b, &a);
			if (ft_lstlast(a)->index != 1)
				a = rotate(a);
			printf("check second\n");
		}
		else if (ft_lstlast(b[0])->index != 1)
		{
			*b = rotate(*b);
			printf("check third\n");
		}
	}
	return (a);
}
