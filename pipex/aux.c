/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:24:51 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/10 15:04:06 by mvicente         ###   ########.fr       */
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
		write(2, "command not found\n", 18);
		exit(127);
	}
	else if (status == 1)
		write(2, "pipex: input: No such file or directory\n", 40);
	else if (status == 2)
		write(2, "command not found\n", 18);
	exit(1);
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*aux;

	i = 0;
	while (envp[i])
	{
		aux = ft_strnstr(envp[i], "PATH");
		if (aux)
			paths = ft_split(aux, ':');
		i++;
	}
	return (paths);
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
	free(path1[i]);
	free(path1);
}
