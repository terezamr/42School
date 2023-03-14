/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/14 11:17:13 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_dups(int fin, int fout, int fd_close)
{
	dup2(fin, STDIN_FILENO);
	dup2(fout, STDOUT_FILENO);
	close(fd_close);
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

void	command(int *fd, t_list *lst, char **envp, int i)
{
	t_list	*node;
	int		f_in;
	int		f_out;

	node = lst;
	if (i == 0)
	{
		if (!node->inputf)
			exit (0);
		f_in = open_f(node, 0);
		do_dups(f_in, fd[1], fd[0]);
		close(f_in);
	}
	else
	{
		node = lst->next;
		f_out = open_f(node, 1);
		do_dups(fd[0], f_out, fd[1]);
		close (f_out);
	}
	execve(node->path, node->param, envp);
	perror(node->param[0]);
	free_lst(lst);
	exit(127);
}

void	pipex(t_list *lst, char **envp)
{
	int		p1;
	int		p2;
	int		fd[2];

	pipe(fd);
	p1 = fork();
	if (p1 == -1)
	{
		error(10);
		return ;
	}
	else if (p1 == 0)
		command(fd, lst, envp, 0);
	p2 = fork();
	if (p2 == -1)
	{
		error(10);
		return ;
	}
	else if (p2 == 0)
		command(fd, lst, envp, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, NULL, WNOHANG);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	t_list	*lst;
	int		command_number;

	if (argc != 5)
	{
		error(10);
		exit (127);
	}
	paths = 0;
	lst = 0;
	command_number = 2;
	check_files(argv[1]);
	paths = get_paths(envp);
	lst = create_list(argv, command_number, lst, paths);
	free_double(paths);
	if (lst)
		pipex(lst, envp);
	free_lst(lst);
	exit(0);
}
