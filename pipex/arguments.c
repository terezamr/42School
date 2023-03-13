/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:05:04 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/13 16:10:20 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	c;

	a = (char *)src;
	b = (char *)dest;
	c = 0;
	if (!dest && !src)
		return (NULL);
	while (c != n)
	{
		b[c] = a[c];
		c++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s, size + 1);
	return (ptr);
}

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
	return (ft_strdup(command));
}

char	**get_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*aux;

	i = 0;
	paths = 0;
	while (envp[i])
	{
		aux = ft_strnstr(envp[i], "PATH");
		if (aux)
			paths = ft_split(aux, ':');
		i++;
	}
	return (paths);
}

void	check_files(char *str)
{
	int		f_in;
	char	*path;

	path = ft_strdup(str);
	f_in = open(path, O_RDONLY, 0444);
	if (f_in == -1)
	{
		free(path);
		error(1);
		exit(127);
	}
	free(path);
	close(f_in);
}
