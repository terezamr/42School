/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:37 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack, int *max)
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
	*max = number;
	return (index);
}

int	get_min(t_list *stack)
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
		if (stack->number < number)
		{
			index = stack->index;
			number = stack->number;
		}
	}
	return (index);
}

t_list	*sort_three(t_list *a)
{
	int	index;
	int	max;

	max = 0;
	index = get_max(a, &max);
	if (index == 1)
	{
		a = rotate(a);
		printf("ra\n");
	}
	else if (index == 2)
	{
		a = reverse_rotate(a);
		printf("rra\n");
	}
	if (a->number > a->next->number)
	{
		a = swap(a);
		printf("sa\n");
	}
	return (a);
}

t_list	*sort_five(t_list *a, t_list **b, int argc)
{
	int	aux;
	int	max;

	if (argc != 3)
	{
		while (ft_lstlast(a)->index != 3)
		{
			a = push(a, &b[0]);
			printf("pb\n");
		}
	}
	a = sort_three(a);
	while (*b)
	{
		aux = get_max(a, &max);
		//printf("min a %d, max %d\n", get_min(a), max);
		if (get_min(a) == 1 && b[0]->number > max)
		{
			b[0] = push(b[0], &a);
			printf("pa\n");
		}
		else if (a->number < b[0]->number)
		{
			// if (b[0]->number > max)
			// {
			// 	b[0] = push(b[0], &a);
			// 	printf("pa\n");
			// }
			// else
			// {
			while (a->number < b[0]->number)
			{
				a = rotate(a);
				printf("ra\n");
				aux--;
				if (aux == 0)
					break ;
			}
			b[0] = push(b[0], &a);
			printf("pa\n");
			// }
		}
		else if (a->number > b[0]->number && get_min(a) == 1)
		{
			b[0] = push(b[0], &a);
			printf("pa\n");
		}
		else
		{
			while (a->number > b[0]->number)
			{
				a = reverse_rotate(a);
				printf("rra\n");
				if (get_min(a) == 1)
					break ;
			}
		}
	}
	while (get_max(a, &max) != argc)
	{
		if (get_max(a, &max) > argc / 2)
		{
			a = reverse_rotate(a);
			printf("rra\n");
		}
		else
		{
			a = rotate(a);
			printf("ra\n");
		}
	}
	return (a);
}

t_list	*sorting(t_list *a, t_list **b, int argc)
{
	int	n;
	int	middle;
	int	offset;
	int	start;
	int	end;
	int	index;
	int max;

	max = 0;
	if (argc == 3)
		return (sort_three(a));
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
	if (argc <= 5)
		return (sort_five(a, &b[0], argc));
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
		index = get_max(*b, &max);
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
