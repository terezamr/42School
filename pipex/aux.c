/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:06:27 by mvicente          #+#    #+#             */
/*   Updated: 2023/02/10 18:06:48 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	write(1, "Error\n", 6);
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