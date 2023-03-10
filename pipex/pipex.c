/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 15:04:01 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command(int *fd, t_list *lst, char **envp, int i)
{
	t_list	*node;
	int		f_in;
	int		f_out;

	if (i == 0)
	{
		node = lst;
		close(fd[0]);
		f_in = open(node->inputf, O_RDONLY, 0444);
		if (f_in == -1)
			error(1);
		dup2(f_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(f_in);
	}
	else
	{
		node = lst->next;
		close(fd[1]);
		f_out = open(node->outputf, O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (f_out == -1)
			error(1);
		dup2(fd[0], STDIN_FILENO);
		dup2(f_out, STDOUT_FILENO);
		close (f_out);
	}
	execve(node->path, node->param, envp);
	perror("pipex");
}


void	pipex(t_list *lst, char **envp)
{
	int		p1;
	int		p2;
	int		fd[2];
	int		status;

	pipe(fd);
	p1 = fork();
	if (p1 == -1)
		error(1);
	else if (p1 == 0)
		command(fd, lst, envp, 0);
	p2 = fork();
	if (p2 == -1)
		error(1);
	else if (p2 == 0)
		command(fd, lst, envp, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(p1, &status, 0);
	waitpid(p2, &status, 0);
	//waitpid(-1, 0, 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	t_list	*lst;
	int		command_number;

	if (argc != 5)
		error(1);
	paths = 0;
	lst = 0;
	paths = get_paths(envp);
	command_number = 2;
	lst = create_list(argv, command_number, lst, paths);
	pipex(lst, envp);
	free_double(paths);
	free_lst(lst);
	exit(0);
}
