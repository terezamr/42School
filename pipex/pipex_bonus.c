/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:22:29 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/14 10:30:16 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_dups(int fin, int fout, int fd_close)
{
	dup2(fin, STDIN_FILENO);
	dup2(fout, STDOUT_FILENO);
	if (fd_close)
		close(fd_close);
}

void	command_bonus(int **fd, t_list *lst, int i, char **envp)
{
	t_list	*node;
	int		f;

	node = get_node(lst, i);
	if (node->inputf)
	{
		close(fd[i][0]);
		f = open_f(node, 0);
		do_dups(f, fd[i][1], f);
	}
	else if (node->outputf)
	{
		close(fd[i - 1][1]);
		f = open_f(node, 1);
		do_dups(fd[i - 1][0], f, fd[i - 1][0]);
		close (f);
	}
	else
	{
		close(fd[i][0]);
		close(fd[i - 1][1]);
		do_dups(fd[i - 1][0], fd[i][1], 0);
	}
	execve(node->path, node->param, envp);
	error_function(lst, node->param[0], fd);
}

void	do_fork(t_list *lst, int **id, int i, char **envp)
{
	int	pa;

	pa = fork();
	if (pa == -1)
	{
		error(10);
		return ;
	}
	else if (pa == 0)
		command_bonus(id, lst, i, envp);
}

void	pipex_bonus(t_list *lst, int com, char **envp)
{
	int	i;
	int	f;
	int	**id;

	i = 0;
	f = 3;
	id = create_pipes(com);
	while (i < com)
	{
		if (i != com - 1)
			pipe(id[i]);
		do_fork(lst, id, i, envp);
		if (i != com - 1)
			close(id[i][1]);
		i++;
	}
	waitpid(-1, 0, 0);
	free_pipes(id, com);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		command_number;
	t_list	*lst;
	int		i;

	i = 0;
	if (argc < 5)
		error(127);
	lst = 0;
	command_number = argc - 3;
	check_files(argv[1]);
	paths = get_paths(envp);
	lst = create_list_bonus(argv, command_number, lst, paths);
	free_double(paths);
	if (lst)
		pipex_bonus(lst, command_number, envp);
	free_lst(lst);
	exit(0);
}
