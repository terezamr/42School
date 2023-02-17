/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/17 19:12:11 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **paths, char *command)
{
	int		i;
	char	*path1;
	char	*path2;

	i = 0;
	while (paths[i])
	{
		path1 = ft_strjoin(paths[i], "/");
		path2 = ft_strjoin(path1, command);
		free(path1);
		if (access(path2, X_OK) == 0)
			return (path2);
		free(path2);
		i++;
	}
	return (NULL);
}

void	ft_strn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	command1(int *fd, char **right_path, char **param, char **envp)
{
	int		f;

	printf("right path %s\n", right_path[2]);
	f = open(right_path[2], O_RDONLY, 0444);
	if (f == -1)
		error(1);
	dup2(f, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
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
	close(fd[0]);
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
	commands[0] = parameters1[0];
	commands[1] = parameters2[0];
	paths = get_paths(envp);
	right_path[0] = check_path(paths, commands[0]);
	right_path[1] = check_path(paths, commands[1]);
	if (argv[1][0] != 47 && argv[1][0] != '.')
		right_path[2] = ft_strjoin("./", argv[1]);
	else
		right_path[2] = ft_strjoin("", argv[1]);
	if (argv[4][0] != 47 && argv[4][0] != '.')
		right_path[3] = ft_strjoin("./", argv[4]);
	else
		right_path[3] = ft_strjoin("", argv[4]);
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
