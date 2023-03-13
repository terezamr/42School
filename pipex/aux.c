/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:24:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/13 16:12:53 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_strn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	error(int status)
{
	if (status == 127)
	{
		write(2, "Command not found\n", 18);
		exit(127);
	}
	else if (status == 1)
		write(2, "No such file or directory\n", 26);
	else if (status == 2)
		write(2, "command not found\n", 18);
	else if (status == 10)
		write(2, "Error\n", 6);
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

void	free_double(char **path1)
{
	int	i;

	i = 0;
	while (path1[i])
	{
		free(path1[i]);
		i++;
	}
	if (path1)
		free(path1);
}

void	free_lst(t_list *lst)
{
	int		i;
	t_list	*ptr;

	while (lst)
	{
		i = 0;
		ptr = lst->next;
		free(lst->path);
		free_double(lst->param);
		free(lst);
		lst = ptr;
	}
	free(lst);
}
