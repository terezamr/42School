/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/31 15:30:03 by mvicente         ###   ########.fr       */
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
		{
			index = stack->index;
			number = stack->number;
		}
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
			{
				a = push(a, &b[0]);
				printf("pb\n");
				if (b[0]->number <= middle && ft_lstlast(b[0])->index != 1)
				{
					*b = rotate(*b);
					printf("rb\n");
				}
			}
			else if (ft_lstlast(a)->index != 1)
			{
				a = rotate(a);
				printf("ra\n");
			}
			argc--;
		}
		if (a)
		{
			argc = ft_lstlast(a)->index;
		}
		start = start - offset;
		end = end + offset;
	}
	while (*b)
	{
		index = get_max(*b);
		middle = ft_lstlast(*b)->index / 2;
		if (index == 1)
		{
			*b = push(*b, &a);
			printf("pa\n");
		}
		else if (a && b[0]->number > ft_lstlast(a)->number)
		{
			*b = push(*b, &a);
			printf("pa\n");
			if (ft_lstlast(a)->index != 1)
			{
				a = rotate(a);
				printf("ra\n");
			}
		}
		else if (ft_lstlast(b[0])->index != 1)
		{
			if (index <= middle)
			{
				*b = rotate(*b);
				printf("rb\n");
			}
			else
			{
				*b = reverse_rotate(*b);
				printf("rrb\n");
			}
		}
	}
	return (a);
}
