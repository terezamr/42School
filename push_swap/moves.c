/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:15 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/27 11:36:54 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*go_back(t_list *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_list	*swap(t_list *stack)
{
	int	a;

	a = stack->number;
	stack->number = stack->next->number;
	stack->next->number = a;
	stack->index = 1;
	stack->next->index = 2;
	return (stack);
}

int	change_index(t_list **stack, int count, int i)
{
	while (stack[0])
	{
		if (i == -1)
			stack[0]->index--;
		else if (i == 1)
			stack[0]->index++;
		if (!stack[0]->next)
			break ;
		stack[0] = stack[0]->next;
		count++;
	}
	return (count);
}

t_list	*rotate(t_list *stack)
{
	t_list	*aux;
	int		count;

	aux = stack;
	count = 1;
	stack = stack->next;
	stack->prev = NULL;
	count = change_index(&stack, count, -1);
	stack->next = aux;
	aux->prev = stack;
	aux->next = NULL;
	count++;
	stack = stack->next;
	stack->index = count;
	return (go_back(stack));
}

t_list	*push_ab(t_list *stack_1, t_list **stack_2)
{
	t_list	*aux;
	int		count;

	aux = stack_1->next;
	ft_lstadd_front(stack_2, stack_1);
	stack_1 = aux;
	stack_1->prev = NULL;
	count = change_index(&stack_1, count, -1);
	if (!stack_2[0]->next)
		return (go_back(stack_1));
	stack_2[0] = stack_2[0]->next;
	count = change_index(stack_2, count, 1);
	*stack_2 = go_back(*stack_2);
	return (go_back(stack_1));
}
