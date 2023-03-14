/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:24:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/14 11:14:27 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error(int status)
{
	if (status == 1)
		write(2, "No such file or directory\n", 26);
	else if (status == 10)
		write(2, "Error\n", 6);
}

void	error_function(t_list *lst, char *command, int **fd)
{
	get_com(lst);
	perror(command);
	free_pipes(fd, get_com(lst));
	free_lst(lst);
	exit(127);
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
	t_list	*ptr;

	while (lst)
	{
		ptr = lst->next;
		free(lst->path);
		free_double(lst->param);
		free(lst);
		lst = ptr;
	}
	free(lst);
}
