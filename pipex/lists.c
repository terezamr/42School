/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:37:07 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/09 13:15:09 by mvicente         ###   ########.fr       */
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
	char	**aux;
	int		f;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	aux = ft_split(str[i + 2], ' ');
	new->command = aux[0];
	f = 1;
	while (aux[f])
	{
		free(aux[f]);
		f++;
	}
	free(aux);
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
		new->inputf = 0;
	if (i == com - 1)
	{
		if (str[i + 3][0] != 47 && str[i + 3][0] != '.')
			new->outputf = ft_strjoin("./", str[i + 3]);
		else
			new->outputf = ft_strjoin("", str[i + 3]);
	}
	else
		new->outputf = 0;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	else if (!lst)
		lst = new;
	else
	{
		aux = ft_lstlast(lst);
		aux->next = new;
	}
}

t_list	*create_list(char **argv, int commands, t_list *lst, char **paths)
{
	t_list	*aux;
	int		i;

	i = 0;
	lst = ft_lstnew(argv, paths, i, commands);
	i++;
	while (i < commands)
	{
		aux = ft_lstnew(argv, paths, i, commands);
		ft_lstadd_back(lst, aux);
		i++;
	}
	return (lst);
}

void	free_lst(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	while (lst)
	{
		ptr = lst->next;
		free(lst->command);
		free(lst->path);
		if (lst->inputf)
			free(lst->inputf);
		if (lst->outputf)
			free(lst->outputf);
		while (lst->param[i])
		{
			free(lst->param[i]);
			i++;
		}
		free(lst);
		lst = ptr;
	}
}
