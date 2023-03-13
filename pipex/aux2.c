/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_bonux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:56:26 by mvicente          #+#    #+#             */
/*   Updated: 2023/03/13 16:02:40 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**create_pipes(int com)
{
	int	i;
	int	f;
	int	**id;

	i = 0;
	f = 3;
	id = 0;
	id = malloc(sizeof(int *) * (com - 1));
	if (!id)
		exit(0);
	while (i < com - 1)
	{
		id[i] = malloc(sizeof(int) * 2);
		id[i][0] = f;
		id[i][1] = f + 1;
		f = f + 2;
		i++;
	}
	return (id);
}

void	free_pipes(int **id, int *pa, int com)
{
	int	i;

	i = 0;
	while (i < com - 1)
	{
		free(id[i]);
		i++;
	}
	free(id);
	free(pa);
}
