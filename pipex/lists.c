/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:37:07 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/08 13:55:45 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

t_list	*ft_lstnew(char **str, char **paths, int i, int com)
{
	t_list	*new;
	char	*word;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->command = ft_split(str[i + 2], ' ')[0];
	new->param = ft_split(str[i + 2], ' ');
	new->path = check_path(paths, new->command);
	if (i == 0)
	{
		if (str[1][0] != 47 && str[1][0] != '.')
			new->inputf = ft_strjoin("./", str[1]);
		else
			new->inputf = ft_strjoin("", str[1]);
	}
	else
		new->inputf = NULL;
	if (i == com - 1)
	{
		if (str[i + 3][0] != 47 && str[i + 3][0] != '.')
			new->outputf = ft_strjoin("./", str[i + 3]);
		else
			new->outputf = ft_strjoin("", str[i + 3]);
	}
	else
		new->outputf = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*aux;

	aux = NULL;
	if (!new)
		return ;
	else if (lst == NULL)
		lst = new;
	else
	{
		aux = ft_lstlast(lst);
		aux->next = new;
		//new->prev = aux;
	}
}

// t_list	*go_back(t_list *stack)
// {
// 	while (stack->prev)
// 		stack = stack->prev;
// 	return (stack);
// }
