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
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int new_number, int i);
int		ft_atoi(const char *nptr);
void	error(void);
t_list	*swap(t_list *stack);
t_list	*rotate(t_list *stack);
t_list	*reverse_rotate(t_list *stack);
t_list	*push(t_list *stack_1, t_list **stack_2);
void	free_lists(t_list *a, t_list *b);
t_list	*go_back(t_list *stack);

#endif