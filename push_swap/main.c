/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:43 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/30 16:00:46 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		error();
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
			error();
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

void	ft_lstiter(int argc, t_list *lst, t_list *lst_b)
{
	while (lst)
	{
		printf("a index %d, number %d\n", lst->index, lst->number);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	printf("\n");
	while (lst_b)
	{
		printf("b index %d, number %d\n", lst_b->index, lst_b->number);
		if (!lst_b->next)
			break ;
		lst_b = lst_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	validate_arguments(argc, argv);
	printf("check 1\n");
	check_arguments(argc, argv, &a);
	printf("check 2\n");
	a = sorting(a, &b, argc - 1);
	printf("check 3\n");
	ft_lstiter(argc, a, b);
	printf("check 4\n");
	free_lists(a, b);
}
