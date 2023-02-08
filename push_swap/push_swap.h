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

# define MIN_INT -2147483648
# define MAX_INT 2147483647

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int new_number, int i);
void	free_lists(t_list *a, t_list *b);
void	ft_lstiter(t_list *lst, t_list *lst_b);

t_list	*swap(t_list *stack, char p);
t_list	*rotate(t_list *stack, char p);
t_list	*reverse_rotate(t_list *stack, char p);
t_list	*push(t_list *stack_1, t_list **stack_2, char p);

t_list	*atob(t_list *a, t_list **b, int argc, int offset);
t_list	*btoa(t_list *a, t_list **b);
t_list	*sorting(t_list *a, t_list **b, int argc, int n);

t_list	*sort_two(t_list *a);
t_list	*sort_three(t_list *a);
t_list	*rotate_a(t_list *a, t_list *b, int aux);
t_list	*btoa_5(t_list *a, t_list **b, int aux, int *max);
t_list	*sort_five(t_list *a, t_list **b, int argc);

void	error(void);
void	check_char(const char *nptr);
int		ft_atoi(const char *nptr);
t_list	*go_back(t_list *stack);

int		get_max(t_list *stack, int *max);
int		get_min(t_list *stack);
int		min_zero_position(t_list *stack, int aux);
int		change_index(t_list **stack, int count, int i);

int		check_sort(t_list *lst);
t_list	*first_position(t_list *stack, int *number);
void	aux_f(t_list **stack, int count, char p);
void	instructions(char m, char p);

#endif