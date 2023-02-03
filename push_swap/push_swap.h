/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:22 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/20 15:57:22 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_list
{
	int				index;
	int				number;
	int				position;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int new_number, int i);
void	free_lists(t_list *a, t_list *b);
void	ft_lstiter(t_list *lst, t_list *lst_b);

int		ft_atoi(const char *nptr);
void	error(void);

t_list	*swap(t_list *stack, char p);
t_list	*rotate(t_list *stack, char p);
t_list	*reverse_rotate(t_list *stack, char p);
t_list	*push(t_list *stack_1, t_list **stack_2);

t_list	*go_back(t_list *stack);
t_list	*sorting(t_list *a, t_list **b, int argc);
void	check_char(const char *nptr);
int		check_sort(t_list *lst);

int		get_max(t_list *stack, int *max);
int		get_min(t_list *stack);
t_list	*sort_two(t_list *a);
t_list	*sort_three(t_list *a);
t_list	*sort_five(t_list *a, t_list **b, int argc);

#endif