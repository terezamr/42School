/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:43 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/03 14:55:11 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc <= 2)
		exit(0);
	while (i < argc)
	{
		check_char(argv[i]);
		i++;
	}
}

void	compare_arg(t_list *new, t_list **stack_a)
{
	while (stack_a[0])
	{
		if (new->number == stack_a[0]->number)
		{
			free_lists(*stack_a, 0);
			free(new);
			error();
		}
		if (!stack_a[0]->next)
			break ;
		stack_a[0] = stack_a[0]->next;
	}
	while (stack_a[0])
	{
		if (!stack_a[0]->prev)
			break ;
		stack_a[0] = stack_a[0]->prev;
	}
}

void	check_arguments(int argc, char **argv, t_list **stack_a)
{
	int		i;
	t_list	*new;

	i = 1;
	new = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]), i);
		compare_arg(new, stack_a);
		ft_lstadd_back(stack_a, new);
		i++;
	}
}

void	get_positions(t_list *a, int size)
{
	t_list	*aux;
	int		number;
	int		index;
	int		count;

	aux = a;
	count = 1;
	while (count <= size)
	{
		aux = a;
		while (aux)
		{
			if (aux->position == 0)
			{
				number = aux->number;
				break ;
			}
			if (!aux->next)
				break ;
			aux = aux->next;
		}
		index = aux->index;
		while (aux)
		{
			if (!aux->next)
				break ;
			aux = aux->next;
			if (aux->number < number && aux->position == 0)
			{
				number = aux->number;
				index = aux->index;
			}
		}
		aux = a;
		while (aux->index != index)
			aux = aux->next;
		aux->position = count;
		count++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	validate_arguments(argc, argv);
	check_arguments(argc, argv, &a);
	if (check_sort(a) == 1)
	{
		free_lists(a, b);
		exit(0);
	}
	get_positions(a, argc - 1);
	a = sorting(a, &b, argc - 1);
	free_lists(a, b);
}
