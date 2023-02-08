/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:48:42 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/08 14:01:55 by mvicente         ###   ########.fr       */
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

int	min_zero_position(t_list *stack, int aux)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack->number <= aux && stack->position == 0)
		{
			aux = stack->number;
			index = stack->index;
		}
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (index);
}

int	change_index(t_list **stack, int count, int i)
{
	while (*stack)
	{
		if (i == -1)
			(*stack)->index--;
		else if (i == 1)
			(*stack)->index++;
		if (!(*stack)->next)
			break ;
		(*stack) = (*stack)->next;
		count++;
	}
	return (count);
}
