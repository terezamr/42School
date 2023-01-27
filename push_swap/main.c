/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:47:43 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/27 12:16:13 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arguments(int argc, char **argv, t_list **stack_a)
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
	check_arguments(argc, argv, &a);
	a = swap(a);
	a = push(a, &b);
	a = push(a, &b);
	a = push(a, &b);
	a = rotate(a);
	b = rotate(b);
	a = reverse_rotate(a);
	b = reverse_rotate(b);
	a = swap(a);
	b = push(b, &a);
	b = push(b, &a);
	b = push(b, &a);
	ft_lstiter(argc, a, b);
	free_lists(a, b);
}
