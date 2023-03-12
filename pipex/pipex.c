/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/12 16:02:51 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_dups(int fin, int fout, int fd_close)
{
	dup2(fin, STDIN_FILENO);
	(void)fout;
	//dup2(fout, STDOUT_FILENO);
	close(fd_close);
}

void	command(int *fd, t_list *lst, char **envp, int i)
{
	t_list	*node;
	int		f_in;
	int		f_out;

	if (i == 0)
	{
		node = lst;
		f_in = open(node->inputf, O_RDONLY, 0444);
		if (f_in == -1)
		{
			error(10);
			exit(0);
		}
		do_dups(f_in, fd[1], fd[0]);
		close(f_in);
	}
	else
	{
		node = lst->next;
		printf("check wc \n");	
		f_out = open(node->outputf, O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (f_out == -1)
		{
			error(10);
			return ;
		}
		do_dups(fd[0], f_out, fd[1]);
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

	pipe(fd);
	p1 = fork();
	if (p1 == -1)
	{
		printf("check 1\n");
		error(10);
		return ;
	}
	else if (p1 == 0)
		command(fd, lst, envp, 0);
	p2 = fork();
	if (p2 == -1)
	{
		printf("check 2\n");
		error(10);
		return ;
	}
	else if (p2 == 0)
		command(fd, lst, envp, 1);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, NULL, WNOHANG);
	//waitpid(p2, NULL, 0);
}

void	check_files(char **argv, int com)
{
	int		f_in;
	int		f_out;
	char	*path;

	path = ft_strjoin("./", argv[1]);
	f_in = open(path, O_RDONLY, 0444);
	if (f_in == -1)
	{
		free(path);
		error(1);
		exit(0);
	}
	free(path);
	path = ft_strjoin("./", argv[com + 2]);
	f_out = open(path, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (f_out == -1)
	{
		free(path);
		close(f_in);
		error(1);
		exit(0);
	}
	close(f_in);
	close(f_out);
	free(path);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	t_list	*lst;
	int		command_number;

	if (argc != 5)
		exit (0);
	paths = 0;
	lst = 0;
	command_number = 2;
	check_files(argv, command_number);
	paths = get_paths(envp);
	lst = create_list(argv, command_number, lst, paths);
	if (lst)
		pipex(lst, envp);
	free_double(paths);
	free_lst(lst);
	exit(0);
}
