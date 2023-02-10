/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 18:06:19 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char **paths, char *command)
{
	int		i;
	char	*aux;

	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		aux = ft_strjoin(aux, command);
		if (access(aux, X_OK) == 0)
			return (aux);
		i++;
	}
	return (NULL);
}

void	command1(int *fds, char *right_path, char **param, char **envp)
{
	int	f;

	f = open("/sgoinfre/goinfre/Perso/mvicente/42/pipex/inputf.txt", R_OK);
	dup2(f, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	execve(right_path, param, envp);
}

void	command2(int *fds, char *right_path, char **param, char **envp)
{
	int	f;

	f = open("/sgoinfre/goinfre/Perso/mvicente/42/pipex/outputf.txt", R_OK);
	dup2(fds[0], STDIN_FILENO);
	dup2(f, STDOUT_FILENO);
	execve(right_path, param, envp);
}

void	pipex(char **param1, char **param2, char **right_path, char **envp)
{
	char	*commands[2];
	int		p1;
	int		p2;
	int		p;
	int		fds[2];

	commands[0] = param1[0];
	commands[1] = param2[0];
	printf("right path 1 %s\n", right_path[0]);
	printf("right path 2 %s\n", right_path[1]);
	printf("param 1 %s\n", param1[0]);
	printf("param 2 %s\n", param2[0]);
	pipe(fds);
	p1 = fork();
	if (p1 == 0)
		command1(fds, right_path[0], param1, envp);
	p2 = fork();
	if (p2 == 0)
		command1(fds, right_path[1], param2, envp);
}

int	main(int argc, char **argv, char **envp)
{
	char	*commands[2];
	char	**parameters1;
	char	**parameters2;
	char	**paths;
	char	*right_path[2];

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
	pipex(parameters1, parameters2, right_path, envp);
}
