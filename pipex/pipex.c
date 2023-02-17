/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/17 20:35:16 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command1(int *fd, char **right_path, char **param, char **envp)
{
	int		f;

	f = open(right_path[2], O_RDONLY, 0444);
	if (f == -1)
		error(1);
	dup2(f, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execve(right_path[0], param, envp);
	perror("pipex");
}

void	command2(int *fd, char **right_path, char **param, char **envp)
{
	int	f;

	f = open(right_path[3], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (f == -1)
		error(1);
	dup2(fd[0], STDIN_FILENO);
	dup2(f, STDOUT_FILENO);
	close(fd[1]);
	execve(right_path[1], param, envp);
	perror("pipex");
}

void	pipex(char **param1, char **param2, char **right_path, char **envp)
{
	char	*commands[2];
	int		p1;
	int		p2;
	int		fd[2];
	int		status;

	commands[0] = param1[0];
	commands[1] = param2[0];
	pipe(fd);
	p1 = fork();
	if (p1 == -1)
		error(1);
	else if (p1 == 0)
		command1(fd, right_path, param1, envp);
	p2 = fork();
	if (p2 == -1)
		error(1);
	else if (p2 == 0)
		command2(fd, right_path, param2, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(p1, &status, 0);
	waitpid(p2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*commands[2];
	char	**parameters1;
	char	**parameters2;
	char	**paths;
	char	*right_path[4];

	if (argc != 5)
		error(1);
	paths = NULL;
	parameters1 = ft_split(argv[2], ' ');
	parameters2 = ft_split(argv[3], ' ');
	paths = get_paths(envp);
	get_commands(parameters1, parameters2, commands);
	get_rightp(right_path, paths, commands, argv);
	pipex(parameters1, parameters2, right_path, envp);
	free_double(parameters1, parameters2, paths);
	if (!right_path[1])
	{
		free_path(right_path);
		exit(127);
	}
	free_path(right_path);
	exit(0);
}
