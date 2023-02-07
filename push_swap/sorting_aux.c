/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:23 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/07 17:41:52 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *lst)
{
	int	flag;

	flag = 1;
	while (lst)
	{
		if (!lst->next)
			break ;
		if (lst->next->number < lst->number)
		{
			flag = 0;
			break ;
		}
		lst = lst->next;
	}
	return (flag);
}

t_list	*first_position(t_list *stack, int *number)
{
	int	aux;

	aux = 0;
	while (stack)
	{
		if (stack->position == 0)
		{
			aux = stack->number;
			break ;
		}
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	number = &aux;
	return (stack);
}

void	aux_f(t_list **stack, int count, char p)
{
	count = change_index(stack, count, 1);
	*stack = go_back(*stack);
	instructions('p', p);
}
