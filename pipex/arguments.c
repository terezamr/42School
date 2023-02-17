/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:05:04 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/17 20:16:53 by mvicente         ###   ########.fr       */
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

void	get_rightp(char **right_path, char **paths, char **com, char **argv)
{
	right_path[0] = check_path(paths, com[0]);
	right_path[1] = check_path(paths, com[1]);
	if (argv[1][0] != 47 && argv[1][0] != '.')
		right_path[2] = ft_strjoin("./", argv[1]);
	else
		right_path[2] = ft_strjoin("", argv[1]);
	if (argv[4][0] != 47 && argv[4][0] != '.')
		right_path[3] = ft_strjoin("./", argv[4]);
	else
		right_path[3] = ft_strjoin("", argv[4]);
}

void	get_commands(char **param1, char **param2, char **commands)
{
	commands[0] = param1[0];
	commands[1] = param2[0];
}
