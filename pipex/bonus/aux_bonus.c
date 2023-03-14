/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:56:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/14 11:10:39 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list	*get_node(t_list *lst, int i)
{
	int		f;
	t_list	*node;

	f = 0;
	node = lst;
	while (f < i)
	{
		node = node->next;
		f++;
	}
	return (node);
}

int	get_com(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	open_f(t_list *node, int flag)
{
	int		f;

	f = -1;
	if (flag == 0)
		f = open(node->inputf, O_RDONLY, 0444);
	else if (flag == 1)
		f = open(node->outputf, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (f == -1)
	{
		error(1);
		exit(127);
	}
	return (f);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
