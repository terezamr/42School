/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:02:44 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/06 13:41:33 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_two(t_list *a)
{
	if (a->number > a->next->number)
		a = swap(a, 'a');
	return (a);
}

t_list	*sort_three(t_list *a)
{
	int	index;
	int	max;

	max = 0;
	index = get_max(a, &max);
	if (index == 1)
		a = rotate(a, 'a');
	else if (index == 2)
		a = reverse_rotate(a, 'a');
	if (a->number > a->next->number)
		a = swap(a, 'a');
	return (a);
}

t_list	*rotate_a(t_list *a, t_list *b, int aux)
{
	while (a->number < b->number)
	{
		a = rotate(a, 'a');
		aux--;
		if (aux == 0)
			break ;
	}
	return (a);
}

t_list	*btoa_5(t_list *a, t_list **b, int aux, int *max)
{
	while (*b)
	{
		aux = get_max(a, max);
		if (get_min(a) == 1 && b[0]->number > *max)
			b[0] = push(b[0], &a, 'a');
		else if (a->number < b[0]->number)
		{
			a = rotate_a(a, *b, aux);
			b[0] = push(b[0], &a, 'a');
		}
		else if (a->number > b[0]->number && get_min(a) == 1)
			b[0] = push(b[0], &a, 'a');
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
	return (a);
}

t_list	*sort_five(t_list *a, t_list **b, int argc)
{
	int	aux;
	int	max;

	aux = 0;
	if (argc != 3)
	{
		while (ft_lstlast(a)->index != 3)
			a = push(a, &b[0], 'b');
	}
	a = sort_three(a);
	a = btoa_5(a, b, aux, &max);
	while (get_max(a, &max) != argc)
	{
		if (get_max(a, &max) > argc / 2)
			a = reverse_rotate(a, 'a');
		else
			a = rotate(a, 'a');
	}
	return (a);
}
