/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/31 13:45:32 by mvicente         ###   ########.fr       */
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
	int	down;

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
	down = 0;
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
				printf("check\n");
			}
			else if (ft_lstlast(a)->index != 1)
			{
				a = rotate(a);
				printf("ra\n");
			}
			printf("argc i%d\n", argc);
			argc--;
		}
		printf("check f 1\n");
		if (a)
		{
			printf("check a\n");
			argc = ft_lstlast(a)->index;
		}
		printf("check f 2\n");
		printf("argc f 3: %d\n", argc);
		start = start - offset;
		end = end + offset;
	}
	printf("check f 4\n");
	while (*b)
	{
		printf("check b\n");
		index = get_max(*b);
		printf("index: %d\n", index);
		middle = ft_lstlast(*b)->index / 2;
		printf("middle: %d\n", middle);
		printf("adeus b\n");
		//printf("b %d %d\n", b[0]->index, b[0]->number);
		//printf("index max %d\n", index);
		//printf("middle %d\n", middle);
		if (index == 1)
		{
			*b = push(*b, &a);
			printf("pa\n");
			down = down + 1;
		}
		else if (a && b[0]->number > ft_lstlast(a)->number)
		{
			printf("check second\n");
			*b = push(*b, &a);
			down = down + 1;
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
