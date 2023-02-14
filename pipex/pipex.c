/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/14 13:12:36 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **paths, char *command)
{
	int		i;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, command);
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

void	command1(int *fd, char **right_path, char **param, char **envp)
{
	int		f;

	f = open(right_path[3], O_RDONLY);
	if (f == -1)
		error();
	dup2(f, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(right_path[0], param, envp);
}

void	command2(int *fd, char **right_path, char **param, char **envp)
{
	int	f;

	f = open(right_path[4], O_WRONLY | O_TRUNC | O_CREAT);
	if (f == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(f, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(right_path[1], param, envp);
}

void	pipex(char **param1, char **param2, char **right_path, char **envp)
{
	char	*commands[2];
	int		p1;
	int		p2;
	int		p;
	int		fd[2];

	commands[0] = param1[0];
	commands[1] = param2[0];
	pipe(fd);
	p1 = fork();
	if (p1 == -1)
		error();
	else if (p1 == 0)
		command1(fd, right_path, param1, envp);
	p2 = fork();
	if (p2 == -1)
		error();
	else if (p2 == 0)
	{
		wait(NULL);
		command2(fd, right_path, param2, envp);
	}
}



int	main(int argc, char **argv, char **envp)
{
	char	*commands[2];
	char	**parameters1;
	char	**parameters2;
	char	**paths;
	char	*right_path[4];

	if (argc != 5)
		error();
	paths = NULL;
	parameters1 = ft_split(argv[2], ' ');
	parameters2 = ft_split(argv[3], ' ');
	commands[0] = parameters1[0];
	commands[1] = parameters2[0];
	paths = get_paths(envp);
	right_path[0] = check_path(paths, commands[0]);
	right_path[1] = check_path(paths, commands[1]);
	if (!right_path[0] || !right_path[1])
		error();
	right_path[3] = ft_strjoin("./", argv[1]);
	right_path[4] = ft_strjoin("./", argv[4]);
	pipex(parameters1, parameters2, right_path, envp);
}
