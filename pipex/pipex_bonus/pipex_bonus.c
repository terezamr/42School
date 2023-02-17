/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:08:06 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/17 20:41:30 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len = len + 1;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr || !s1 || !s2)
		return (0);
	while (s1[a] != '\0')
	{
		ptr[a] = s1[a];
		a++;
	}
	while (s2[b] != '\0')
	{
		ptr[a] = s2[b];
		a++;
		b++;
	}
	ptr[a] = '\0';
	return (ptr);
}

int	main(int argc, char **argv, char **envp)
{
	char	**parameters;
	int		command_number;
	int		i;

	i = 0;
	if (argc <= 5)
		error(1);
	command_number = argc - 3;
	printf("cn %d\n", command_number);
	parameters = malloc(sizeof(char *))
	while (i < command_number)
	{
		printf("argv %s\n",  ft_strjoin("", argv[i + 2]));
		parameters[i] = ft_strjoin("", argv[i + 2]);
		printf("param %s\n", parameters[i]);
		i++;
	}
	printf("check\n");
	while (parameters[i])
	{
		printf("param %s\n", parameters[i]);
		i++;
	}
	//paths = get_paths(envp);
	
	// get_commands(parameters1, parameters2, commands);
	// get_rightp(right_path, paths, commands, argv);
	// pipex(parameters1, parameters2, right_path, envp);
	// free_double(parameters1, parameters2, paths);
	// if (!right_path[1])
	// {
	// 	free_path(right_path);
	// 	exit(127);
	// }
	// free_path(right_path);
	exit(0);
}
