/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:43 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/24 14:03:18 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(int argc, char **argv, t_list *stack_a)
{
	int		i;
	t_list	*new;

	i = 1;
	new = NULL;
	if (argc < 2)
		error();
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]), i);
		ft_lstadd_back(&stack_a, new);
		i++;
	}
}

void	ft_lstiter(int argc, t_list *lst)
{
	t_list	*a;

	a = NULL;
	lst = lst->next;
	while (lst && lst->index != argc)
	{
		printf("lst index %d\n", lst->index);
		printf("number %d\n", lst->number);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	a = lst;
	printf("\n");
	while (lst && lst->index != 0)
	{
		printf("lst index %d\n", lst->index);
		printf("number %d\n", lst->number);
		lst = lst->prev;
	}
}

void	sa(t_list *stack_a)
{
	t_list	*b;

	stack_a = stack_a->next;
	//printf("index %d\n", stack_a->index);
//	printf("number %d\n", stack_a->number);
	b = stack_a->next;
	stack_a->prev = b;
	stack_a->next = b->next;
	stack_a->index = 2;
	stack_a = stack_a->prev;
	stack_a->next = stack_a->prev;
	stack_a->prev = NULL;
	stack_a->index = 1;
	//printf("index %d\n", stack_a->index);
//	printf("number %d\n", stack_a->number);
}

int	main(int argc, char **argv)
{
	t_list	stack_a;

	stack_a.next = NULL;
	check_arguments(argc, argv, &stack_a);
	sa(&stack_a);
	ft_lstiter(argc, &stack_a);
}
