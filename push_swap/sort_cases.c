/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:02:44 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/03 12:56:08 by mvicente         ###   ########.fr       */
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
