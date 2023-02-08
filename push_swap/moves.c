/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:27:15 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/08 11:33:58 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions(char m, char p)
{
	if (m == 's')
		write(1, &m, 1);
	else if (m == 'r')
		write(1, &m, 1);
	else if (m == 'd')
		write(1, "rr", 2);
	else if (m == 'p')
		write(1, &m, 1);
	write(1, &p, 1);
	write(1, "\n", 1);
}

t_list	*swap(t_list *stack, char p)
{
	int	a;

	a = stack->number;
	stack->number = stack->next->number;
	stack->next->number = a;
	stack->index = 1;
	stack->next->index = 2;
	instructions('s', p);
	return (stack);
}

t_list	*rotate(t_list *stack, char p)
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
	instructions('r', p);
	return (go_back(stack));
}

t_list	*reverse_rotate(t_list *stack, char p)
{
	t_list	*aux;
	int		count;

	aux = stack;
	count = 0;
	count = change_index(&stack, count, 1);
	stack->prev->next = NULL;
	stack->prev = NULL;
	stack->next = aux;
	aux->prev = stack;
	stack->index = 1;
	instructions('d', p);
	return (stack);
}

t_list	*push(t_list *stack_1, t_list **stack_2, char p)
{
	t_list	*aux;
	int		count;

	count = 0;
	if (!stack_1->next)
	{
		ft_lstadd_front(stack_2, stack_1);
		*stack_2 = (*stack_2)->next;
		aux_f(stack_2, count, p);
		stack_1 = NULL;
		return (stack_1);
	}
	aux = stack_1->next;
	ft_lstadd_front(stack_2, stack_1);
	stack_1 = aux;
	stack_1->prev = NULL;
	count = change_index(&stack_1, count, -1);
	if (!(*stack_2)->next)
	{
		instructions('p', p);
		return (go_back(stack_1));
	}
	*stack_2 = (*stack_2)->next;
	aux_f(stack_2, count, p);
	return (go_back(stack_1));
}
