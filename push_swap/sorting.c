/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:45:33 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/03 14:54:00 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (get_min(a) == 1 && b[0]->number > max)
		{
			b[0] = push(b[0], &a);
			printf("pa\n");
		}
		else if (a->number < b[0]->number)
		{
			while (a->number < b[0]->number)
			{
				a = rotate(a, 'a');
				aux--;
				if (aux == 0)
					break ;
			}
			b[0] = push(b[0], &a);
			printf("pa\n");
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
				a = reverse_rotate(a, 'a');
				if (get_min(a) == 1)
					break ;
			}
		}
	}
	while (get_max(a, &max) != argc)
	{
		if (get_max(a, &max) > argc / 2)
			a = reverse_rotate(a, 'a');
		else
			a = rotate(a, 'a');
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
	if (argc == 2)
		return (sort_two(a));
	if (argc == 3)
		return (sort_three(a));
	if (argc <= 5)
		return (sort_five(a, &b[0], argc));
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
			if (a->position >= start && a->position <= end)
			{
				a = push(a, &b[0]);
				printf("pb\n");
				if (b[0]->position <= middle && ft_lstlast(b[0])->index != 1)
					*b = rotate(*b, 'b');
			}
			else if (ft_lstlast(a)->index != 1)
				a = rotate(a, 'a');
			argc--;
		}
		if (a)
			argc = ft_lstlast(a)->index;
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
		else if (a && b[0]->position > ft_lstlast(a)->position)
		{
			*b = push(*b, &a);
			printf("pa\n");
			if (ft_lstlast(a)->index != 1)
				a = rotate(a, 'a');
		}
		else if (ft_lstlast(b[0])->index != 1)
		{
			if (index <= middle)
				*b = rotate(*b, 'b');
			else
				*b = reverse_rotate(*b, 'b');
		}
	}
	return (a);
}
