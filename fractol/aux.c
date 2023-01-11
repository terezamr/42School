/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:12:45 by mvicente          #+#    #+#             */
/*   Updated: 2023/01/11 15:59:57 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*to_lower(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] = string[i] + 32;
		i++;
	}
	return (string);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	s1 = to_lower(s1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
