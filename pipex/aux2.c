/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:56:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/14 10:31:43 by mvicente         ###   ########.fr       */
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

void	error_function(t_list *lst, char *command, int **fd)
{
	get_com(lst);
	perror(command);
	free_pipes(fd, get_com(lst));
	free_lst(lst);
	exit(127);
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
		error(10);
		exit(127);
	}
	return (f);
}
